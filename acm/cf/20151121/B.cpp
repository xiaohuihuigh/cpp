#include<bits/stdc++.h>
using namespace std;

int f[100005];
int b[100005];
int i1[100005];
int i2[100005];
int a[100005];

bool cmp1(int x,int y){
    return f[x]<f[y]?1:0;
}
bool cmp2(int x,int y){
    return b[x]<b[y]?1:0;
}
int main(){
    int n,m;
    while(cin>>n>>m)
    {
        for(int i = 0;i<n;i++){
            i1[i] = i;
            cin>>f[i];
        }
        for(int i = 0;i<m;i++){
            i2[i] = i;
            cin>>b[i];
        }
        sort(i1,i1+n,cmp1);
        sort(i2,i2+m,cmp2);
        /*for(int i = 0;i<m;i++){
            cout<<b[i2[i]];
        }*/
        int j = 0;int yn = 0;int yna = 0;
        for(int i = 0;i<n;i++){
            if(b[i2[j]] != f[i1[i]])continue;
            else{
                a[i2[j]] = i1[i];
                if(i<n-1&&f[i1[i]] == f[i1[i+1]])yna = 1;
                j++;
            }
        }
        if(j<m-1) cout<<"Impossible"<<endl;
        else if(yna == 1)cout<<"Ambiguity"<<endl;
        else{
            cout<<"Possible"<<endl;
            for(int i = 0;i<m;i++){
                cout<<a[i]+1<<" ";
            }
            cout<<endl;
        }
    }
}
