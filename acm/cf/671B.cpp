//以最大和最小值分别进行二分查找
//以进行的小于等于k次作为判断条件进行转移
//当采用结果为l时：
    //使用r = mid-1 形式，其中mid = (l+r-1)/2+1;
//当采用结果为r时：
    //使用l = mid+1形式，其中mid = (l+r)/2;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main(){
    ios::sync_with_stdio(false);
    int n,k;
    while (cin>>n>>k){
        ll sum = 0;
    	for (int i = 0;i<n;i++){
    		cin>>a[i];
    		sum+=a[i];
//    		cout<<sum<<endl;
    	}
    	sort(a,a+n);
    	int l1 = sum/n,r1 = (sum+n-1)/n;
//    	cout<<sum<<l1<<r1<<endl;
    	int l = 0,r = l1,ans1 = 0;
    	while (l<r){
    		int mid = (l+r-1)/2+1;
    		ll need = 0;
    		for (int i = 0;i<n;i++){
    			need+=max(0ll,mid - a[i]);
    		}
    		if(need<=k)ans1 = mid,l = mid;
    		else r = mid-1;
    	}
//    	cout<<r1<<endl;
    	l = r1,r = 1e9+10;
    	int ansr = 0;
    	while (l<r){
    		int mid = (l+r)/2;
    		ll need = 0;
    		for (int i = 0;i<n;i++){
    			need+=max(0ll,a[i] - mid);
    		}
    		if(need<=k)ansr = mid,r = mid;
    		else l = mid+1;
    	}
    	cout<<ansr - ans1<<endl;
    }
}
