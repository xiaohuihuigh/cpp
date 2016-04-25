#include<stdio.h>
#include<math.h>
void jh(int &a,int &b){
    int t;
    t = a;
    a = b;
    b = t;
}

int main(){
    int a,b,c,t;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)jh(a,b);
    if(a>c)jh(a,c);
    if(b>c)jh(b,c);
    printf("%d %d %d\n",a,b,c);
    return 0;
}
