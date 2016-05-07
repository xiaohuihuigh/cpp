#include<stdio.h>
int main()
{
    int n,m,c;
    scanf("%d%d",&n,&m);
    c = m;
    m = n;
    n = c;
    printf("%d %d\n",n,m);
    return 0;
}
