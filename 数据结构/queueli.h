#ifndef QUEUELI_H
#define QUEUELI_H

// 元素类型定义
typedef int ElementType;

struct Node;
struct QueueRecord;

typedef struct Node *PtrToNode;
typedef struct QueueRecord *Queue;

struct Node {
    ElementType Element;
    PtrToNode Next;
};

struct QueueRecord {
    PtrToNode Front;  
    PtrToNode Rear;   
    int Size;         
};

//创建空队列
Queue CreateQueue(void);

//销毁队列
void DisposeQueue(Queue Q);

//清空队列
void MakeEmpty(Queue Q);

//判断队列是否为空
int IsEmpty(Queue Q);

//入队
void Enqueue(ElementType X, Queue Q);

//出队操作
void Dequeue(Queue Q);

//获取队首元素
ElementType Front(Queue Q);

//打印队列元素
void PrintQueue(Queue Q);

#endif  // QUEUELI_H