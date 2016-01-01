#include<iostream>
#include<string>
using namespace std;
string s[105];
int vis[105][105];
int cnt[10005];
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;int st;
        cin>>n>>m;
        for(int i = 0;i<n;i++)cin>>s[i];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(s[i][j] == 'S')
                st = i*m+j;
            }
        }
        queue<int>Q;

        Q.push(st);cnt[st] =0;
        vis[st/m][st%m] = 1;
        while(!Q.empty()){
            int t = Q.top();Q.pop();
            int x = t/m,y = t%m;
            for(int i=  0;i<4;i++){
                int tx = x+dir[i][0];
                int ty = y+dir[i][1];
                if(tx>=0&&ty>=0&&tx<n&&tx<m&&vis[tx][ty] == 0&&(s[tx][ty] != '#'){

                    int tt = tx*m+ty;
                    cnt[tt] = cnt[t]+1;
                    vis[tx][ty] = 1;
                    if(s[tx][ty] == 'E')
                    Q.push(tt);


            }
        }
    }
}
