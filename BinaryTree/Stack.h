#pragma once

#include <assert.h>

struct BTreeNode;	// �ṹ������

typedef struct BTreeNode * StackDataType;

#define	MAX_SIZE	(100)

typedef struct Stack {
	StackDataType	array[MAX_SIZE];
	int				top;	// ��ʾ��ǰ����
}	Stack;

// ��ʼ��/����
// ����ֻ�ܴ�ջ����/ɾ��ֻ��ɾ��ջ����/�飨ֻ�ܲ鿴ջ��Ԫ�أ�
// ���� / �Ƿ�� / �Ƿ���
// �� -> ˳����β��
// ɾ -> ˳����βɾ

void StackInit(Stack *pStack)
{
	pStack->top = 0;
}

void StackDestroy(Stack *pStack)
{
	pStack->top = 0;
}

void StackPush(Stack *pStack, StackDataType data)
{
	assert(pStack->top < MAX_SIZE);

	pStack->array[pStack->top++] = data;
}

void StackPop(Stack *pStack)
{
	assert(pStack->top > 0);

	pStack->top--;
}

StackDataType StackTop(const Stack *pStack)
{
	assert(pStack->top > 0);

	return pStack->array[pStack->top - 1];
}

int StackSize(const Stack *pStack)
{
	return pStack->top;
}

int StackFull(const Stack *pStack)
{
	return pStack->top >= MAX_SIZE;
}

int StackEmpty(const Stack *pStack)
{
	return pStack->top <= 0;
}