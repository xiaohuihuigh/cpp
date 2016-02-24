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
