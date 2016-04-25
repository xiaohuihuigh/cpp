#include<iostream>
#include<algorithm>
using namespace std;

int nl[20005];
int zj[20005];

int main(){
    int n,m;
    while(cin>>n>>m&&n&&m){
        for(int i = 0;i<n;i++)
            cin>>zj[i];
        for(int i = 0;i<m;i++)
            cin>>nl[i];
        sort(zj,zj+n);
        sort(nl,nl+m);
        int  j = 0;
        int sum = 0;
        for(int i = 0;i<n;i ++){
            if(zj[i]<=nl[j++])
                sum += nl[j-1];
            else
                i--;
            if(j > m){
                cout<<"Loowater is doomed!"<<endl;
            goto DAS;
            }
        }
        cout<<sum<<endl;
        DAS:;
    }
    return 0;
}

