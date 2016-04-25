#include<stdio.h>
int main(){
    long long int sum;
    int m,n,i;
    while(scanf("%d",&m),scanf("%d",&n)==1){
        sum = 1;
        for(i = 1;i< n;i++)
            sum = sum *i;
        for(i = 1;i<=n;i++)
            sum = sum *i;
        for(i = 1;i<= n-m;i++)
        sum = sum / i;
        printf("%lld\n",sum);
    }
    return 0;
}
/**************************************************************
    Problem: 1833
    User: xiaohuihui
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:988 kb
****************************************************************/
