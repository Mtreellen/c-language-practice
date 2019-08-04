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
	// ��ôȥ�ж���������������
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
			// ����������
			cur = top->right;
			continue;
		}
		

		// ���������
		printf("%d ", top->data);
		StackPop(&stack);

		// ��¼ last �ı仯
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

// ǰ�� node1 �� node2 һ���� root ����
BTreeNode * GetAncestor(BTreeNode *root, BTreeNode *node1, BTreeNode *node2)
{
	// �ж� node1 �� node2 ���ĸ�����
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

	// ������ֻ��һ������ʱ�򣬿���д��Ҳ���Բ�д
	// д�Ļ�����ʡ���κ�������

	return MAX(GetHeight(root->left), GetHeight(root->right)) + 1;
}

int IsBalance(BTreeNode *root)
{
	if (root == NULL) {
		return 1;
	}

	// �ж��������Ƿ�ƽ��
	int leftBalance = IsBalance(root->left);
	if (!leftBalance) {
		// ��������ƽ�⣬û��Ҫ������������һ����ƽ��
		return 0;
	}

	// �ж��������Ƿ�ƽ��
	int rightBalance = IsBalance(root->right);
	if (!rightBalance) {
		// ��������ƽ�⣬û��Ҫ������������һ����ƽ��
		return 0;
	}

	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);

	// �߶Ȳ���� 1
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

	// �ж��������Ƿ�ƽ��
	int leftHeight;
	int leftBalance = IsBalance(root->left, &leftHeight);
	if (!leftBalance) {
		// ��������ƽ�⣬û��Ҫ������������һ����ƽ��
		*pHeight = -1;	// ��ƽ���������߶�û���ã�����ֵ������
		return 0;
	}

	// �ж��������Ƿ�ƽ��
	int rightBalance = IsBalance(root->right);
	if (!rightBalance) {
		// ��������ƽ�⣬û��Ҫ������������һ����ƽ��
		*pHeight = -1;	// ��ƽ���������߶�û���ã�����ֵ������
		return 0;
	}

	// �������������ĸ߶�
	*pHeight = MAX(leftHeight, rightHeight) + 1;

	// �߶Ȳ���� 1
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

// �Ż��� �� �߶ȵĹ���
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