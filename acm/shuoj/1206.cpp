#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int ,pair<int ,int> > >v;
    int mon,day,year;
    char c;
    v.clear();
    while(cin>>mon>>c>>day>>c>>year){
        v.push_back(make_pair(year,make_pair(mon,day)));
    }
    sort(v.begin(),v.end());
    int l = v.size();
    for(int i = 0;i<l;i++){
            if(v[i].second.first<10)
                cout<<"0"<<v[i].second.first;
            else
                cout<<v[i].second.first;
            cout<<"/";
            if(v[i].second.second<10)
                cout<<"0"<<v[i].second.second;
            else
                cout<<v[i].second.second;
            cout<<"/";
            if(v[i].first<10)
                cout<<"000";
            else if(v[i].first<100)
                cout<<"00";
            else if(v[i].first<1000)
                cout<<"0";
            cout<<v[i].first<<endl;
    }

}
