#include<iostream>
#include<cmath>
using namespace std;
/*
c为图色颜色数，n为几边行
*/
const int MAXN = 50000;
int perm[ MAXN];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int cycle(int* perm,int n,int& repetend){
	int i,j,p,v[MAXN]={0},ret=1;
	for (repetend=i=0;i<n;i++)
		if (!v[i]){
			repetend++;p=i;
			for (j=0;!v[perm[p]];j++){
				p=perm[p];
				v[p]=1;
			}
			ret*=j/gcd(ret,j);
		}
	return ret;
}
double polya(int c,int n){	//旋转和翻转下视为相同
	int i,j,x;double t=0.0,m=c;//c为颜色数
	for (i=0;i<=n-1;i++){	//构造第i个旋转，0->i
		for (j=0;j<=n-1;j++)
			perm[j]=(i+j)%n;
		cycle(perm, n, x);
		t=t+pow(m,x);
	}
	if(n%2==1)    		//构造第i个翻转
		for (i=0;i<=n-1;i++){	//i保持不动
			for (j=0;j<=n-1;j++)
				perm[(i+j)%n]=(i-j+n)%n;
			cycle(perm, n, x);
			t=t+pow(m,x);
		}
		if(n%2==0)
		for (i=0;i<(n/2);i++){		//构造第i个翻转
			for (j=0;j<=n-1;j++)	//i保持不动，共n/2个
				perm[(i+j)%n]=(i-j+n)%n;
			cycle(perm, n, x);
			t=t+pow(m,x);//可能需要高精度计算
			for (j=0;j<=n-1;j++)
					//ii+1，i-1i+2，…，共n/2个
				perm[(i-j+n)%n]=(i+j+1)%n;
			cycle(perm, n, x);
			t=t+pow(m,x);
		}
	return t/(2*n);
}
int main(){
int c,n;
while(cin>>c>>n){
int ans = 0;
for(int i = 1;i<=c;i++)
    ans+=polya(i,n);
cout<<ans<<endl;
}
return 0;
}
