#pragma once

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

#include "Stack.h"

void PreOrder(BTreeNode *root)
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

		top = StackTop(&stack);
		StackPop(&stack);

		cur = top->right;
	}
}

void InOrder(BTreeNode *root)
{
	Stack	stack;
	StackInit(&stack);

	BTreeNode *cur, *top;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)) {
		while (cur != NULL) {
			StackPush(&stack, cur);
			cur = cur->left;
		}

		top = StackTop(&stack);
		printf("%d ", top->data);
		StackPop(&stack);

		cur = top->right;
	}
}

void PostOrder(BTreeNode *root)
{
	// 怎么去判断右子树遍历过了
	Stack	stack;
	StackInit(&stack);

	BTreeNode *cur, *top;
	BTreeNode *last;
	cur = root;
	last = NULL;

	while (cur != NULL || !StackEmpty(&stack)) {
		while (cur != NULL) {
			StackPush(&stack, cur);
			cur = cur->left;
		}

		top = StackTop(&stack);


		if (top->right != NULL && top->right != last) {
			// 遍历右子树
			cur = top->right;
			continue;
		}
		

		// 遍历根结点
		printf("%d ", top->data);
		StackPop(&stack);

		// 记录 last 的变化
		last = top;
	}
}

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

// 前提 node1 和 node2 一定在 root 树中
BTreeNode * GetAncestor(BTreeNode *root, BTreeNode *node1, BTreeNode *node2)
{
	// 判断 node1 和 node2 在哪个子树
	BTreeNode *node1InLeft = Find(root->left, node1->data);
	BTreeNode *node2InLeft = Find(root->left, node2->data);
	BTreeNode *node1InRight = Find(root->right, node1->data);
	BTreeNode *node2InRight = Find(root->right, node2->data);

	if ((node1InLeft && node2InRight) || (node1InRight && node2InLeft)) {
		return root;
	}

	if (node1InLeft) {
		return GetAncestor(root->left, node1, node2);
	}
	else {
		return GetAncestor(root->right, node1, node2);
	}
}

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

int IsBalance(BTreeNode *root)
{
	if (root == NULL) {
		return 1;
	}

	// 判断左子树是否平衡
	int leftBalance = IsBalance(root->left);
	if (!leftBalance) {
		// 左子树不平衡，没必要继续，整棵树一定不平衡
		return 0;
	}

	// 判断右子树是否平衡
	int rightBalance = IsBalance(root->right);
	if (!rightBalance) {
		// 右子树不平衡，没必要继续，整棵树一定不平衡
		return 0;
	}

	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);

	// 高度差不超过 1
	int diff = leftHeight - rightHeight;
	if (diff >= -1 && diff <= 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int IsBalanceAd(BTreeNode *root, int *pHeight)
{
	if (root == NULL) {
		*pHeight = 0;
		return 1;
	}

	// 判断左子树是否平衡
	int leftHeight;
	int leftBalance = IsBalance(root->left, &leftHeight);
	if (!leftBalance) {
		// 左子树不平衡，没必要继续，整棵树一定不平衡
		*pHeight = -1;	// 不平衡的情况，高度没有用，给的值无意义
		return 0;
	}

	// 判断右子树是否平衡
	int rightBalance = IsBalance(root->right);
	if (!rightBalance) {
		// 右子树不平衡，没必要继续，整棵树一定不平衡
		*pHeight = -1;	// 不平衡的情况，高度没有用，给的值无意义
		return 0;
	}

	// 真正的整棵树的高度
	*pHeight = MAX(leftHeight, rightHeight) + 1;

	// 高度差不超过 1
	int diff = leftHeight - rightHeight;
	if (diff >= -1 && diff <= 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int MAX_THREE(int a, int b, int c)
{
	if (a >= b && a >= c) {
		return a;
	}

	if (b >= a && b >= c) {
		return b;
	}

	return c;
}

// 优化掉 求 高度的过程
int GetLongDistance(BTreeNode *root)
{
	if (root == NULL) {
		return 0;
	}

	int leftLD = GetLongDistance(root->left);
	int rightLD = GetLongDistance(root->right);
	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);
	int rootLD = leftHeight + rightHeight;

	return MAX_THREE(leftLD, rightLD, rootLD);
}

void Test()
{
	//int preOrder[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 10 };
	int preOrder[] = { 1, 2, -1, -1, 3 };
	int size = sizeof(preOrder) / sizeof(int);
	int usedSize;

	BTreeNode *root = CreateTree(preOrder, size, &usedSize);

#if 0
	PreOrder(root); printf("\n");
	InOrder(root); printf("\n");
	PostOrder(root); printf("\n");
#endif

	printf("%d\n", IsBalance(root));
}