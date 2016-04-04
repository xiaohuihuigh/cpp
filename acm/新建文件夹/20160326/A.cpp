
#include<iostream>
using namespace std;
int m1[6050];
int m2[6050];
int f1[6050];
int f2[6050];
int main(){
	int n;
	while(cin>>n){
		char s;int a,b;
		int minn = 0x3f3f3f3f,maxn = 0;
		int mi = 0,fi = 0;
		for(int i = 0;i<n;i++){
			cin>>s>>a>>b;
			if(s == 'M'){m1[mi] = a;m2[mi++] = b;}
			else{f1[fi] = a;f2[fi++] = b;}
			minn = min(minn,a);
			maxn = max(maxn,b);
		}
		int ans = 0;
		for(int i = minn;i<=maxn;i++){
		int mt = 0;
			for(int j = 0;j<mi;j++){
				if(m1[j]<=i&&m2[j]>=i)mt++;
			}
			int ft = 0;
			for(int j = 0;j<fi;j++){
				if(f1[j]<=i&&f2[j]>=i)ft++;
			}
			ans = max(ans,2*min(mt,ft));
		}
		cout<<ans<<endl;
	}
	return 0;
}
