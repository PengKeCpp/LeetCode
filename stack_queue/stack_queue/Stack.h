#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDataType;

//初始化栈的大小

extern const int N;
typedef struct Stack {
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

//栈的销毁和初始化
void StackInit(Stack* stack);
void StackDestroy(Stack* stack);

//栈的进出
void StackPush(Stack* stack, STDataType x);
void StackPop(Stack* stack);

//判断栈是否为空，返回1为空，返回0不为空
int StackEmpty(Stack* stack);
//返回栈的大小，直接返回top的值
int StackSize(Stack* stack);

//返回栈顶的值
STDataType StackTop(Stack* stack);
