
#include<bits/stdc++.h>
using namespace std;
int b[1005];
int j[1005];
int id[1005];
bool cmp(int x,int y){
    return j[x]>j[y]?1:0;
}
int main(){
    int n;
    int ca = 0;
    while(cin>>n&&n)
    {
        ca++;
        for(int i = 0;i < n;i++){
            cin>>b[i]>>j[i];
            id[i] = i;
        }
        sort(id,id+n,cmp);
        int sumb = 0, sum = 0;
        for(int i = 0;i<n;i++){
            sumb += b[id[i]];
            sum = max(sum,sumb+j[id[i]]);
        }
        cout<<"Case "<<ca<<": "<<sum<<endl;

    }
     return 0;
}
