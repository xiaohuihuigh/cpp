#include<bits/stdc++.h>
using namespace std;
int mt1[5][5];
int mt2[5][5];
int mt3[5][5];
void mutl(int m){
	for(int i = 1;i<=2;i++)
	for(int j = 1;j<=2;j++){
		mt3[i][j] = mt2[i][j];
		mt2[i][j] = 0;
		}
	for(int i = 1;i<=2;i++)
	for(int j = 1;j<=2;j++)
	for(int k = 1;k<=2;k++){
		mt2[i][j] = (mt2[i][j]+mt1[i][k]*mt3[k][j])%m;
		while(mt2[i][j]<0)mt2[i][j]+=m;
	}
}
void mut(int m){
	for(int i = 1;i<=2;i++)
	for(int j = 1;j<=2;j++){
		mt3[i][j] = mt1[i][j];
		mt1[i][j] = 0;
	//cout<<i<<" "<<j<<" "<<mt3[i][j]<<endl;
	}
	for(int i = 1;i<=2;i++)
	for(int j = 1;j<=2;j++)
	for(int k = 1;k<=2;k++){
		mt1[i][j] = (mt1[i][j]+mt3[i][k]*mt3[k][j])%m;
		while(mt1[i][j]<0)mt1[i][j]+=m;
		//cout<<i<<" "<<j<<" "<<mt1[i][j]<<endl;
		}
}
void fast_m(int n,int m){
	while(n){
		if(n&1) mutl(m);//ans = ans*s;
		mut(m);//s = s*s
		n>>=1;
	}
	//return ans;
}
int main(){
	int T;
	cin>>T;
	int ca = 1;
	while(T--){
		mt2[1][1] = 1;
		mt2[1][2] = 0;
		mt2[2][1] = 0;
		mt2[2][2] = 1;
		int n,m;
		cin>>n>>m;
		for(int i = 1;i<=2;i++)
		for(int j = 1;j<=2;j++){
			cin>>mt1[i][j];
		}
		fast_m(n,m);
		cout<<"Case "<<ca++<<":"<<endl;
		for(int i = 1;i<=2;i++){
			for(int j =1 ;j<=2;j++){
				if(j != 1)cout<<" ";
				cout<<mt2[i][j];
			}
			cout<<endl;
		}
	}
}
