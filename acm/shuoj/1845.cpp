#include<stdio.h>
int main(){
    int l,m,q,z,w = 0,i;
    bool a[10001];
    while (scanf("%d",&l)== 1 && scanf("%d",&m)== 1){
        if(l > 10000||l < 0||m > 100||m < 0)
        continue;
        w = 0;
        for(i = 0;i <= l;i++)
        a[i] = true;
        while(m--){
            scanf("%d%d",&q,&z);
            for(i = q;i<=z;i++)
            if(a[i] == true)
                a[i] = false;
        }
        for(i=0;i<=l;i++)
        if(a[i])
            w++;
        printf("%d\n",w);
        }
    return 0;
}

/**************************************************************
    Problem: 1845
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1052 kb
****************************************************************/
