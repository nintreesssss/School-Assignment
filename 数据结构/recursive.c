#include <stdio.h>

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }else{
        return sum(n-1) + n;
    }
}

void main(){
    int n;
    printf("请输入数字\n");
    scanf("%d",&n);
    printf("%d",sum(n));
    return;
}
