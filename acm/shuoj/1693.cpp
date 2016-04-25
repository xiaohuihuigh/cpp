#include<bits/stdc++.h>
using namespace std;

bool que(int num){
    if(num <100 ){
        if(num  == 33 ||num == 44||num == 46||num == 58||num == 59||num == 63||num == 32||(num>=65&&num<=90)||num>=97)
        return 1;
    }
    if(num >=100&&num<=122)return 1;
    return 0;
}

int main(){
    int T;
    cin>>T;
    getchar();
    while(T--){
        string a;
        char s[1000];

        getline(cin,a);
        int l = a.size();
        int num1 = 0;
        int num2 = 0;
        int t = 0;
        if(a[0]>='0'&&a[0]<='9'){
            for(int i = 0;i<l;i++){
                num1 = (a[i] - '0') + (a[i+1] - '0')*10;
                num2 = (a[i] - '0') + (a[i+1] - '0')*10+(a[i+2] - '0')*100;
                if(que(num1))
                {
                    s[t++] = (char)num1;
                    i++;
                }
                else if(que(num2)){
                    s[t++] = (char)num2;
                    i+=2;
                }

            }
            for(int i = t-1;i>=0;i--){
                cout<<s[i];
            }
            cout<<endl;
        }

        else{
            for(int i = l-1;i>=0;i--){
            int num = a[i];
                while(num){
                    s[t++] = num%10+'0';
                    num/=10;
                }
            }
        for(int i = 0;i<t;i++){
                cout<<s[i];
            }
            cout<<endl;
        }


            //for()
    }
}
