#include<bits/stdc++.h>
using namespace std;
int a[110];
int l = 100000;
void cheng(int t,int& len){
    int jin  =0;
    for(int i = 0;i<len;i++){
        a[i ]=a[i]*t+jin;
            jin = a[i]/l;
            a[i] = a[i]%l;
    }
    if(jin != 0&&len<=99) a[len++] = jin;//cout<<len;
}
int main(){
    int n;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    a[0] = 1;int len = 1;

    int lenn = (int)(n*log10(2))+1;
    while(n>10){
        cheng(1024,len);
        n -=10;
    }int ch = 1;
    for(int i = 0;i<n;i++){
        ch *=2;
    }cheng(ch,len);
    a[0]--;
   printf("%d",lenn);
    for(int i = 99;i>=0;i--){
    if(i%10+1==10)printf("\n");
        printf("%05d",a[i]);
    }
    printf("\n");
}
