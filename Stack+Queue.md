### [622. 设计循环队列](https://leetcode-cn.com/problems/design-circular-queue/)

```c
//关键在于判空和判满
//判空：rear=front;
//判满：(rear+1)%k=front;
//k的值要比初始化的k值大一，这样设计循环链表才能很好的判断空和满不矛盾
//返回队尾元素时要注意当这时为rear=0时，返回的是rear=arr[k-1];所以rear=(rear-1+k)%k;
//rear指的位置是当前该插入的位置
typedef struct {
    int *arr;
    int front;
    int rear;
    int k;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front==obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear+1)%(obj->k)==obj->front;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* myQ=(MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    myQ->arr=(int*)malloc(sizeof(int)*(k+1));
    myQ->front=0;
    myQ->rear=0;
    myQ->k=k+1;
    return myQ;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)){
        return false;
    }
    obj->arr[obj->rear]=value;
    obj->rear=(obj->rear+1)%obj->k;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return false;
    }
    obj->front=(obj->front+1)%obj->k;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->arr[(obj->rear+obj->k-1)%obj->k];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}
```

