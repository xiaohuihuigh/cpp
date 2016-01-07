#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	double sum = 0;
	for(int i = 1;i<=n;i++){
		double t = i;
		sum+=1.0/i;
	}
	printf("%.6lf\n",sum);
}
