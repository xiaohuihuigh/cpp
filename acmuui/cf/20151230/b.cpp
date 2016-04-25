#include<iostream>
using namespace std;
int a[100];
int b[100];
int main(){
    long long n,m;
    while(cin>>n>>m){
        int a0 = -1;
        int ai = 0;while(n){
        a[ai++] = n&1;n = n>>1;
        if(a[ai-1] == 0)a0 = ai-1;}
        int bt = 0;int b0 = -1;
        int bi = 0;while(m){
            b[bi++] = m&1;
            if(b[bi-1] == 0){bt++;b0 = bi-1;}
            m = m>>1;}
          //  cout<<ai<<bi<<bt<<endl;
        if(bt>=2){
            bt = 1;
            b[b0+1] = 0;b0 ++;
            if(b0+1 == bi){bi--;bt = 0;}
            for(int i = 0;i<=b0;i++)b[i] = 1;
        }int sum = 0;
        if(ai>bi){cout<<0<<endl;continue;}

        else if(bi>ai){

            sum += a0+1;
        //    cout<<sum<<"1"<<endl;
            ai++;
                while(bi>ai){
            sum += ai-1;
         //    cout<<sum<<"2"<<endl;
            ai++;
        }
        if(bt == 0){
            sum += ai-1;
          //  cout<<sum<<"3"<<endl;
        }
        else{
            sum += bi - b0-1;
         //    cout<<sum<<"4"<<endl;
        }
            }
            else{
                if(bt == 0){
                    sum += a0+1;
            //        cout<<sum<<"5"<<endl;
                }
                else{
                    sum += a0-b0+1;
            //        cout<<sum<<"6"<<endl;
                }
            }

        cout<<sum<<endl;

    }
}
