#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	double t = 100,sum = 0;
	for(int i = 1;i<=n;i++){
		sum+=2*t;
		t/=2;
	}

	printf("%.4lf\n",sum-100);
}
