/*#include<bits/stdc++.h>
using namespace std;
int n,m,S,c;
string str[105];
int vis[105][105];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>S>>c;
		for(int i = 0;i<n;i++){
			cin>>str[i];
		}
		int st = 0;
		for(int i =0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(str[i][j] == 'S')
					st = i*m+j;
					vis[i][j] = 1;
			}
		}
		memset(vis,0,sizeof(vis));
		queue<pair<int,int> >q;
		vector<pair<int ,int > >v[1000];
		q.push(make_pair(st,S));
		q.push(make_pair(-1,1));
		pair<int ,int >s;
		int time = 1;int ma = 0;
		while(!q.empty()){
			s = q.front();q.pop();
			int x = s.first/m;
			int y = s.first%m;
			//cout<<x<<" "<<y<< " "<<s.second<<endl;
			if(s.first == -1){
				int x = s.second+1;
				time = x;
				for(int i = 0;i<v[x].size();i++)
				q.push(v[x][i]);
				q.push(make_pair(-1,x));
				s = q.front();q.pop();
			}
			for(int i = 0;i<4;i++){
				int tx = x+dir[i][0];
				int ty = y+dir[i][1];
				if(tx<0|ty<0||tx>=n||ty>=m||str[tx][ty] =='X'||vis[tx][ty] == 1)continue;
				if(str[tx][ty] == 'T'){break;}
				if(str[tx][ty] == 'D'){
					//cout<<tx<<" "<<ty<<endl;
					int tt = tx*m+ty;
					int qi;

					if(s.second>=c){
					//cout<<s.second<<" fdf"<<c<<endl;
						vis[tx][ty] = 1;
						qi = s.second-c;
						q.push(make_pair(tt,qi));
					}
					else{
						//cout<<s.second<<" wert"<<c<<endl;
						ma = time+c-s.second;
						//cout<<ma<<endl;
						v[time+c-s.second].push_back(make_pair(tt,0));
					}
				}
				else{
					vis[tx][ty] = 1;
					int tt = tx*m+ty;
					int qi;
					(s.second<S)?qi =(s.second +1):S;
					q.push(make_pair(tt,qi));
				}
			}

		}
		cout<<time-1<<endl;
	}
}*/
#include<bits/stdc++.h>
using namespace std;
int n,m,S,c;
string str[105];
int vis[105][105];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>S>>c;
		for(int i = 0;i<n;i++){
			cin>>str[i];
		}
		int st = 0;
		for(int i =0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(str[i][j] == 'S')
					st = i*m+j;
					vis[i][j] = 1;
			}
		}
		memset(vis,0,sizeof(vis));
		queue<pair<int,int> >q;
		vector<pair<int ,int > >v[1000];
		q.push(make_pair(st,S));
		q.push(make_pair(-1,1));
		pair<int ,int >s;
		int time = 1;int ma = 0;
		while(!q.empty()){
			s = q.front();q.pop();
			int x = s.first/m;
			int y = s.first%m;
			cout<<x<<" "<<y<< " "<<s.second<<endl;
			if(s.first == -1){
				int x = s.second+1;
				time = x;
				//for(int i = 0;i<v[x].size();i++)
				//q.push(v[x][i]);
				q.push(make_pair(-1,x));
				s = q.front();q.pop();
			}
			for(int i = 0;i<4;i++){
				int tx = x+dir[i][0];
				int ty = y+dir[i][1];
				if(tx<0|ty<0||tx>=n||ty>=m||str[tx][ty] =='X'||vis[tx][ty] == 1)continue;
				if(str[tx][ty] == 'T'){break;}
				if(str[tx][ty] == 'D'){
					//cout<<tx<<" "<<ty<<endl;
					int tt = tx*m+ty;
					int qi;

					if(s.second>=c){
					//cout<<s.second<<" fdf"<<c<<endl;
						vis[tx][ty] = 1;
						qi = s.second-c;
						q.push(make_pair(tt,qi));
					}
					else{
						//cout<<s.second<<" wert"<<c<<endl;
						//ma = time+c-s.second;
						//cout<<ma<<endl;
						q.push(make_pair(s.first,s.second+1));
						//v[time+c-s.second].push_back(make_pair(tt,0));
					}
				}
				else{
					vis[tx][ty] = 1;
					int tt = tx*m+ty;
					int qi;
					(s.second<S)?qi =(s.second +1):S;
					q.push(make_pair(tt,qi));
				}
			}

		}
		cout<<time-1<<endl;
	}
}

















