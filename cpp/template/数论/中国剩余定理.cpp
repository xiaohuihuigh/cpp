//中国剩余定理.cpp
/*设 m1，m2,m3...mn是两两互素的n个正整数，
记m = m1m2m3...mn ，Mi = n/mi
，1≤i≤n，那么，下列模线性方程组
x === b1(mod m1)
x === b2(mod m2)
    ...
x === bn(mod mn)
的解为x0 = (b1m1y1+b2m2y2+...+bnmnyn)，
其中yi 是Miyi ===1(mod mi) 的解，i=1，2，3，…，n
*/
#include<iostream>
using namespace std;
const int maxn = 1000;
long long m[maxn];
long long b[maxn];
long long ChinaRemainder(int n,long long  m0[], long long  b[]){
	long long d,x,y,t,m=1,a=0,Mi;
	int  i;
	for (i=0; i< n ; i++)  m=m*m0[i];
	for (i=0; i< n ; i++) {
		Mi=m / m0[i];
		extend_gcd(Mi, m0[i], x, y); //求逆元拓展欧几里得
        //或x=mod_reverse(MM, m0[i]);
		a=(a+Mi*x*b[i]) % m;
	}
	while(a<0)a = a+m;
	return a;
}
int main(){
    int n;
    while(cin>>n){
        for(int i = 0;i<n;i++)
            cin>>b[i]>>m[i];
        cout<<ChinaRemainder(n,m,b)<<endl;
    }
}
