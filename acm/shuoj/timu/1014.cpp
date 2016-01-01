#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[10000];
int b[10000];
int c[10000];
int d[10000];
int main(){
    char s;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    int i = 0;int j = 0;int yn =0;int first = 0;
    while((s = getchar())!=EOF){
    if(s == 'E'){
        if(first == 0){cout<<"0:0"<<endl<<endl<<"0:0";return 0;}
     //   if(a[i] == 0&&b[i] == 0)i--;
        //if(c[j] == 0&&d[j] == 0)j--;
            for(int ii  =0;ii<=i;ii++){
                cout<<a[ii]<<":"<<b[ii]<<endl;
            }
            cout<<endl;
            for(int jj  =0;jj<=j;jj++){
                cout<<c[jj]<<":"<<d[jj]<<endl;
            }
            return 0;
        }
        first ++;
        if(s == 'W'){a[i]++;c[j]++;}
        if(s == 'L'){b[i]++;d[j]++;}
        if(a[i]>= 11&&a[i]-b[i]>=2)i++;
        if(b[i]>= 11&&b[i]-a[i]>=2)i++;
        if(c[j] >= 21&&c[j] - d[j]>=2)j++;
        if(d[j] >= 21&&d[j] - c[j]>=2)j++;

    }
    return 0;
}
