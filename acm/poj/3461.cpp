    #include<iostream>
    #include<string>
    #include<cstdio>
    using namespace std;

    int next[10005];
    string  w;
    string t;
    int wss,ts;
    void getnext(){
        int i = 0;int j = -1;
        next[i] = j;
        //cout<<j;
        while(i<wss){
               // cout<<i<<endl;
                if(j==-1||w[i] == w[j]){
                        ++i;++j;
                 /*   if(w[i] == w[j])
                        next[i] = next[j];*/
                  /*  else*/ next[i] = j;
                }
                else
                    j = next[j];
             //   cout<<i<<endl;
            //while(j!=-1&&w[i] != w[j])j = next[j];
            //if(w[++i] == w[++j]) next[i] = next[j];
            //else next[i] = j;
        }
    }

    int kmp(){
        int ans = 0;
        int i = 0;int j = 0;
        getnext();
        while(i<ts){
                if(j == -1||t[i] == w[j]) {i++;j++;}
                else j = next[j];
           /* while(j!=-1&&t[i] != w[j])j = next[j];
            i++;j++;*/
            //cout<<j<<endl;
            if(j >= wss){
                    //cout<<"adfba"<<endl;
                ans++;
                j = next[j];
            }
        }
        return ans;
    }
    int main(){
        std::ios::sync_with_stdio(false);
        int T;
        cin>>T;
        //cout<<getchar();
        //getchar();
        while(T--){
       cin>>w;
       cin>>t;
            wss =w.size();ts = t.size();
           int ans = kmp();
            cout<<ans<<endl;

        }

        return 0;
    }














