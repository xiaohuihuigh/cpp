
#include<bits/stdc++.h>
using namespace std;

int main(){
    string a1,b1;
    while(cin>>a1>>b1){
        reverse(a1.begin(),a1.end());
        reverse(b1.begin(),b1.end());
        string a,b;
        string c = new char[105];
        cout<<sizeof(c);
        a = a1;
        b = b1;

        int al = a.size();
        int bl = b.size();
        //if(al == 2&&bl == 2&&a[0] == '0'&&b[0] == '0' ){cout<<"0+0=0"<<endl;continue;}
       // cout<<al<<" "<<bl;
       int jw = 0,i;
       for(i=0;i<al||i<bl;i++){
        if(i>=al&&i<bl){
            int ci = jw+b[i] - '0';
            jw = ci/8;
            ci = ci%8;
            c[i] = ci+'0';
        }
        else if(i>=bl&&i<al){
            int ci = jw+a[i] - '0';
            jw = ci/8;
            ci = ci%8;
            c[i] = ci+'0';
        }
        else{
            int ci = jw+b[i] +a[i]- '0' - '0';
            jw = ci/8;
            ci = ci%8;
            c[i] = ci+'0';
        }
       }
       if(jw == 1)
        c[i++] = jw+'0';
       reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        cout<<a<<"+"<<b<<"=";
       /* for(int j = i-1;j>=0;j--){
            cout<<c[j];
        }*/
        cout<<c;
        cout<<endl;
        }
    }
/**void shuchu(string c){
    int cl = c.size();
int yn = 1;
        for(int i= cl-1;i>=0;i--){

            if(c[i] == '0'){
                    if(yn  == 0)
                cout<<c[i];
            }
            if(c[i] != '0'){
                yn = 0;
                cout<<c[i];
            }

        }
}*/
