#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int main(){
	int n,m;
	while(cin>>n>>m){
            memset(b,0,sizeof(b));
    for(int i = 1;i<= n;i++){
        cin>>a[i];
    }
    int jishu = 0;int jici = 0;
    while(1){
        for(int i= 1;i<=n;i++){
            if(b[i] == 0)
                jishu ++;
            if(jishu == m){
                b[i] = 1;
                m = a[i];
                jishu =0;
                jici++;
               // cout<<i<<endl;
            }
            if(jici == n)
            {cout<<i<<endl;goto END;}
        }
	}
	END:;
	}
	return 0;
}
/*
7 20
3 1 7 2 4 8 4
*/
