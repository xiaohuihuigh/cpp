#include<stdio.h>
int main(){
    int n,m;
    scanf

          d%d",&n,&m);
    int a,b;
    a = (m - 2*n)/2;
    b = n - a;
    if(a < 0||b < 0 || m&1)
        printf("No Answer\n");
    else
        printf("%d %d\n",b,a);
    return 0;
}
