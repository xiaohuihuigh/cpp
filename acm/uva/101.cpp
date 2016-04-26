#include<bits/stdc++.h>
using namespace std;
const int maxn = 30;
int blocks[maxn][maxn];
int cnt[maxn];
int pos[maxn];
int fa[maxn];
int main(){
	int n;
	cin>>n;
		for(int i = 0;i<n;i++){
			cnt[i] = 1;
			pos[i] = 0;
			fa[i] = i;
			blocks[i][0] = i;
		}
		string s1,s2;int a,b;
		while(cin>>s1&&s1!="quit"){
			cin>>a>>s2>>b;
			if(fa[a] == fa[b]) continue;
			if(s1 == "move"){
				if(s2 == "onto"){
					for(int i = pos[a]+1;i<cnt[fa[a]];i++){
						int t = blocks[fa[a]][i];
						blocks[t][0] = t;
						cnt[t]++;
						pos[t] = 0;
						fa[t] = t;
					}
					cnt[fa[a]] = pos[a];
					for(int i = pos[b]+1;i<cnt[fa[b]];i++){
						int t = blocks[fa[b]][i];
						blocks[t][0] = t;
						cnt[t]++;
						pos[t] = 0;
						fa[t] = t;
					}
					blocks[fa[b]][pos[b]+1] = a;
					cnt[fa[b]] = pos[b]+2;
					fa[a] = fa[b];
					pos[a] = pos[b]+1;
				}
				else{
					for(int i = pos[a]+1;i<cnt[fa[a]];i++){
						int t = blocks[fa[a]][i];
						blocks[t][0] = t;
						cnt[t]++;
						pos[t] = 0;
						fa[t] = t;
					}
					cnt[fa[a]] = pos[a];

					blocks[fa[b]][cnt[fa[b]]] = a;
					cnt[fa[b]]++;
					fa[a] = fa[b];
					pos[a] = cnt[fa[b]]-1;
				}
			}
			else if(s1 == "pile"){
				if(s2 == "onto"){
					int posa = pos[a];
					for(int i = pos[b]+1;i<cnt[fa[b]];i++){
						int t = blocks[fa[b]][i];
						blocks[t][0] = t;
						cnt[t]++;
						pos[t] = 0;
						fa[t] = t;
					}
					cnt[fa[b]] = pos[b]+1;
					for(int i = pos[a];i<cnt[fa[a]];i++){
						int t = blocks[fa[a]][i];
						blocks[fa[b]][cnt[fa[b]]] = t;
						pos[t] = cnt[fa[b]];
						cnt[fa[b]]++;
						fa[t] = fa[b];
					}
					cnt[fa[a]] = posa;
				}
				else{
//					cout<<s1<<a<<s2<<b<<endl;
					int faa = fa[a];
					int posa = pos[a];
//					cout<<cnt[fa[a]]<<"cnt"<<endl;
					int cnta = cnt[fa[a]];
					for(int i = posa;i<cnta;i++){
//						cout<<i<<endl;
						int t = blocks[faa][i];
						blocks[fa[b]][cnt[fa[b]]] = t;
//						cout<<"t"<<t<<endl;
						pos[t] = cnt[fa[b]];
						cnt[fa[b]]++;
//						cout<<"fa"<<fa[b]<<"cnt"<<cnt[fa[b]]<<endl;
						fa[t] = fa[b];
					}
					cnt[faa] = posa;
//					cout<<cnt[fa[a]]<<"cnt"<<endl;
				}
			}
		}
		for(int i = 0;i<n;i++){
		cout<<i<<": ";
		for(int j = 0;j<cnt[i];j++){
			if(j!= 0)cout<<" ";
			cout<<blocks[i][j];
		}
		cout<<endl;
		}
}
