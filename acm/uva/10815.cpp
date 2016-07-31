//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cctype>
//using namespace std;
//int main()
//{
//	string s;
//	vector<string> svec;
//	while(getline(cin,s))
//	{
//		int i;
//		for(i=0;i<(int)s.size();++i)
//		{
//			if(isupper(s[i]))
//				s[i]=s[i]-'A'+'a';
//		}
//		string::iterator begin=s.begin();
//		for(;begin!=s.end()&&!isalpha(*begin);++begin);
//		string::iterator end;
//		if(begin==s.end())
//			end=begin;
//		else
//			end=begin+1;
//		while(true)
//		{
//			if(begin==s.end())
//				break;
//			for(;end!=s.end()&&isalpha(*end);++end);
//			string str(begin,end);
//			vector<string>::iterator iter=find(svec.begin(),svec.end(),str);
//			if(iter==svec.end())
//				svec.push_back(str);
//			for(;end!=s.end()&&!isalpha(*end);++end);
//			begin=end;
//			if(end!=s.end())
//				++end;
//		}
//	}
//	sort(svec.begin(),svec.end());
//	vector<string>::iterator iter=svec.begin();
//	while(iter!=svec.end())
//		cout<<*iter++<<endl;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
#define XINF ll_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define repp(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define fors(i,s) for(auto i = (s).begin();i!=(s).end();i++)
#define all(s) (s).begin(),(s).end()
#define clr(A,X) memset(A,X,sizeof(A))
#define it iterator
#define lson l,m,((rt)<<1)
#define rson m+1,r,((rt)<<1|1)
#define in(x) scanf("%d",&x)
#define in2(x,y) scanf("%d%d",&x,&y)
#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define out1(x)  prllf("%lld\n",x)
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const int maxn = 55;
set<string> dict;
stringstream ss;
int main(){
    string s,buf;
    while(cin>>s){
        int len = s.size();
        rep(i,len){
            if(isalpha(s[i]))s[i] = tolower(s[i]);
            else s[i] = ' ';
        }
        ss.clear();
        ss.str(s);
        while(ss>>buf)dict.insert(buf);
    }
    for(set<string>::it i = dict.begin();i!=dict.end();i++){
        cout<<*i<<endl;
    }
}
