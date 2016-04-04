#include<bits/stdc++.h>
using namespace std;
double a0,a1;
double c[3005];
int main(){
	int n;
	cin>>n>>a0>>a1;
	for(int i = 1;i<=n;i++)cin>>c[i];
	double sum = 0,ant = 0;
	for(int i = 1;i<=n;i++){
		ant = ant+2*c[i];
		sum = sum + ant;
	}
	printf("%.2lf\n",( a1-sum-a0)/(n+1)+a0);

}
