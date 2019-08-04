#pragma once

/* Binary Tree */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "Queue.h"

typedef int TDataType;

typedef struct BTreeNode {
	TDataType	data;
	struct BTreeNode *left;
	struct BTreeNode *right;
}	BTreeNode;


BTreeNode * CreateNode(int data)
{
	BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
	node->data = data;
	node->left = node->right = NULL;

	return node;
}

// 返回值:
// 1. 创出的树的根结点
// 2. 创建树过程中，使用的字符个数
BTreeNode * CreateTree(int preOrder[], int size, int *pUsedSize)
{
	if (size <= 0) {
		*pUsedSize = 0;
		return NULL;
	}

	int leftUse, rightUse;
	int	rootValue = preOrder[0];
	if (rootValue == -1) {
		*pUsedSize = 1;
		return NULL;
	}

	BTreeNode *root = CreateNode(rootValue);
	
	root->left = CreateTree(preOrder + 1, size - 1, &leftUse);
	root->right = CreateTree(preOrder + 1 + leftUse, size - 1 - leftUse, &rightUse);

	// 向老大汇报实际使用情况
	*pUsedSize = 1 + leftUse + rightUse;

	return root;
}






// 前序/中序/后序遍历
void PreOrder(BTreeNode *root)
{
	if (root == NULL) {
		// root 是一棵空树
		return;
	}

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}














void InOrder(BTreeNode *root)
{
	if (root == NULL) { return; }

	InOrder(root->left);	// 用中序的方式遍历 左子树**
	printf("%d ", root->data);
	InOrder(root->right);	// 用中序的方式遍历 右子树**
}

void PostOrder(BTreeNode *root)
{
	if (root == NULL) { return; }

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

// 求树的结点个数
// 1. 用子问题的方式求解
// 2. 用遍历求解

// 利用后序遍历的方式计数结点个数
int count = 0;
void GetSize2(BTreeNode *root)
{
	if (root == NULL) { return; }

	GetSize2(root->left);
	GetSize2(root->right);
	count++;
}

int GetSize1(BTreeNode *root)
{
	if (root == NULL) {
		return 0;
	}

	int left = GetSize1(root->left);
	int right = GetSize1(root->right);

	return left + right + 1;

	//return GetSize1(root->left) + GetSize2(root->right) + 1;
}

int GetLeafSize(BTreeNode *root)
{
	if (root == NULL) { 
		// 我是空树
		return 0; 
	}
	else {

		if (root->left == NULL && root->right == NULL) {
			// 我是只有一个结点的树
			return 1;
		}
		else {

			// 我不是空树也不是只有一个结点的树
			return GetLeafSize(root->left) + GetLeafSize(root->right);
		}
	}
}


int GetLevelKSize(BTreeNode *root, int k)
{
	assert(k >= 1);

	if (root == NULL) {
		// 空树，任意层都是 0 个
		return 0;
	}

	if (k == 1) {
		// 第一层只有根结点，所以返回 1
		return 1;
	}

	// 我的第 k 层，是我子树的第 k - 1 层
	int left = GetLevelKSize(root->left, k - 1);
	int right = GetLevelKSize(root->right, k - 1);

	return left + right;
}

// 高度/深度
#define MAX(a, b)	((a) > (b) ? (a) : (b))
int GetHeight(BTreeNode *root)
{
	if (root == NULL) {
		return 0;
	}

	// 当子树只有一个结点的时候，可以写，也可以不写
	// 写的话，节省两次函数调用

	return MAX(GetHeight(root->left), GetHeight(root->right)) + 1;
}


// 前提，树里的 data 不重复
// 如果找到了，返回结点地址
// 如果没找到，返回 NULL
// 先匹配根，再左子树，再右子树
BTreeNode * Find(BTreeNode *root, TDataType data)
{
	if (root == NULL) {
		return NULL;	//	(1)
	}

	if (root->data == data) {
		return root;	//	(2)
	}

	BTreeNode *result = Find(root->left, data);
	if (result != NULL) {
		// 左子树找到了
		return result;		//	(3)
	}

	result = Find(root->right, data);
	if (result != NULL) {
		return result;		// (4)
	}
	else {
		return NULL;		// (5)
	}
}


void LevelOrder(BTreeNode *root)
{
	Queue	queue;
	QueueInit(&queue);
	BTreeNode *front;

	if (root == NULL) {
		return;
	}

	QueuePush(&queue, root);	// 放的结点地址，不是结点的 data
	while (!QueueEmpty(&queue)) {
		front = QueueFront(&queue);
		QueuePop(&queue);

		// front 取拉下线，空结点是不要的
		// 先左后右
		if (front->left != NULL) {
			QueuePush(&queue, front->left);
		}

		if (front->right != NULL) {
			QueuePush(&queue, front->right);
		}

		// 层序遍历 front 结点
		printf("%d ", front->data);
	}

	// 销毁队列
}

// 判断一棵树是不是完全二叉树
int IsCompleteTree(BTreeNode *root)
{
	Queue queue;
	BTreeNode *front;
	if (root == NULL) {
		return 1;
	}

	QueuePush(&queue, root);
	while (!QueueEmpty(&queue)) {	// 这个条件肯定不会走到
		front = QueueFront(&queue);
		QueuePop(&queue);
		// 这里和层序遍历的区别：front 是有可能是 NULL
		if (front == NULL) {
			// 如果是完全二叉树，剩下的结点应该全是 NULL
			break;
		}

		QueuePush(&queue, front->left);
		QueuePush(&queue, front->right);
	}

	// 队列剩余结点是否都是 NULL
	// 判定队列为空 QueueFront(&queue) == NULL，这个不是空队列判定	
	while (!QueueEmpty(&queue)) {
		front = QueueFront(&queue);
		QueuePop(&queue);
		if (front != NULL) {
			// TODO: 队列销毁
			return 0;
		}
	}

	// TODO: 队列销毁
	return 1;
}


// 非递归（前序/中序/后序）
#include "Stack.h"
// 栈里保存的是 右子树没有遍历过的结点
void PreOrderLoop(BTreeNode *root)
{
	Stack	stack;
	StackInit(&stack);
	BTreeNode *cur, *top;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)) {
		while (cur != NULL) {
			printf("%d ", cur->data);
			StackPush(&stack, cur);
			cur = cur->left;
		}
		// top 的左子树 和 根已经遍历过了
		top = StackTop(&stack);
		StackPop(&stack);

		// 需要进行 top 是空的判定么?
		cur = top->right;
	}
}

// 栈里保存的是 根 和右子树没有遍历过的结点
void InOrderLoop(BTreeNode *root)
{
	Stack	stack;
	StackInit(&stack);
	BTreeNode *cur, *top;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)) {
		// 遍历左子树
		while (cur != NULL) {
			StackPush(&stack, cur);
			cur = cur->left;
		}
		// top 的 左子树 已经遍历过了
		top = StackTop(&stack);
		StackPop(&stack);
		printf("%d ", top->data);

		// 需要进行 top 是空的判定么?
		// 利用子问题的思想去遍历 top 右子树
		cur = top->right;
	}
}

void PostOrderLoop(BTreeNode *root)
{
	Stack	stack;
	StackInit(&stack);
	// last 上一个被遍历的结点
	BTreeNode *cur, *top, *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)) {
		// 遍历左子树
		while (cur != NULL) {
			StackPush(&stack, cur);
			cur = cur->left;
		}
		// top 的 左子树 已经遍历过了
		top = StackTop(&stack);

		if (top->right == NULL || top->right == last) {
			// 如果右子树被遍历过了
			StackPop(&stack);
			printf("%d ", top->data);

			// 记录这个被遍历的结点
			last = top;
		}
		else {
			// 如果右子树没有被遍历过
			cur = top->right;
		}
	}
}

// 求镜像
void Mirror1(BTreeNode *root)
{
	if (root == NULL) {
		return;
	}

	Mirror1(root->left);
	Mirror1(root->right);

	BTreeNode *t = root->left;
	root->left = root->right;
	root->right = t;
}

void Mirror2(BTreeNode *root)
{
	Stack	stack;
	StackInit(&stack);
	// last 上一个被遍历的结点
	BTreeNode *cur, *top, *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)) {
		// 遍历左子树
		while (cur != NULL) {
			StackPush(&stack, cur);
			cur = cur->left;
		}
		// top 的 左子树 已经遍历过了
		top = StackTop(&stack);

		if (top->right == NULL || top->right == last) {
			// 如果右子树被遍历过了
			StackPop(&stack);

			// 替换掉原来的打印
			BTreeNode *t = top->left;
			top->left = top->right;
			top->right = t;

			// 记录这个被遍历的结点
			last = top;
		}
		else {
			// 如果右子树没有被遍历过
			cur = top->right;
		}
	}
}

void Test()
{
	//int preOrder[] = { 1, 2, -1, -1, 3 };
	int preOrder[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 10 };
	//int preOrder[] = { 1, 2, 4, -1, -1, -1, 3 };
	int size = sizeof(preOrder) / sizeof(int);
	int usedSize;

	BTreeNode *root = CreateTree(preOrder, size, &usedSize);

#if 0
	PreOrder(root); printf("\n");
	InOrder(root); printf("\n");
	PostOrder(root); printf("\n");
	GetSize2(root);	printf("结点个数: %d\n", count);
	printf("结点个数: %d\n", GetSize1(root));
	printf("叶子结点个数: %d\n", GetLeafSize(root));
	printf("第 3 层有 :%d\n", GetLevelKSize(root, 3));
	printf("高度: %d\n", GetHeight(root));

	BTreeNode *r = Find(root, 3);

	LevelOrder(root); printf("\n");
	PreOrderLoop(root); printf("\n");
	InOrderLoop(root); printf("\n");
	PostOrderLoop(root); printf("\n");
#endif

	Mirror2(root);

	printf("成功\n");
}