/**
高精度乘法
大数乘小数
*/
//计算1977阶乘，按照乘法竖式规则
#include<bits/stdc++.h>
using namespace std;
int a[10000];
int jin[10000];
int main(){
	memset(a,0,sizeof(a));
	int n ;
	n = 1977;
	//int jin = 0;
	a[1] = 1;int len = 1;
	for(int i  =1;i<=n;i++){
		for(int j = 1;j<=len;j++){
			jin[j] = a[j] * i;a[j] = 0;}
		memset(a,0,sizeof(a));
		for(int k = 1;k<=len;k++){
		int t = k-1;
		int jn = 0;
			while(jin[k]||jn){
				t++;
				a[t] += jin[k]%10+jn;
				jn = a[t]/10;
				a[t] %=10;
				jin[k]/=10;
				len = max(len,t);
			}
		}
	}
	for(int j = len;j>0;j--){
		cout<<a[j];
	}cout<<endl;

}
