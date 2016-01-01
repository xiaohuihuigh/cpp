#include<iostream>
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;

const int INF  =0x3f3f3f3f;
const  int maxn = 1005;

int id[maxn];
int w[maxn];
int s[maxn];
int dp[maxn];
map<int,int> idp;
map<int ,int>le;
bool cmp(int x,int y){
	if(w[x]<w[y])return 1;
	if(w[x]>w[y])return 0;
	if(s[x]<s[y])return 1;
	else return 0;
}
int main(){
	int n = 0;
	while(scanf("%d%d",&w[n++],&s[n]) != EOF){id[n] = n;}
	n--;
	/*for(int i  =0;i<n;i++){
        cout<<s[i]<<endl;
	}cout<<endl;*/
	sort(id,id+n,cmp);
	for(int i  =0;i<n;i++){
		if(w[id[i]] == w[id[i+1]]){
			s[id[i+1]]  =INF;
		}
		if(s[id[i]] == s[id[i+1]]&&s[id[i]] != INF){
			s[id[i+1]] = INF;
		}
	}

	/*for(int i  =0;i<n;i++){
        cout<<s[id[i]]<<endl;
	}
	cout<<endl;*/
		reverse(id,id+n);
	dp[0] = s[id[0]];int len = 0;le[dp[0]] = len;
	idp[dp[0]] = id[0];
	for(int i = 1;i<n;i++){
	if(s[id[i]] == INF){
		le[id[i]] =INF;
		continue;
		}
		if(s[id[i]]>dp[len]){
			dp[++len] = s[id[i]];
            idp[dp[len]] = id[i];
			le[dp[len]] = len;
			//cout<<dp[len]<<" "<<idp[dp[len]]<<" "<<len<<endl;
			}
		else{
			int p = lower_bound(dp,dp+len+1,s[id[i]]) - dp;
			dp[p] = s[id[i]];
			idp[dp[p]] = id[i];
			le[dp[p]]  = p;
			//cout<<dp[p]<<" "<<idp[dp[p]]<<" "<<p<<endl;
		}

	}
	//cout<<len+ 1<<endl;
	printf("%d\n",len+1);
	cout<</*dp[len]<<" "<<le[dp[len]]<<" "<<*/idp[dp[len]]+1<<endl;
	printf("%d\n",idp[dp[len]]+1);
	int l = dp[len];
	for(int i = 1;i<=len;i++){
		for(int j = 0;j<n;j++){
			if(w[idp[l]]<w[j]&&le[s[j]] == le[l]-1&&s[j] < l){
				l = s[j];//cout<</*s[idp[l]]<<" "<<le[l]<<" "<<*/idp[l]+1<<endl;
				printf("%d\n",idp[l]+1);
				continue;
			}
		}
	}
	return 0;
}
