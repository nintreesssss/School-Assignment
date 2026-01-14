#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct BTNode;
struct BTNode
{
    ElementType Element;
    struct BTNode *Left;
    struct BTNode *Right;
};
typedef struct BTNode BTNode;


int leaf(BTNode *t, int n) {
    if (t == NULL) {
        return 0;  
    }

    if (t->Left == NULL && t->Right == NULL) {
        return 1 + n;  
    }
 
    return leaf(t->Left, n) + leaf(t->Right, n);
}