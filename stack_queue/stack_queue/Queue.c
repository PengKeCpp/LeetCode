#include"Queue.h"


void QueueInit(Queue* queue) {
	assert(queue);
	queue->_head = queue->_tail = NULL;
}

void QueueDestroy(Queue* queue) {
	assert(queue);
	QueueNode* cur = queue->_head;
	while (cur) {
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	queue->_head = queue->_tail = NULL;
}

void QueuePush(Queue* queue, QDataType x) {
	assert(queue);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL) {
		printf("内存不足！");
		exit(-1);
	}
	newNode->_data = x;
	newNode->_next = NULL;
	if (queue->_head == NULL) {
		queue->_head = queue->_tail = newNode;
	}
	else {
		queue->_tail->_next = newNode;
		queue->_tail = newNode;
	}
}

void QueuePop(Queue* queue) {
	assert(queue);
	assert(queue->_head);
	QueueNode* next = queue->_head->_next;
	free(queue->_head);
	queue->_head = next;
	//当删除了所有的结点，所以避免tail是野指针
	if (queue->_head == NULL) {
		queue->_tail = NULL;
	}

}

QDataType QueueFront(Queue* queue) {
	assert(queue);
	assert(queue->_head);
	return queue->_head->_data;
}

QDataType QueueBack(Queue* queue) {
	assert(queue);
	assert(queue->_tail);
	return queue->_tail->_data;

}

int QueueEmpty(Queue* queue) {
	assert(queue);
	return !queue->_head;
}

int QueueSize(Queue* queue) {
	assert(queue);
	QueueNode* cur = queue->_head;
	int size = 0;
	while (cur) {
		cur = cur->_next;
		++size;
	}
	return size;
}