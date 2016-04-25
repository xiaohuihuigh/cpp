#include <stdio.h>
#include <string.h>

#define max(a,b) ((a)>(b)?(a):(b))

int a[1001];

int main(){

 int T,M;
 scanf("%d%d",&T,&M);

 memset(a,0,sizeof(a));

for(int i=0;i<M;i++){
  int t,v;
  scanf("%d%d",&t,&v);
  for(int j=T-t;j>0;j--)if(a[j])
   a[j+t] = max(a[j+t],a[j] + v);
  a[t] = max(a[t],v);
 }

 int ans = 0;
 for(int i=1;i<=T;i++)
  ans = max(ans,a[i]);

 printf("%d\n",ans);

 return 0;
}

/**************************************************************
    Problem: 1043
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1056 kb
****************************************************************/
