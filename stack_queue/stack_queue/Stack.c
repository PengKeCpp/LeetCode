#include "Stack.h"

extern const int N = 4;


void StackInit(Stack* stack) {
	assert(stack);
	stack->_a = (STDataType*)malloc(sizeof(STDataType)* N);
	stack->_capacity = N;
	stack->_top = 0;
}

void StackDestroy(Stack* stack) {
	assert(stack);
	free(stack->_a);
	stack->_a = NULL;
	stack->_capacity = stack->_top = 0;
}

void StackPush(Stack* stack, STDataType x) {
	assert(stack);
	if (stack->_top == stack->_capacity) {
		stack->_capacity *= 2;
		//考虑严谨
		STDataType* temp = (STDataType*)realloc(stack->_a,sizeof(STDataType)*stack->_capacity);
		if (temp == NULL) {
			printf("内存不足！");
			exit(-1);
		}
		else {
			stack->_a = temp;
		}
		//若在打算法时可以直接赋值
		//stack->_a = (STDataType*)relloc(stack->_a,sizeof(STDataType)*stack->_capacity);
	}
	stack->_a[stack->_top++] = x;
}
void StackPop(Stack* stack) {
	assert(stack);
	assert(stack->_top>0);
	--stack->_top;
}

int StackEmpty(Stack* stack) {
	assert(stack);
	return !stack->_top;
}

int StackSize(Stack* stack) {
	assert(stack);
	return stack->_top;
}

STDataType StackTop(Stack* stack) {
	assert(stack);
	assert(stack->_top > 0);
	return stack->_a[stack->_top-1];
}
