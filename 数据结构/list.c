#include <stdio.h>
#include <stdlib.h>
 typedef struct _T_linear_list{
    int a[100];   //初始化
    int a_len;
 } linear_list_t;
 typedef enum _T_error_t
    {NOERROR, OVERFLOW, SUBSCRIPT}
    error_t;
 typedef int elem_t;

  /* create and destroy the linear list */
 linear_list_t *Create(void);
 void Destroy(linear_list_t *L);

 linear_list_t *Create(void)
{
    linear_list_t *L = (linear_list_t*)malloc(sizeof(*L));

    if (L)
        L->a_len = 0;

    return L;
}

void Destroy(linear_list_t *L)
{
    free(L);
}

/* A set of operations */
void Set_null(linear_list_t *L);/* empty list*/
int Length(linear_list_t *L); /* length of the list */
elem_t  Get(linear_list_t *L, int i); /* get the value */
error_t Insert(linear_list_t *L, elem_t x, int i); /* insert */
error_t Remove(linear_list_t *L, int i);/* remove */
int Locate(linear_list_t *L, elem_t x);/* locate the pos.*/

/* empty list*/
void Set_null(linear_list_t *L)
{
    L->a_len = 0;
}

/* the length of the list*/
int Length(linear_list_t *L)
{
    return L->a_len;
}

/* get the value at position i*/
elem_t Get(linear_list_t *L, int i)
{
    if (i < 0 || i >= L->a_len )
        ERROR("Subscript");

    return L->a[i];
}

/* insert */
error_t Insert(linear_list_t *L, elem_t x, int i)
{
    if(L->a_len >=100)
    return OVERFLOW;//检查数组空间

    if (i<0 || i>L->a_len)//检查插入位置是否合法
    {
        return SUBSCRIPT;
    }
    
    for (int j = i; j < L->a_len; j++)//从插入位置每项右移一位
    {
        L->a[j] = L->a[j+1];
    }
    
    L->a[i] = x;//赋值

    L->a_len++;//长度加一
    return NOERROR;
}

/* locate the pos.*/
int Locate(linear_list_t *L, elem_t x)
{
    int p=0;
    for (int i = 0; i < L->a_len; i++)
    {
        if(L->a[i] == x)
            break;
        else p++;
        if (p == L->a_len)
        {
            p=-1;
        }                
    }
    return p;
}

error_t RemoveDup(linear_list_t *L) {
    if (L == NULL) {
        return SUBSCRIPT;
    }

    if (L->a_len <= 1) {
        return NOERROR;
    }

    for (int i = 0; i < L->a_len; i++) {  //遍历所有元素
        elem_t current = Get(L, i);
        int j = i + 1;
        while (j < L->a_len) {    //遍历每个元素后的所有元素检查是否有重复
            if (Get(L, j) == current) {
                error_t err = Remove(L, j);
                if (err != NOERROR) {
                    return err; 
                }
                L->a_len--; //长度减一
            } else {
                j++; //继续
            }
        }
    }

    return NOERROR;
}