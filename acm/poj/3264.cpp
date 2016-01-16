#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int a[50005];
int ma[50005][50],mi[50005][50];
void rmq_st(int n){
	for(int i = 1;i<=n;i++)
		ma[i][0] = mi[i][0] = a[i];
	for(int j = 1;(1<<j)<=n;j++){
		for(int i = 1;i+(1<<j)-1<=n;i++){
				ma[i][j] = max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
				mi[i][j] = min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
		}
	}
}
int rmq(int l,int r){
	int k = log(r-l+1.0)/log(2.0);
	int ans1 = max(ma[l][k],ma[r-(1<<k)+1][k]);
	int ans2 = min(mi[l][k],mi[r-(1<<k)+1][k]);
	//cout<<ans1<<" "<<ans2<<endl;
	return ans1-ans2;
}
int main(){
	std::ios::sync_with_stdio(0);
	int n,q;
	while(~scanf("%d%d",&n,&q)){
		for(int i = 1;i<=n;i++)
			scanf("%d",&a[i]);
		rmq_st(n);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",rmq(l,r));
		}

	}
	return 0;
}
/*
7 3
1
7
3
4
2
5
8
1 5
4 6
2 2
*/
