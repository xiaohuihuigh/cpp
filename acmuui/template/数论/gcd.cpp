//gcd.cpp
#include<iostream>
using namespace std;
int gcd(int a,int b) {
	int c;
	if(a ==0) return b;
   while(b!=0) c=b,b=a%b,a=c;
   return a;
}
//gcd.cpp
long long gcd(long long  a, long long b){
  if ((b==0)&(a==0)) //表示无最大公因数
       return -1;
  return b == 0?a:gcd(b, a%b);
}
//extend_gcd.cpp（非递归）
long long extend_gcd(long long a, long long b, long long &x, long long &y){
	long long  x0,x1,x2, y0,y1,y2;
	long long  r0,r1,r2, q;
	if((a== 0)&&(b==0)){
		x=0; y=0;
		return -1;
	}
	if((a== 0)&&(b!=0)){
		x = 0;  y = 1 ;
		return  b;
	}
if((b == 0) &&(a!=0)) {
		x = 1;  y = 0 ;
		return  a;
	}
	if((a!= 0) &&(b!=0)){
		x0=0; x1=1; r0= a;
		y0 = 1;  r1 = b;
		r2=r0 % r1;y1 =0- r0/r1;
		x2=1;	y2=y1;
while((r1%r2) != 0) {
			r0=r1;	r1=r2;
			q= r0/r1;
			x2=x0-x1*q;  y2=y0-y1*q;
			x0=x1;	x1=x2;  y0=y1; y1=y2;		r2=r0 % r1;
		}
		x = x2; y = y2;
		return r2;
	}
}
//extend_gcd.cpp（递归）
long long extend_gcd(long long a, long long b, long long &x,long long &y){
   long long t,m;
   if ((b==0)&(a==0)) return -1;
   if (b==0){
		x=1;y=0;
		return a;
   }
   else {
		m=extend_gcd(b,a % b,x,y);
		t=x;x=y;y=t-(a/b)*y;
   }
   return m;
}
int main()
{
	long long  a,b,x,y;
	while(cin>>a>>b){
		long long t1 = gcd(a,b);
		long long t2 = extend_gcd(a,b,x,y);
		cout<<t1<<" "<<x<<" "<<y<<endl;
	}
}
