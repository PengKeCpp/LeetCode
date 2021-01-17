#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;

//��ʼ��ջ�Ĵ�С

extern const int N;
typedef struct Stack {
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

//ջ�����ٺͳ�ʼ��
void StackInit(Stack* stack);
void StackDestroy(Stack* stack);

//ջ�Ľ���
void StackPush(Stack* stack, STDataType x);
void StackPop(Stack* stack);

//�ж�ջ�Ƿ�Ϊ�գ�����1Ϊ�գ�����0��Ϊ��
int StackEmpty(Stack* stack);
//����ջ�Ĵ�С��ֱ�ӷ���top��ֵ
int StackSize(Stack* stack);

//����ջ����ֵ
STDataType StackTop(Stack* stack);
