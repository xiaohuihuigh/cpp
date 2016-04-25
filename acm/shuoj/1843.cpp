#include<stdio.h>
int main(){
    int n,m,i,a = 0,b = 0,c[20],j;
    while(scanf("%d",&n) == 1){
        m = 1;
        a = 0;
        b = 0;
        for(i = 0;m != 0;i++)
        {
            m = n/2;
            c[i] = n%2;
            n = m;
        }
        j=i-1;
        i = 0;
        while(c[i++] == 0)
        b++;
        for(j;j>=i-1;j--){
            a = a*2 +c[j];
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}
/**************************************************************
    Problem: 1843
    User: xiaohuihui
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:988 kb
****************************************************************/
