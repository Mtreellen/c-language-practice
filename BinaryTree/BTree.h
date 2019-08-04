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

// ����ֵ:
// 1. ���������ĸ����
// 2. �����������У�ʹ�õ��ַ�����
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

	// ���ϴ�㱨ʵ��ʹ�����
	*pUsedSize = 1 + leftUse + rightUse;

	return root;
}






// ǰ��/����/�������
void PreOrder(BTreeNode *root)
{
	if (root == NULL) {
		// root ��һ�ÿ���
		return;
	}

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}














void InOrder(BTreeNode *root)
{
	if (root == NULL) { return; }

	InOrder(root->left);	// ������ķ�ʽ���� ������**
	printf("%d ", root->data);
	InOrder(root->right);	// ������ķ�ʽ���� ������**
}

void PostOrder(BTreeNode *root)
{
	if (root == NULL) { return; }

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}

// �����Ľ�����
// 1. ��������ķ�ʽ���
// 2. �ñ������

// ���ú�������ķ�ʽ����������
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
		// ���ǿ���
		return 0; 
	}
	else {

		if (root->left == NULL && root->right == NULL) {
			// ����ֻ��һ��������
			return 1;
		}
		else {

			// �Ҳ��ǿ���Ҳ����ֻ��һ��������
			return GetLeafSize(root->left) + GetLeafSize(root->right);
		}
	}
}


int GetLevelKSize(BTreeNode *root, int k)
{
	assert(k >= 1);

	if (root == NULL) {
		// ����������㶼�� 0 ��
		return 0;
	}

	if (k == 1) {
		// ��һ��ֻ�и���㣬���Է��� 1
		return 1;
	}

	// �ҵĵ� k �㣬���������ĵ� k - 1 ��
	int left = GetLevelKSize(root->left, k - 1);
	int right = GetLevelKSize(root->right, k - 1);

	return left + right;
}

// �߶�/���
#define MAX(a, b)	((a) > (b) ? (a) : (b))
int GetHeight(BTreeNode *root)
{
	if (root == NULL) {
		return 0;
	}

	// ������ֻ��һ������ʱ�򣬿���д��Ҳ���Բ�д
	// д�Ļ�����ʡ���κ�������

	return MAX(GetHeight(root->left), GetHeight(root->right)) + 1;
}


// ǰ�ᣬ����� data ���ظ�
// ����ҵ��ˣ����ؽ���ַ
// ���û�ҵ������� NULL
// ��ƥ�����������������������
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
		// �������ҵ���
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

	QueuePush(&queue, root);	// �ŵĽ���ַ�����ǽ��� data
	while (!QueueEmpty(&queue)) {
		front = QueueFront(&queue);
		QueuePop(&queue);

		// front ȡ�����ߣ��ս���ǲ�Ҫ��
		// �������
		if (front->left != NULL) {
			QueuePush(&queue, front->left);
		}

		if (front->right != NULL) {
			QueuePush(&queue, front->right);
		}

		// ������� front ���
		printf("%d ", front->data);
	}

	// ���ٶ���
}

// �ж�һ�����ǲ�����ȫ������
int IsCompleteTree(BTreeNode *root)
{
	Queue queue;
	BTreeNode *front;
	if (root == NULL) {
		return 1;
	}

	QueuePush(&queue, root);
	while (!QueueEmpty(&queue)) {	// ��������϶������ߵ�
		front = QueueFront(&queue);
		QueuePop(&queue);
		// ����Ͳ������������front ���п����� NULL
		if (front == NULL) {
			// �������ȫ��������ʣ�µĽ��Ӧ��ȫ�� NULL
			break;
		}

		QueuePush(&queue, front->left);
		QueuePush(&queue, front->right);
	}

	// ����ʣ�����Ƿ��� NULL
	// �ж�����Ϊ�� QueueFront(&queue) == NULL��������ǿն����ж�	
	while (!QueueEmpty(&queue)) {
		front = QueueFront(&queue);
		QueuePop(&queue);
		if (front != NULL) {
			// TODO: ��������
			return 0;
		}
	}

	// TODO: ��������
	return 1;
}


// �ǵݹ飨ǰ��/����/����
#include "Stack.h"
// ջ�ﱣ����� ������û�б������Ľ��
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
		// top �������� �� ���Ѿ���������
		top = StackTop(&stack);
		StackPop(&stack);

		// ��Ҫ���� top �ǿյ��ж�ô?
		cur = top->right;
	}
}

// ջ�ﱣ����� �� ��������û�б������Ľ��
void InOrderLoop(BTreeNode *root)
{
	Stack	stack;
	StackInit(&stack);
	BTreeNode *cur, *top;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)) {
		// ����������
		while (cur != NULL) {
			StackPush(&stack, cur);
			cur = cur->left;
		}
		// top �� ������ �Ѿ���������
		top = StackTop(&stack);
		StackPop(&stack);
		printf("%d ", top->data);

		// ��Ҫ���� top �ǿյ��ж�ô?
		// �����������˼��ȥ���� top ������
		cur = top->right;
	}
}

void PostOrderLoop(BTreeNode *root)
{
	Stack	stack;
	StackInit(&stack);
	// last ��һ���������Ľ��
	BTreeNode *cur, *top, *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)) {
		// ����������
		while (cur != NULL) {
			StackPush(&stack, cur);
			cur = cur->left;
		}
		// top �� ������ �Ѿ���������
		top = StackTop(&stack);

		if (top->right == NULL || top->right == last) {
			// �������������������
			StackPop(&stack);
			printf("%d ", top->data);

			// ��¼����������Ľ��
			last = top;
		}
		else {
			// ���������û�б�������
			cur = top->right;
		}
	}
}

// ����
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
	// last ��һ���������Ľ��
	BTreeNode *cur, *top, *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)) {
		// ����������
		while (cur != NULL) {
			StackPush(&stack, cur);
			cur = cur->left;
		}
		// top �� ������ �Ѿ���������
		top = StackTop(&stack);

		if (top->right == NULL || top->right == last) {
			// �������������������
			StackPop(&stack);

			// �滻��ԭ���Ĵ�ӡ
			BTreeNode *t = top->left;
			top->left = top->right;
			top->right = t;

			// ��¼����������Ľ��
			last = top;
		}
		else {
			// ���������û�б�������
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
	GetSize2(root);	printf("������: %d\n", count);
	printf("������: %d\n", GetSize1(root));
	printf("Ҷ�ӽ�����: %d\n", GetLeafSize(root));
	printf("�� 3 ���� :%d\n", GetLevelKSize(root, 3));
	printf("�߶�: %d\n", GetHeight(root));

	BTreeNode *r = Find(root, 3);

	LevelOrder(root); printf("\n");
	PreOrderLoop(root); printf("\n");
	InOrderLoop(root); printf("\n");
	PostOrderLoop(root); printf("\n");
#endif

	Mirror2(root);

	printf("�ɹ�\n");
}