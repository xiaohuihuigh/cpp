#include<bits/stdc++.h>
using namespace std;
int s=0,r=0,jishu=0;
int sushu(int a);
void zuhe(int* a,int k,int n)
{
	if(k==0){
		if(sushu(s)){
		// printf("%d\n",s);
		jishu++;
		}
	}
	else{
		for(int i=r;i<n;i++){
			r=i+1;
			s+=a[i];
			zuhe(a,k-1,n);
			s-=a[i];
			r=0;
		}
	}
}
int sushu(int a){
	 if(a==0)return 0;
	 for(int i=2;i<=sqrt(a);i++)
	 if(a%i==0)return 0;
	 return 1;
}
int main()
{
	 int n=0,k=1;
	 //printf("%d",sushu(11));
	// printf("输入数组大小n组和数k\n");
	while(cin>>n>>k){
	s=0,r=0,jishu=0;
		 int *a=(int*)malloc(n*sizeof(int));
		 for(int i=0;i<n;i++)cin>>a[i];
		 zuhe(a,k,n);
		 cout<<jishu<<endl;
	}


	 return 0;
}
