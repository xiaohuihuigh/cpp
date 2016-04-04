#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	long long n;
	while(cin>>n){
		printf("%11lld-->",n);
		if(n<0){
			n = -n;printf("-");
		}
		if(n == 0){printf("0\n");continue;}
		int i = 0;
		while(n){
			a[i++] = n%2;
			n>>=1;
		}
		for(int j = i-1;j>=0;j--)printf("%d",a[j]);
		printf("\n");
	}
}
