#include "Stack.h"
#include"Queue.h"

void TestStack() {
	Stack stack;
	StackInit(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	printf("%d\n\n", StackSize(&stack));
	while (!StackEmpty(&stack)) {
		printf("%d\n", StackTop(&stack));
		StackPop(&stack);
	}
}

//1.Ӧ�ó������Ƚ��ȳ�����������Ҫ�������й�ƽ���Ŷӳ�Ż�
//2.�����������
void TestQueue() {
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 5);
	while (!QueueEmpty(&queue)) {
		printf("%d\n",QueueFront(&queue));
		QueuePop(&queue);
	}
}

int main() {
	TestQueue();
	//TestStack();
}