#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1005];
int b[1005];
int c[1005];
int id[1005];
int dp[1005];
bool cmp(int x,int y){
        return a[x]<a[y]?1:0;
    }
int main(){
    int T;int ca = 0;
    while(cin>>T){
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<T;i++){
            id[i] = i;
            cin>>a[i]>>b[i];
            c[a[i]] = b[i];
            }
        /*    for(int i = 1;i<=T;i++){
                for(int j = 1;j<=T;j++)

                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])+(c[i] == j?1:0);
                }
            }
            cout<<dp[T][T]<<endl;
*/
        int len = 0;
            for(int i = 1;i<=T;i++){
                int l = lower_bound(dp,dp+len+1,c[i])-dp;
                dp[l] =c[i];
                len = max(len,l);
            }
            cout<<"Case "<<++ca<<":"<<endl;
            cout<<"The Maximal number is: "<<len<<endl;

           // cout<<len+1<<endl;
        }

    }
