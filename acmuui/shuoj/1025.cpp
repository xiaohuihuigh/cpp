#include <stdio.h>
int main() //把main函数定义成int类型
{
int a,b,t;
scanf("%d",&t);
while(t--) // 输入结束时，scanf函数返回值为EOF，即没有数据输入时则退出while循环

{
scanf("%d%d",&a,&b);
printf("%d\n",a+b);

}
return 0; //返回值为0
}

/**************************************************************
    Problem: 1025
    User: xiaohuihui
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:988 kb
****************************************************************/
