#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char c[1005][1005];
int sum[1005][1005][2];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;getchar();
        memset(sum,0,sizeof(sum));
        memset(c,'x',sizeof(c));
  for(int i = 0;i<n;i++){
  for(int j = 0;j<m;j++){
           scanf("%c",&c[i][j]);
            }getchar();}
                    for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(c[i][j] == 'x'){
                sum[i][j][0] = 0,sum[i][j][1] = 0;
                int t =  j-1;
                while(t>0&&c[i][t-1]!='x'&&c[i][t]!='x'){
                    sum[i][t-1][0] = sum[i][t][0];
                    t--;
                } t =  i-1;
                while(t>0&&c[t-1][j] != 'x'&&c[t][j]!='x'){
                    sum[t-1][j][1] = sum[t][j][1];
                    t--;
                }
                }
                else {
                if(i == 0&&j == 0){sum[i][j][0] =1;sum[i][j][1] = 1;}
                 else if(i == 0){sum[i][j][0] = sum[i][j-1][0]+1;sum[i][j][1] = 1;}
                    else if(j == 0) {sum[i][j][1] = sum[i-1][j][1]+1;sum[i][j][0] =1;}
                 else{
                        sum[i][j][0] = sum[i][j-1][0]+1;
                        sum[i][j][1] = sum[i-1][j][1]+1;
                        }
                }
            }
        }  int ma = 0;
         for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ma = max(ma,sum[i][j][0]+sum[i][j][1]);
            }}


            cout<<ma-2<<endl;

    }
}
