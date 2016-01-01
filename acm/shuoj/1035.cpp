#include<bits/stdc++.h>
using namespace std;
string s[105];
int a[105][105];
int dir[8][2] = {{0,1},{0,-1},{-1,0},{1,0},{-1,-1},{-1,1},{1,1},{1,-1}};
int main(){
    int n,m;
    int ca = 0;
    while(cin>>n>>m&&n&&m){
            memset(a,0,sizeof(a));
        for(int i = 0;i<n;i++)cin>>s[i];
        for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++){
                if(s[i][j] =='*')continue;
                int cnt = 0;
            for(int k = 0;k<8;k++){
                int tx = i+dir[k][0];
                int ty = j+dir[k][1];
                if(tx<0||ty<0||tx>=n||ty>=m||s[tx][ty] == '.')continue;
                cnt++;
            }
            a[i][j] = cnt;
        }
        if(++ca != 1)cout<<endl;
    cout<<"Field #"<<ca<<":"<<endl;
        for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(s[i][j] == '*')cout<<s[i][j];
            else cout<<a[i][j];

        }
        cout<<endl;
        }
    }
}
