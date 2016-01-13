//行列分开求，否则会因为行列之间相互关联，无法快速求解
#include<bits/stdc++.h>
using namespace std;
const int maxn = 550;
char s[maxn][maxn];
int ha[maxn][maxn];
int li[maxn][maxn];

int main(){
	int h,w;
	cin>>h>>w;getchar();
	memset(s,'#',sizeof(s));
	memset(ha,0,sizeof(ha));
	memset(li,0,sizeof(li));
	for(int i= 1;i<=h;i++){
		for (int j=1;j<=w;j++)
		cin>>s[i][j];
	}
	for(int i = 1;i<=h;i++){
		for(int j = 1;j<=w;j++){
			ha[i][j] = ha[i][j-1]+ha[i-1][j]-ha[i-1][j-1];
			if(s[i][j] == '.'&&s[i][j-1] == '.')ha[i][j]++;
			li[i][j] = li[i-1][j]+li[i][j-1]-li[i-1][j-1];
			if(s[i][j] == '.'&&s[i-1][j] == '.')li[i][j]++;
		}
	}
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int sum = 0;
		//求行和列的总和是，注意减去的部分和加上的部分
		sum += ha[c][d]-ha[c][b]-ha[a-1][d]+ha[a-1][b];
		sum += li[c][d]-li[c][b-1]-li[a][d]+li[a][b-1];
		cout<<sum<<endl;
	}
}




