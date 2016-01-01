#include<stdio.h>

int main(){
    int n,m;
    scanf("%d",&n);
    m = n%10*100+n/10%10*10+n/100;
    printf("%03d\n",m);
    return 0;
}

#define TRUE
#ifndef TRUE
int main(){
    int n,m = 0;
    scanf("%d",&n);
    for(int i = 0;i<3;i++){
        m  = m*10+n%10;
        n/=10;
    }
    printf("%03d%\n",m);
    return 0;
}
#endif
