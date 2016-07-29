

#include<bits/stdc++.h>
using namespace std;
const int maxn = 500050;
int a[maxn];
//int main(){
//    int T;
//    cin>>T;
//    while(T--){
//        int n;
//        cin>>n;
//        for(int i = 0;i<n;i++){
//            cin>>a[i];
//        }
//    }
//}
double x[maxn];
double y[maxn];
int c[maxn];
int main(){
    int n,k;
    while(cin>>n>>k){
        for(int i = 0;i<n;i++){
            cin>>c[i];
        }
        sort(c,c+n);
        int a = 1,b = 1;
        int chax = 0,chad = 0;
        int x,y;
        x = 0;y = n-1;
        while(k>0){
            for(int i = x+1;i<n;i++){
                if(c[i] == c[x]){
                    a++;
                }
                else{
                    x = i-1;
                    chax = c[i] - c[i-1];
                    break;
                }
            }
            for(int i = y-1;i>=0;i++){
                if(c[i] == c[y]){
                    b++;
                }
                else{
                    y = i+1;
                    chad = c[y] - c[i];
                    break;
                }
            }
            int zx = a*chax;
            int zd = b*chad;
            if(zx>zd){

            }
            else{
                k-=zx;

            }
        }

    }
}
