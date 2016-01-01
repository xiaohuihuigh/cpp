#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int>Map;
    int a[50000];
    int i = 0;
    while(cin>>a[i++]){
        if(Map.count(a[i-1]))
        Map[a[i-1]]++;
    else Map[a[i-1]] = 0;

    };
    int ma = 0;
     for(int j = 0;j<i;j++){
        ma = max(ma,Map[a[j]]);
    }
    for(map<int,int>::iterator iter = Map.begin();iter != Map.end();++iter){
        //cout << iter->first << " " << iter->second << endl;
        ma = max(ma,Map[iter->first]);
    }//Map.iterator a = Map.begin();
 for(map<int,int>::iterator iter = Map.begin();iter != Map.end();++iter){
        //cout << iter->first << " " << iter->second << endl;
        if(ma == iter->second){
            cout<<iter->first<<endl;
        }
    }
}
