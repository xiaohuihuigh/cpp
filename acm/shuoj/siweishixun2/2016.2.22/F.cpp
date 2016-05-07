#include<bits/stdc++.h>
#define INF 0x3FFFFFFF
using namespace std;
const int MAXN = 310;
int G[MAXN][MAXN];
void init(int n){
    for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
        G[i][j] = INF;
}
void Floyd(int n){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
            }
        }
    }
}
int main(){
	int n,m;
	while(cin>>n>>m){
	init(n);
		for(int i = 0;i<m;i++){
			int a,b;
			cin>>a>>b;
			G[a][b] = 1;
		}
		Floyd(n);
		int k = 0;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(i!=j){
					if(G[i][j] <INF&&G[j][i]<INF)
					{
						cout<<"NO"<<endl;
						k = 1;
						break;
					}
				}
			}
			if(k == 1)break;
		}
		if(k ==0)cout<<"YES"<<endl;
	}
}

