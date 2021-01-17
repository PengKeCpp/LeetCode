#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int QDataType;
typedef struct QueueNode {
	struct QueueNode* _next;
	QDataType _data;
}QueueNode;

typedef struct Queue {
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

//初始化和销毁队列
void QueueInit(Queue *queue);
void QueueDestroy(Queue *queue);

void QueuePush(Queue *queue,QDataType x);
void QueuePop(Queue *queue);

QDataType QueueFront(Queue *queue);
QDataType QueueBack(Queue *queue);

int QueueEmpty(Queue* queue);
int QueueSize(Queue *queue);
