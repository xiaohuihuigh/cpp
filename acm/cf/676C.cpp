#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
int b[maxn];
int main(){
    ios::sync_with_stdio(false);
    int n,k;
    string s;
    while (cin>>n>>k){
    	cin>>s;
    	a[0] = 0,b[0] = 0;
    	for (int i = 0;i<n;i++){
    		if(s[i] == 'a'){
                a[i+1] = a[i]+1;
                b[i+1] = b[i];
    		}
    		else{
                b[i+1] = b[i]+1;
                a[i+1] = a[i];
    		}
    	}
//    	for (int i = 0;i<=n;i++){
//    		cout<<a[i]<<" ";
//    	}
//    	cout<<endl;
//    	for (int i = 0;i<=n;i++){
//    		cout<<b[i]<<" ";
//    	}
//    	cout<<endl;
    	int ans = 0;
    	for (int i = 0;i<n;i++){
    	    int l = i,r = n-1;
            while(l<r){
                int mid = (l+r-1)/2+1;
                if(a[mid+1] - a[i]<=k)l = mid;
                else r = mid-1;
    	    }
    	    ans = max(ans,l - i+1);
    	    l = i,r = n-1;
            while(l<r){
                //cout<<l<<" "<<r<<endl;
                int mid = (l+r-1)/2+1;
                if(b[mid+1] - b[i]<=k)l = mid;
                else r = mid-1;

    	    }
    	    ans = max(ans,l - i+1);
    	    //cout<<ans<<" "<<l<<" "<<i<<endl;
    	}
    	cout<<ans<<endl;
    }
}
