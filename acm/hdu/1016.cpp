#include<bits/stdc++.h>
using namespace std;
const int maxn = 25;
int prim_num[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
int num[maxn],a[maxn];
int n;

bool is_prime(int m){
    for (int i = 0;i<12;i++){
    	if(m == prim_num[i])return true;
    }
    return false;
}
void print(){
    for(int i = 1;i<=n;i++){
        i == 1?cout<<num[i]:cout<<" "<<num[i];
    }
    cout<<endl;
}
int dfs(int pre,int post,int flag){
    if(!is_prime(pre+post))return 0;
    num[flag] = post;
    if(flag == n && is_prime(post+1)){
        print();
        return 1;
    }
    a[post] = 0;
    for(int i = 2;i<=n;i++){
        if(a[i]!= 0&&dfs(post,i,flag+1))break;
    }
    a[post] = 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    int ca = 0;
    while(cin>>n){
        cout<<"Case "<<++ca<<":\n";
        for(int i = 1;i<=n;i++) a[i] = 1;
        num[1] = 1;
        if(n == 1){cout<<"1\n"<<endl;continue;}
        for(int i = 2;i<=n;i++)
            dfs(1,i,2);
            cout<<endl;
    }
}
