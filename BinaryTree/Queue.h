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

// 初始化/销毁

// 插入（队尾插入）/删除（队头删除）/查看队首数据

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

// 插入（尾插）
void QueuePush(Queue *pQueue, QDataType data)
{
	QNode *newNode = QCreateNode(data);	// 不要忘记申请空间

	if (pQueue->front == NULL) {
		pQueue->front = pQueue->rear = newNode;
		return;
	}

	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

// 删除（头删）
void QueuePop(Queue *pQueue)
{
	assert(pQueue != NULL);			// 地址需要有效
	assert(pQueue->front != NULL);	// 队列为空，不支持

	QNode *del = pQueue->front;
	pQueue->front = pQueue->front->next;
	free(del);

	// 队列中只有一个结点
	if (pQueue->front == NULL) {
		pQueue->rear = NULL;
	}
}

// 查看队首数据
QDataType QueueFront(Queue *pQueue)
{
	assert(pQueue != NULL);			// 地址需要有效
	assert(pQueue->front != NULL);	// 队列为空，不支持

	return pQueue->front->data;
}

// 是否为空
int QueueEmpty(const Queue *pQueue)
{
	return pQueue->front == NULL;
}

// 返回数据个数
int QueueSize(const Queue *pQueue)
{
	int size = 0;
	QNode *cur;
	for (cur = pQueue->front; cur != NULL; cur = cur->next) {
		size++;
	}

	return size;
}