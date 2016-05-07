#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long
#define in(x) scanf("%d",&x)
#define in2(x,y) scanf("%d%d",&x,&y)
#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define out1(x)  printf("%d\n",x)
const int maxn = 200000;
int h,w,n;
ll maxx[maxn<<2];
void pushup(int rt){
	maxx[rt] = max(maxx[rt<<1],maxx[rt<<1|1]);
}
void build(int v,int l,int r,int rt){
	if(l>r)return;
	if(l == r){
		maxx[rt] = v;
		return ;
	}
	int m = (l+r)>>1;
	build(v,lson);
	build(v,rson);
	pushup(rt);
}
void update(int v,int l,int r,int rt){
	//if(l>r)return;
	if(l == r){
	if(maxx[rt]>=v){
		maxx[rt]-=v;
		out1(l);
		return;}
	else{cout<<"-1"<<endl;return;}
	}

	int m = (l+r)>>1;
	if(maxx[rt<<1]>=v)update(v,lson);
	else update(v,rson);
	pushup(rt);
}
int main(){

	while(~in3(h,w,n)){
		if(h>n)h = n;
		build(w,1,h,1);
		/*for(int i = 1;i<=2*h-1;i++){
			cout<<maxx[i]<<" ";
		}
		cout<<endl;*/
		while(n--){
			int w;
			in(w);
			update(w,1,h,1);
			/*for(int i = 1;i<=2*h-1;i++){
			cout<<maxx[i]<<" ";
		}
		//cout<<endl;*/
		}
	}
}
