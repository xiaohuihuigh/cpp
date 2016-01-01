#include<bits/stdc++.h>
using namespace std;
map<int,bool> maps;
int main(){
    int c[100000];
    char a ;

    while(cin.get()!= EOF){
            cin.unget();
    int i = 0;
    maps.clear();
        while((a = cin.get())!='\n')
    {
        cin.unget();
        cin>>c[i++];
        maps[c[i-1]] = 1;
    }
    for(int j = 0;j<i;j++){
        if(maps[c[j]] == 1){
                if(j != 0) cout<<" ";
            cout<<c[j];
            maps[c[j]] = 0;
        }
    }
    cout<<endl;
    }


}
