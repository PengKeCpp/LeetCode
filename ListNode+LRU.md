### List.h

```cpp
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;

typedef struct ListNode {
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType val;
}ListNode;


ListNode* ListBuyNode(LTDataType x);
void ListInitNode(ListNode** pphead);
void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);

void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);
void ListPrintNode(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
//在pos的前面插入x
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
void ListClear(ListNode *phead);
void ListDestory(ListNode *phead);
```



### List.c

```cpp
#include "List.h"

void ListInitNode(ListNode** pphead) {

	*pphead = ListBuyNode(10);
	(*pphead)->next = (*pphead);
	(*pphead)->prev = (*pphead);
}

ListNode* ListBuyNode(LTDataType x) {
	ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
	if (newHead != NULL) {
		newHead->val = x;
		newHead->next = NULL;
		newHead->prev = NULL;
	}
	return newHead;
}

void ListPushBack(ListNode* phead, LTDataType x) {
	assert(phead);
	ListNode* tail = phead->prev;

	ListNode* newNode = ListBuyNode(x);

	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;
}

void ListPopBack(ListNode* phead) {
	assert(phead);
	assert(phead->next != phead);
	ListNode* tail = phead->prev;
	ListNode* tailprev = tail->prev;
	phead->prev = tailprev;
	tailprev->next = phead;
	free(tail);
	tail = NULL;
}

void ListPushFront(ListNode* phead, LTDataType x) {
	assert(phead);	
	ListNode* cur = ListBuyNode(x);
	ListNode* first = phead->next;
	phead->next = cur;
	cur->prev = phead;
	cur->next = first;
	first->prev = cur;
}
void ListPopFront(ListNode* phead) {
	assert(phead);
	assert(phead->next != phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
}

ListNode* ListFind(ListNode* phead, LTDataType x) {
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead) {
		if (cur->val == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


void ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* insertNode = ListBuyNode(x);
	posPrev->next = insertNode;
	insertNode->prev= posPrev;
	insertNode->next = pos;
	pos->prev = insertNode;
}

void ListErase(ListNode* pos) {
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	pos = NULL;
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

void ListPrintNode(ListNode* phead) {
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead) {
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}


void ListClear(ListNode* phead) {
	assert(phead);
	ListNode* cur = phead;
	while (cur != phead) {
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	printf("%d ", cur->val);
	phead->next = phead;
	phead->prev = phead;
}

//void ListDestory(ListNode* phead) {
//	assert(phead);
//	ListClear(phead);
//	free(phead);
//}
```

