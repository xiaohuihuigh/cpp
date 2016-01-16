
#include<bits/stdc++.h>
using namespace std;
char s[1100][1100];
int huo[1100][1100];
int vis[1100][1100];
int dis[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int main(){
         std::ios::sync_with_stdio(false);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;int yn = 0;
		scanf("%d%d",&n,&m);
		for(int i = 0;i<n;i++)scanf("%s",s[i]);
		memset(huo,-1,sizeof(huo));
		memset(vis,-1,sizeof(vis));
		queue<int >pre;
		queue<int >Q;
		getchar();
		for(int i = 0;i<n;i++)
		for(int j  = 0;j<m;j++)
			if(s[i][j] == 'F'){
				pre.push(i*m+j);
				huo[i][j] = 0;
			}
			else if(s[i][j] == 'J'){
				Q.push(i*m+j);
				vis[i][j] = 0;
			}
		while(!pre.empty()){
			int t = pre.front();pre.pop();
			int x = t/m;
			int y = t%m;
			for(int i = 0;i<4;i++){
				int tx = x+dis[i][0];
				int ty = y+dis[i][1];
				if(tx<0||ty<0||tx>=n||ty>=m)continue;
				if((s[tx][ty] == '.'||s[tx][ty]=='J')&&huo[tx][ty] == -1){
					huo[tx][ty] = huo[x][y]+1;
					pre.push(tx*m+ty);
				}
			}
		}
		while(!Q.empty()){
			int t = Q.front();Q.pop();
			int x = t/m;
			int y = t%m;
			if(x <=0||y<=0||x>=n-1||y>=m-1){
					yn = vis[x][y]+1;break;
				}
			for(int i = 0;i<4;i++){
				int tx = x+dis[i][0];
				int ty = y+dis[i][1];

				if(vis[x][y]+1>=huo[tx][ty]||s[tx][ty] == '#')continue;
				vis[tx][ty] = vis[x][y] +1;
				Q.push(tx*m+ty);
			}
		}
			/*for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				cout<<vis[i][j]<<" ";
			}cout<<endl;}cout<<endl;
			for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				cout<<huo[i][j]<<" ";
			}cout<<endl;}*/
			if(yn)printf("%d\n",yn);
			else printf("IMPOSSIBLE\n");
		EN:;
	}

}/*
2
4 4
####
#JF#
#..#
#..#
3 3
###
#J.
#.F
*/
