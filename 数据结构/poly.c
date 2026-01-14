#include <stdio.h>
#include <stdlib.h>

typedef  struct _T_term term_t,elem_t;//定义项
struct _T_term {
    int Coef,Exp;
};

typedef struct _T_node node_t;//定义节点
struct _T_node {
    elem_t Elem;
    node_t *Next;
};

typedef  node_t  *poly;//头节点
void InsertMiddle(node_t *head, int k, int newNum){
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        return;
    }
    newNode->Elem.Coef = newNum;
    newNode->Elem.Exp = 0;
    newNode->Next = NULL;
    if (k == 0)//特殊情况在头部插入
    {
        newNode->Next = head;
        head = newNode;
        return;
    }

    node_t *pre = head;
    int currentPos = 1;
    while (pre != NULL && currentPos < k)//从头部开始遍历
    {
        pre = pre->Next;
        currentPos++;
    }
    if (pre == NULL) {//k超出链表长度或链表为空
        printf("k无效\n");
        free(newNode);
        return;
    }
    newNode->Next = pre->Next;  //插入
    pre->Next = newNode;
}