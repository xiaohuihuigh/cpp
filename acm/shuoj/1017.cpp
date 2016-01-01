#include<bits/stdc++.h>
using namespace std;
int a[100];
int l = 100000;
void cheng(int a[],int t,int& len){
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
        cheng(a,1024,len);
        n -=10;
    }
    for(int i = 0;i<n;i++){
        cheng(a,2,len);
    }
    a[0]--;
   printf("%d\n",lenn);
    for(int i = 99;i>=0;i--){
        printf("%05d",a[i]);
    }
}
