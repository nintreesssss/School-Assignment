#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
struct AvlNode {
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

static int Height(Position P) {
    if (P == NULL) return 0;
    else return P->Height;
}


static int Max(int a, int b) {
    return a > b ? a : b;
}

// 左左：右单旋
Position SingleRotateWithLeft(Position K2) {
    Position K1 = K2->Left;
    
    K2->Left = K1->Right;
    K1->Right = K2;
    
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), K2->Height) + 1;
    
    return K1;
}

// 右右：左单旋
Position SingleRotateWithRight(Position K1) {
    Position K2 = K1->Right;
    
    K1->Right = K2->Left;
    K2->Left = K1;
    
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K2->Height = Max(Height(K2->Right), K1->Height) + 1;
    
    return K2;
}

// 左右：先左单旋再右单旋
Position DoubleRotateWithLeft(Position K3) {
    // 先对左子树进行左单旋
    K3->Left = SingleRotateWithRight(K3->Left);
    // 再对当前节点进行右单旋
    return SingleRotateWithLeft(K3);
}

// 右左：先右单旋，再左单旋
Position DoubleRotateWithRight(Position K1) {
    // 先对右子树进行右单旋
    K1->Right = SingleRotateWithLeft(K1->Right);
    // 再对当前节点进行左单旋
    return SingleRotateWithRight(K1);
}

AvlTree Insert(ElementType X, AvlTree T) {
    if (T == NULL) {
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        if (T == NULL) {
            printf("内存分配失败\n");
            exit(1);
        }
        T->Element = X;
        T->Left = T->Right = NULL;
        T->Height = 0;
    } else if (X < T->Element) {
        T->Left = Insert(X, T->Left);
        // 检查平衡
        if (Height(T->Left) - Height(T->Right) == 2) {
            if (X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    } else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
        // 检查平衡
        if (Height(T->Right) - Height(T->Left) == 2) {
            if (X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }

    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

// 中序遍历
void InorderTraversal(AvlTree T) {
    if (T != NULL) {
        InorderTraversal(T->Left);
        printf("%d ", T->Element);
        InorderTraversal(T->Right);
    }
}

// 打印树
void PrintTree(AvlTree T, int level) {
    if (T != NULL) {
        PrintTree(T->Right, level + 1);
        for (int i = 0; i < 4 * level; i++)
            printf(" ");
        printf("%d\n", T->Element);
        PrintTree(T->Left, level + 1);
    }
}

int main() {
    AvlTree root = NULL;
    int values[] = {5, 2, 7, 1, 4, 6, 9, 3};

    for (int i = 0; i < 8; i++) {
        root = Insert(values[i], root);
    }



    PrintTree(root, 0);

    return 0;
}