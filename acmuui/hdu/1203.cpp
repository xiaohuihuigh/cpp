///zhi neng yong scanf

#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 10005;
int w[maxn];
double v[maxn];
double dp[maxn];
int main (){
   // printf("灰灰我爱你（づ￣3￣）づ╭❤～");
	int m,n;
	while(scanf("%d%d",&m,&n)&&(n+m)){
		for(int i = 1;i <= n;i++){
			scanf("%d%lf",&w[i],&v[i]);
			v[i] = 1 - v[i];
			}
			for(int i = 0;i <= m;i++){dp[i] = 1;}
		for(int i = 1;i<= n;i++){
			for(int j = m;j >= w[i];j--){
				if(dp[j]>dp[j - w[i]] * v[i]){
                       // cout<<i<<" "<<j<<" "<<dp[j]<<endl;
					dp[j] = dp[j-w[i]]*v[i];
				}

			}
		}
		printf("%.1f%%\n",(1-dp[m])*100);
	}
	return 0;
}


