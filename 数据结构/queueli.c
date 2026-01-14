#include "queueli.h"
#include <stdio.h>
#include <stdlib.h>

Queue CreateQueue(void){
    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    if (Q == NULL) {
        printf("内存分配失败");
    }

    Q ->Front =NULL;
    Q ->Rear =NULL;
    Q ->Size =0;

    return Q;
}

void DisposeQueue(Queue Q){
    if (Q == NULL) {
        printf("队列为空");
    }

    MakeEmpty(Q);
    free(Q);
}

void MakeEmpty(Queue Q) {
    if (Q == NULL) {
        printf("队列为空");
    }
    
    while (!IsEmpty(Q)) {
        Dequeue(Q);
    }
}

int IsEmpty(Queue Q){
    if (Q == NULL) {
        printf("队列为空");
    }
    return(Q->Front == NULL) || (Q->Size == 0);
}

void Enqueue(ElementType X,Queue Q){
    if (Q == NULL) {
        printf("队列为空");
    }
    PtrToNode NewNode = (PtrToNode)malloc(sizeof(struct Node));
    if (NewNode == NULL) {
        printf("内存分配失败");
    }
    NewNode->Element = X;
    NewNode->Next =NULL;
    if (IsEmpty(Q))
    {
        Q->Front = NewNode;
        Q->Rear = NewNode;
    }else{
        Q->Rear->Next = NewNode;
        Q->Rear = NewNode;
    }
    
    Q->Size++;
}

void Dequeue(Queue Q){
    if (Q == NULL || IsEmpty(Q))
    {
        printf("队列为空");
    }
    PtrToNode Temp = Q->Front;

    if(Q->Front == Q->Rear)
    {
        Q->Front = NULL;
        Q->Rear = NULL;
    }else{
        Q->Front = Q->Front->Next;
    }
    Q->Size--;
}

ElementType Front(Queue Q){
    if (Q == NULL || IsEmpty(Q))
    {
        printf("队列为空");
    }
    return Q->Front->Element;
}

void PrintQueue(Queue Q){
    if (Q == NULL || IsEmpty(Q))
    {
        printf("队列为空");
        return;
    }
    PtrToNode Current = Q->Front;
    while (Current != NULL)
    {
        printf("%d\n",Current->Element);
        Current = Current->Next;
    }
    
}