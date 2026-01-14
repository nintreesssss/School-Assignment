#include "queueli.h"
#include <stdio.h>

void main(){
    Queue Q = CreateQueue();
    Enqueue(0,Q);
    Enqueue(3,Q);
    Enqueue(99,Q);
    Enqueue(100,Q);
    Enqueue(106,Q);
    Enqueue(58,Q);
    Enqueue(9,Q);
    Enqueue(365,Q);
    PrintQueue(Q);
    Dequeue(Q);
    Dequeue(Q);
    Dequeue(Q);
    PrintQueue(Q);
}