//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	int T;
//	cin>>T;
//
//	while(T--){
//		long long n;
////		cin>>n;
//		n = T;
//		n = n/2;
//		long long  sum = 0;
//		int gai = 0;
//		int ping = 0;
//		while(ping+n>=2||gai+n>=4){
//			sum+=n;
//			gai  += n;
//			ping +=n;
//			n = gai/4+ping /2;
//			gai = gai%4;
//			ping = ping %2;
//
//		}
//		sum+=n;
//		cout<<T<<" "<<sum<<endl;
//	}
//}


#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;

	while(T--){
		long long n;
		cin>>n;
		int sum = (n/2-1)*4-1;
		if(n<=1)sum = 0;
		if(n<=3&&n>1)sum = 1;

		cout<<sum<<endl;
		}

		}
