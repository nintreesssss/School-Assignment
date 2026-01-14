#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    int Capacity;    // 堆的最大容量
    int Size;        // 堆当前元素个数
    ElementType *Elements; // 存储元素的数组
};

PriorityQueue Initialize(int capacity) { //初始化
    PriorityQueue H;
    H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    if (H == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    H->Elements = (ElementType *)malloc((capacity + 1) * sizeof(ElementType));
    if (H->Elements == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    H->Capacity = capacity;
    H->Size = 0;
    H->Elements[0] = -32767;  // 哨兵（小于任何输入值）
    return H;
}

void Insert(ElementType x, PriorityQueue H) {
    int i;
    if (H->Size == H->Capacity) {
        printf("堆已满\n");
        return;
    }
    // 上滤
    for (i = ++H->Size; H->Elements[i / 2] > x; i /= 2) {
        H->Elements[i] = H->Elements[i / 2];
    }
    H->Elements[i] = x;
}

void BuildHeap(ElementType arr[], int n, PriorityQueue H) {
    if (n > H->Capacity) {
        printf("元素数量超过堆容量\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        Insert(arr[i], H);
    }
}

ElementType FindMin(PriorityQueue H) {
    if (H->Size == 0) {
        printf("堆为空\n");
        return -1;
    }
    return H->Elements[1];
}

ElementType DeleteMin(PriorityQueue H) {
    int i, Child;
    ElementType MinElement, LastElement;

    if (H->Size == 0) {
        printf("堆为空，无法删除\n");
        return -1;
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];

    // 下滤
    for (i = 1; i * 2 <= H->Size; i = Child) {
        Child = i * 2;  // 左子节点
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child]) {
            Child++;  // 选择较小的子节点
        }
        if (LastElement > H->Elements[Child]) {
            H->Elements[i] = H->Elements[Child];
        } else {
            break;
        }
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

void PrintHeap(PriorityQueue H) {
    if (H->Size == 0) {
        printf("堆为空\n");
        return;
    }
    for (int i = 1; i <= H->Size; i++) {
        printf("%d ", H->Elements[i]);
    }
    printf("\n");
}

int main(){
    ElementType test[]={53, 26, 97, 59, 41, 31, 58};
    int n = sizeof(test)/sizeof(ElementType);
    PriorityQueue H = Initialize(n);
    BuildHeap(test,n,H);
    PrintHeap(H);
    printf("minimum:%d\n",FindMin(H));
    DeleteMin(H);
    PrintHeap(H);
    return 0;
}


