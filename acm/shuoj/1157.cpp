#include<bits/stdc++.h>
using namespace std;
int main(){
	char b;
	int a,c;
	while(~scanf("%d%c%d",&a,&b,&c)){
		int g = a;
		int d =c ;
		double e = (1.0*g)/d;
		cout<<".";
		for(int i = 0;i<10;i++){
			   e = 3*e;
			   int f = (int)e;
			   e = e-f;
			   if(i == 9){
				e = 3*e;
			   int t = (int)e;
				if(t == 2)f++;
			   }
			   cout<<f;
		}
		cout<<endl;
	}
}
