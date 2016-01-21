#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<cmath>
using namespace std;
int a[1005];
int m[1005][50];
void rmq_st(int n){
	for(int i = 1;i<=n;i++)
		m[i][0] = i;
	for(int j = 1;(1<<j)<=n;j++)
	for(int i = 1;i+(1<<j)-1<=n;i++)
		if(a[m[i][j-1]]<=a[m[i+(1<<(j-1))][j-1]])
			m[i][j] = m[i][j-1];
		else m[i][j] = m[i+(1<<(j-1))][j-1];
}
int rmq(int l,int r){
	int k = log(r-l+1.0)/log(2.0);
	return a[m[l][k]]<=a[m[r-(1<<k)+1][k]]? m[l][k]:m[r-(1<<k)+1][k];
}
int main(){
	char s[1000];
	while(~scanf("%s",s)){
		int n;
		scanf("%d",&n);
		int len =strlen(s);
		if(n>=len){printf("0\n");continue;}
		for(int i = 0;i<len;i++)
			a[i+1] = s[i]-'0';
		rmq_st(len);
		int l = 1,r = n+1;
		int yn = 1;
		for(int i = 1;i<=len-n;i++){
			//cout<<"l"<<l<<"r"<<r<<endl;
			int num =  rmq(l,r);
			if(i == len-n||a[num]!=0||yn == 0){
				printf("%d",a[num]);
				yn =0;
			}
			l = num+1;r++;
		}
		printf("\n");
	}
}
/*16541684689413251685143541321564123541354158745431 5*/
