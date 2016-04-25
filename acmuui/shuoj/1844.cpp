#include<stdio.h>
int main(){
    int q[100],p[100],n,i,j,k,count,sum = 0;
    while(scanf("%d\n",&n) == 1)
    {
        sum = 0;
        for(i=1;i<=n;i++)
            scanf("%d",&p[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&q[i]);
        for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        {
            if(p[i]<p[j])
            {
                count = p[i];
                p[i] = p[j];
                p[j] = count;
            }
            if(q[i]<q[j])
            {
                count = q[i];
                q[i] = q[j];
                q[j] = count;
            }
        }
        for(i=1;i<=n;i++)
        {
            sum = sum +p[i]*q[i];
        }
        printf("%d\n",sum);

    }
    return 0;
    }
/**************************************************************
    Problem: 1844
    User: xiaohuihui
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:988 kb
****************************************************************/
