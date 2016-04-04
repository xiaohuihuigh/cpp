#include<bits/stdc++.h>
using namespace std;
int a[1050];
int b[1050];
int aa[1050];
const int INF = 11;
int main(){
	int n;int ca = 0;
	while(cin>>n&&n){
		ca++;
		for(int i = 0;i<n;i++){cin>>a[i];}
		cout<<"Game "<<ca<<":"<<endl;
		while(1){
			int c = 0,d = 0;aa[0] = a[0];
			for(int i = 0;i<n;i++){
				cin>>b[i];
				aa[i] = a[i];
				if(a[i] == b[i]){
					c++;
					aa[i] = INF;
					b[i] = INF;
				}
			}
			if(b[n-1] == 0)break;
			sort(aa,aa+n);
			sort(b,b+n);
			int j = 0,i;
			for(i = 0;i<n&&j<n;i++){
				if(aa[i] == INF||b[j] == INF)break;
				if(aa[i] == b[j]){d++;j++;continue;}
				if(aa[i]>b[j]){j++;i--;}
			}
			cout<<"    ("<<c<<","<<d<<")"<<endl;
		}
	}
}
