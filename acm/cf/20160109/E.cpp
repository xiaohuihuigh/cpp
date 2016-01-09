#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin>>n;
	if(n == 0){cout<<"0 0"<<endl;return 0;}
	//int x,int y;
	//cout<<"n"<<n<<endl;
	ll nn =(n+5)/6;
	ll ns = sqrt(nn*2);
	while(ns*(ns+1)/2<nn)ns++;
	ns--;
//cout<<ns<<endl;//完整的层数
	ll cnt,bian,ge;
		 cnt = n-ns*(ns+1)/2*6-1;
		bian = cnt/(ns+1);
		ge = cnt%(ns+1);
	ll cx,cy;
	ll x,y;
	ge++;ns++;
	if(bian == 0){
	cx = 2*ns;cy = 0;
		x = cx-ge;
		y = cy+ge*2;
	}
	if(bian == 1){
		cx = ns,cy =2*ns;
		x = cx-ge*2;
		y = cy;
	}
	if(bian == 2){
		cx = -ns,cy =2*ns;
		x = cx-ge;
		y = cy-ge*2;
	}
	if(bian == 3){
		cx = -ns*2,cy =0;
		x = cx+ge;
		y = cy-ge*2;
	}
	if(bian == 4){
		cx = -ns,cy =-2*ns;
		x = cx+ge*2;
		y = cy;
	}
	if(bian == 5){
		cx = ns,cy =-2*ns;
		x = cx+ge;
		y = cy+ge*2;
	}
	cout<<x<<" "<<y<<endl;
}
