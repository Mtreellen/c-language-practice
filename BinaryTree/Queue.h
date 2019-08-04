#pragma once

#include <stdlib.h>
#include <assert.h>

struct BTreeNode;

typedef struct BTreeNode * QDataType;

typedef struct QNode {
	QDataType data;
	struct QNode *next;
}	QNode;

typedef struct Queue {
	QNode *front;
	QNode *rear;
}	Queue;

// ��ʼ��/����

// ���루��β���룩/ɾ������ͷɾ����/�鿴��������

void QueueInit(Queue *pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}
void QueueDestroy(Queue *pQueue)
{
	QNode *cur, *next;
	for (cur = pQueue->front; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}
	pQueue->front = pQueue->rear = NULL;
}

static QNode * QCreateNode(QDataType data)
{
	QNode *node = (QNode *)malloc(sizeof(QNode));
	assert(node);
	node->data = data;
	node->next = NULL;

	return node;
}

// ���루β�壩
void QueuePush(Queue *pQueue, QDataType data)
{
	QNode *newNode = QCreateNode(data);	// ��Ҫ��������ռ�

	if (pQueue->front == NULL) {
		pQueue->front = pQueue->rear = newNode;
		return;
	}

	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

// ɾ����ͷɾ��
void QueuePop(Queue *pQueue)
{
	assert(pQueue != NULL);			// ��ַ��Ҫ��Ч
	assert(pQueue->front != NULL);	// ����Ϊ�գ���֧��

	QNode *del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);

	// ������ֻ��һ�����
	if (pQueue->front == NULL) {
		pQueue->rear = NULL;
	}
}

// �鿴��������
QDataType QueueFront(Queue *pQueue)
{
	assert(pQueue != NULL);			// ��ַ��Ҫ��Ч
	assert(pQueue->front != NULL);	// ����Ϊ�գ���֧��

	return pQueue->front->data;
}

// �Ƿ�Ϊ��
int QueueEmpty(const Queue *pQueue)
{
	return pQueue->front == NULL;
}

// �������ݸ���
int QueueSize(const Queue *pQueue)
{
	int size = 0;
	QNode *cur;
	for (cur = pQueue->front; cur != NULL; cur = cur->next) {
		size++;
	}

	return size;
}