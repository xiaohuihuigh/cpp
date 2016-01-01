//#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define LOCAL/*
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;*//
const int maxn = 200010;
int Next[maxn];
void getNext(string a){
	int i = 0;int j = -1;
	Next[0] = -1;
		while(i<a.size()){
		if(j == -1||a[i] == a[j]){
			Next[++i] = ++j;
		}
		else j = Next[j];
		}
}/*
int kmp(string a,string b){
	int i = 1;int j = 0;
	getNext(a);
	while(i<a.size()){
		if(j == -1||a[j]  == b[i]){
			i++;j++;
		}
		else {ans += j+1;j = Next[j];}
		if(j == a.size()){
			j = Next[j];
		}
		return ans+j+1;
	}
}
*/
int main(){
    /*
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif */
	string a;
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cin>>a;
		int ans = 0;
		getNext(a);
		for(int i = 1;i<=n;i++){
            if(Next[i] != 0)
            {ans++;

            ans %=10007;
            }
		}
		ans =(ans+n)%10007;
		cout<<ans<<endl;

	}

   //printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC);

}
