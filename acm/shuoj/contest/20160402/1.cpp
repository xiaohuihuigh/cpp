#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf  = 1000000;
int main(){
	int t;
	cin>>t;
	int ca = 1;
	while(t--){
	ll n;
	cin>>n;
	int x,y;
	int mix = inf,mai = -inf,miy = inf,may = -inf;
	int mixy = inf,maxy = -inf;
	for(int i = 0;i<n;i++){
		cin>>x>>y;
		mix = min(mix,x);
		mai = max(mai,x);
		miy = min(miy,y);
		may = max(may,y);
		mixy = min(mixy,x+y);
		maxy = max(maxy,x+y);
	}
	int t1 = mai - mix;
	int t2=  may - miy;
	int t3=  maxy - mixy;
	int tt = max(t1,max(t2,t3));
	int sum = 0;
	for(int i  = 1;i<=(tt+1)/2;i++){
		sum+= i*6;
	}
	sum+=1;
	cout<<"Case "<<ca++<<": "<<sum<<endl;
	}
}
