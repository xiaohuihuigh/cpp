#include<bits/stdc++.h>
using namespace std;
struct  node{
	int a,b,c;
};
node G[1040];
int aa[1040];
bool cmp(node x,node y){
	return x.a<y.a?1:0;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i = 0;i<k;i++){
			cin>>G[i].a>>G[i].b;
			G[i].c = 0;
		}
		sort(G,G+k,cmp);
		for(int i = 0;i<k;i++){
			aa[i]  = G[i].a;
		}
		int yn = 0;int s = 1;
		while(1){
			int p = lower_bound(aa,aa+k,s)-aa;
			//cout<<s<<" "<<p<<endl;
			if(p >=k &&n>=G[k-1].a){yn = 2;break;}
			if(s<=n&&n<=G[p].a){yn = 2;break;}
			if(G[p].c == 1){yn = 1;break;}
			s = G[p].b;
			G[p].c = 1;
		}
		if(yn == 1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}














