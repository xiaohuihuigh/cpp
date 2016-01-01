//ax+by=c.cpp
/*ax+by=c的整数解算法 */
/*设t=gcd(a, b)，记a=mt，b=nt
求特解：求整系数方程ax+by=t的一个整数解x0，y0，
求一般解：若 t不是c的因数，则整系数方程ax+by=c无整数解；
若 t是c的因数，记c=gt，则整系数方程ax+by=c一般解为：
            x=gx0+bk,  y=gy0-ak,   k为任何整数
如果x1<=x<=x2&&y1<=y<=y2;
存在这样的x,y输出“have”反之“nothing”
*/
#include<iostream>
using namespace std;
int main()
{
	long long  a,b,c,x,y,x0,y0,x1,x2,y1,y2,kx1,kx2,ky1,ky2;
	while(cin>>a>>b>>c>>x1>>x2>>y1>>y2){
		long long t = extend_gcd(a,b,x0,y0);//拓展欧几里得
		if(c%t == 0){
			long long  g = c/t;
			long long m = a/t;
			long long n = b/t;
			kx1 = (x1- g*x0-1)/n;
			kx2 = (x2- g*x0+1)/n;
			ky2 = (y1- g*y0+1)/(-m);
			ky1 = (y2- g*y0-1)/(-m);
			for(int k  = kx1+1;k<kx2;k++)
				if(k>ky1&&k<ky2){
					cout<<"have"<<endl;
					x = g*x0+n*k;
					y = g*y0-m*k;
					cout<<x<<" "<<y<<endl;
                }
		}
		else cout<<"nothing"<<endl;
	}
}
