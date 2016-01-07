/*#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[5];
int c[1000][2];
int main(){
	int n;
	while(cin>>n){
	memset(c,0,sizeof(c));
		for(int i = 0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		if(n == 1){cout<<a[0]<<endl;continue;}
		//if(n == 2){cout<<a[1]<<endl;continue;}
		int t = n;
		b[0] = a[0];
		b[1] = a[1];
		int m = 1;
		long long sum = 0;
		int cnt = 0;
		while(t>0){
		if(n>2&&t>2){
			if(m == 1){

		 	//	cout<<b[1]<<" "<<b[0]<<endl;
		 	//	cout<<b[0]<<endl;
				c[++cnt][0]= b[0];
				c[cnt][1] = b[1];
				c[++cnt][0] = b[0];
				sum += b[1]+b[0];
				t=t-1;
		 		m = 0;
			}
			else{


				c[++cnt][0]= a[n-2];
				c[cnt][1] = a[n-1];
				c[++cnt][0] = b[1];
			//	cout<<a[n-2]<<" "<<a[n-1]<<endl;
		 	//	cout<<b[1]<<endl;
		 		sum+= a[n-1]+b[1];
				n-=2;
				t-=1;
				m++;
			}
		}
		else{
		if(m == 1){
	//	cout<<b[1]<<" "<<b[0]<<endl;
				sum += b[1];
				m = 0;
				t-=2;
				c[++cnt][0]= b[0];
				c[cnt][1] = b[1];
			}
			else {
				sum+= a[n-1];
			//	cout<<a[0]<<" "<<a[n-1]<<endl;

				c[++cnt][0]= b[0];
				c[cnt][1] = a[n-1];
				n-=2;
				t-=2;
				m++;
			}
		}
		//cout<<sum<<endl;
		}
		cout<<sum<<endl;
		for(int i = 1;i<=cnt;i++){
		if(c[i][1] != 0)
			cout<<c[i][0]<<" "<<c[i][1]<<endl;
			else  cout<<c[i][0]<<endl;
		}
	}
}
*/
