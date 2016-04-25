#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 2005;
int next2[maxn];
int ans[maxn];
string s[505];
void getnext2(string a)
{
    int i = 0;int j = -1;
    next2[0] = -1;
    while(i<a.length()){
        if(j == -1||a[i] == a[j])
        {
            i++;j++;
            next2[i] = j;
        }
        else
            j = next2[j];
    }
}
int kmp(string a,string b){
    getnext2(a);
    int ans = 0;
    int al = a.size();
    int bl = b.size();
    //cout<<b<<endl;
    int i = 0;int j = 0;
    while(i<bl){
        if(j == -1||a[j] == b[i]){
            //cout<<i<<" "<<j<<a[j]<<b[i]<<endl;
            i++;j++;

        }
        else{
            j = next2[j];
        }
         //ans = max(ans,j);
        if(j == al)
            return 1;
    }
    return 0;
}


int main(){
    std::ios::sync_with_stdio(0);
    int T;
    cin>>T;
    int ca = 0;
    while(T--){
        int n;
       // string a[3];
        int yn  =0;
        cin>>n;
        int j = 0;
        string ss;
        for(int i = 1;i<=n;i++){
                //if(yn){cin>>a[i&1];continue;}
                cin>>ss;
                s[j] =ss;
                int m = 0;
               for(int k = 0;k<=j;k++){
                    if(!kmp(s[k],ss))
                        {
                            s[m++] = s[k];
                            yn = i;
                        }
               }
                s[m++] = ss;
                j = m;
            }

        cout<<"Case #"<<++ca<<": ";
        if(yn)cout<<yn<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}












