#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
struct Node {
    ElementType  Element;
    PtrToNode   Next;  
};//单链表节点定义

struct DNode {
    ElementType Element;
    struct DNode *Prev; // 前驱指针
    struct DNode *Next; // 后继指针
};//双链表节点定义

typedef enum _T_error_t
    {NOERROR, OVERFLOW, SUBSCRIPT}
    error_t;
typedef int elem_t;//错误类型

void PrintList(Position head) {
    if (head == NULL) {
        printf("链表为空\n");
        return;
    }
    
    Position current = head;
    while (current != NULL) {
        printf("%d ", current->Element);
        current = current->Next;
    }
    printf("\n");
}

// 打印L中由P指定位置的元素
void print_lots(Position L, Position P) {
    if (L == NULL) {
        printf("链表L为空\n");
        return;
    }
    if (P == NULL) {
        printf("链表P为空\n");
        return;
    }

    Position p_current = P;  // 遍历P
    while (p_current != NULL) {
        int pos = p_current->Element;  // 获取当前要打印的位置
        if (pos < 1) {  // 忽略无效位置（小于1）
            p_current = p_current->Next;
            continue;
        }

        Position l_current = L;  // 遍历L的指针
        int current_pos = 1;     // 当前在L中的位置
        // 找到L中第pos个元素
        while (l_current != NULL && current_pos < pos) {
            l_current = l_current->Next;
            current_pos++;
        }

        // 检查是否找到有效元素
        if (l_current != NULL) {
            printf("%d ", l_current->Element);
        } else {
            printf("(位置%d超出链表L长度) ", pos);
        }

        p_current = p_current->Next;  // 处理P的下一个位置
    }
    printf("\n");
}

// 交换单链表中p和其后继节点
void swapAdjacentSingly(PtrToNode *head, Position p) {
    if (p == NULL || p->Next == NULL) return; // 无效节点
    
    Position q = p->Next;
    Position prev = NULL;
    Position current = *head;
    
    // 寻找p的前驱节点prev
    while (current != NULL && current != p) {
        prev = current;
        current = current->Next;
    }
    
    // 调整指针
    if (prev != NULL) {
        prev->Next = q; // 前驱指向q
    } else {
        *head = q; // 若p是头节点，更新头指针
    }
    p->Next = q->Next; // p指向q的后继
    q->Next = p;       // q指向p
}

// 交换双链表中p和其后继节点
void swapAdjacentDoubly(struct DNode **head, struct DNode *p) {
    if (p == NULL || p->Next == NULL) return;
    
    struct DNode *q = p->Next;
    
    //处理p的前驱
    if (p->Prev != NULL) {
        p->Prev->Next = q;
    } else {
        *head = q; //若p是头节点，更新头指针
    }
    
    //处理q的后继
    if (q->Next != NULL) {
        q->Next->Prev = p;
    }
    
    //调整p和q之间的指针
    p->Next = q->Next;
    q->Prev = p->Prev;
    q->Next = p;
    p->Prev = q;
}