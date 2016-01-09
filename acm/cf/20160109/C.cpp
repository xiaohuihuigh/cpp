#include<bits/stdc++.h>
using namespace std;
int aa[27];
int bb[27];
int qi[2500];
int ho[2500];
int main(){
	string a,ar,b;
	cin>>a;
	cin>>b;
	ar = a;
	reverse(ar.begin(),ar.end());
	int al = a.size();
	int bl = b.size();
	for(int i = 0;i<al;i++)aa[a[i]-'a'] = 1;
	for(int i = 0;i<bl;i++)bb[b[i]-'a'] = 1;
	for(int i  = 0;i<26;i++){
		if(aa[i]==0&&bb[i]==1){cout<<"-1"<<endl;return 0;}
	}
	int ans = 0;
	for(int i = 0;i<bl;i++){
	int ma = 0,ma1=  0;
		for(int j = 0;j<al;j++){
			int ii = i;int cnt = 0;int yn = 0;int jj = j;
			while(b[ii] == a[jj]){ii++;jj++;cnt++;if(ii>=bl)break;if(jj>= al)break;yn = 1;}
			ma1 = max(ma,cnt);
			if(ma1 !=ma){qi[ans] = jj-ma1+1;ho[ans] = jj;}
			ma = ma1;
		}
		for(int j = 0;j<al;j++){
			int ii = i;int cnt = 0;int yn = 0;int jj = j;
			while(b[ii] == ar[jj]){ii++;jj++;cnt++;if(ii>=bl)break;if(jj>= al)break;yn = 1;}
			ma1 = max(ma,cnt);
			if(ma1 !=ma){qi[ans] = jj;ho[ans] = jj-ma1+1;}
			ma = ma1;
		}
		i+=ma-1;
		ans++;
	}
	cout<<ans<<endl;
	for(int i = 0;i<ans;i++){
		cout<<qi[i]<<" "<<ho[i]<<endl;
	}
	return 0;
}
