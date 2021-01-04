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
//使用二级指针将头节点置空
void ListDestory(ListNode **pphead);
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
	/*assert(phead);
	ListNode* tail = phead->prev;

	ListNode* newNode = ListBuyNode(x);

	tail->next = newNode;
	newNode->prev = tail;
	newNode->next = phead;
	phead->prev = newNode;*/
	//代码复用
	ListInsert(phead,x);
}

void ListPopBack(ListNode* phead) {
	/*assert(phead);
	assert(phead->next != phead);
	ListNode* tail = phead->prev;
	ListNode* tailprev = tail->prev;
	phead->prev = tailprev;
	tailprev->next = phead;
	free(tail);
	tail = NULL;*/
	//代码复用
	ListErase(phead->prev);
}

void ListPushFront(ListNode* phead, LTDataType x) {
	/*assert(phead);	
	ListNode* cur = ListBuyNode(x);
	ListNode* first = phead->next;
	phead->next = cur;
	cur->prev = phead;
	cur->next = first;
	first->prev = cur;*/
	//代码复用
	ListInsert(phead->next,x);
}
void ListPopFront(ListNode* phead) {
	/*assert(phead);
	assert(phead->next != phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);*/
	//代码复用
	ListErase(phead->next);
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
	assert(pos->next!=pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
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

void ListDestory(ListNode** pphead) {
	assert(*pphead);
	ListClear(*pphead);
	free(*pphead);
	*pphead = NULL;
}
```



### [707. 设计链表](https://leetcode-cn.com/problems/design-linked-list/)

```cpp
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int x) {
            val = x;
            next = nullptr;
            prev = nullptr;
        }
    };
    /** Initialize your data structure here. */
    MyLinkedList() {
        dynamic = new ListNode(-1);
        size = 0;
        dynamic->next = dynamic;
        dynamic->prev = dynamic;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size)return -1;
        return findNode(index)->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        insertNode(dynamic->next, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        insertNode(dynamic, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) {
            insertNode(dynamic->next, val);
        }
        else if (index == size) {
            insertNode(dynamic, val);
        }
        else {
            insertNode(findNode(index), val);
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return;
        ListNode* cur = findNode(index);
        ListNode* preCur = cur->prev;
        ListNode* nextCur = cur->next;
        delete cur;
        preCur->next = nextCur;
        nextCur->prev = preCur;
        size--;
    }
    ListNode* findNode(int index) {
        ListNode* temp = dynamic;
        for (int i = 0; i <= index; i++) {
            temp = temp->next;
        }
        return temp;
    }
    void insertNode(ListNode* pos, int val) {
        ListNode* prePos = pos->prev;
        ListNode* cur = new ListNode(val);
        prePos->next = cur;
        cur->prev = prePos;
        cur->next = pos;
        pos->prev = cur;
        size++;
    }
    void print() {
        ListNode* cur = dynamic->next;
        while (cur != dynamic) {
            cout << cur->val << endl;
            cur = cur->next;
        }
    }
public:
    ListNode* dynamic;
    int size;
};
```



### [146. LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/)

```cpp
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        const auto it = m_.find(key);
        // If key does not exist
        if (it == m_.cend()) return -1;
 
        // Move this key to the front of the cache
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {        
        const auto it = m_.find(key);
        
        // Key already exists
        if (it != m_.cend()) {
            // Update the value
            it->second->second = value;
            // Move this entry to the front of the cache
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        
        // Reached the capacity, remove the oldest entry
        if (cache_.size() == capacity_) {
            const auto& node = cache_.back();
            //将map中的key移除
            m_.erase(node.first);
            //将list中的移除
            cache_.pop_back();
        }
        
        // Insert the entry to the front of the cache and update mapping.
        cache_.emplace_front(key, value);
        m_[key] = cache_.begin();
    }
private:
    int capacity_;
    list<pair<int,int>> cache_;
    unordered_map<int, list<pair<int,int>>::iterator> m_;
};
```



### 链表和顺序表(数组)的区别和联系(答优缺点)：

**优点：**顺序表就是在数组的基础上实现增删改查，并且插入时可以动态增长

**缺点：**

- 可能存在一定空间浪费
- 增容有一些效率损失
- 中间或者头部插入删除，时间复杂度为O(N)，因为要挪动数据

**这些问题链表来解决就是链表的有点**

**链表的缺陷：不能随机访问数据**

这两种数据结构**互补**

