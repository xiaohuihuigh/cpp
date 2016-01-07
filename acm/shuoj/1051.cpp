/*#include<bits/stdc++.h>
using namespace std;*/
/*
这道题竟然是动态规划的问题
本来是当一道贪心题做的
f[i] = max(f[i-1]+17,t[i])
t[i]是仅使用法力进行移动的距离
f[i]是使用法力和直接奔跑最远的距离
（因为只是用奔跑是不可能最快的，所以直接忽略）
*//*
int main(){
	int m,s,t;
	cin>>m>>s>>t;
	int d1  = 0,d2 = 0;int i = 1;
	for(i = 1;i<=t;i++){
		if(m>=10)
			{d1+=60;m-=10;}
		else m+=4;
		if(d1>=d2+17)d2 = d1;
		else d2+=17;
		if(d2>=s)break;
	}
	if(i>t)cout<<"No"<<endl<<d2<<endl;
	else cout<<"Yes"<<endl<<i<<endl;
}*//*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int M,S,T;
    cin>>M>>S>>T;
    int m = M,s = S,t = T;
    while(s&&t){
        if(m>=10){m-=10;s-=60;t-=1;continue;}
        if(s<=17||t<=1){s-=17;t-=1;continue;}
        if(m>=6){s-=60;t-=2;m = m+4-10;continue;}
        if(s<=34||t<=2){s-=34;t-=2;continue;}
        if(m>=2){s-=60;t-=3;m = m+8-10;continue;}
        if(s<=102||t<=6){
            if(s<=102){
                t -= 1+(s-1)/17;
                s-=102;continue;
            }
            else{
                s -= t*17;
                t-=6;continue;
            }
        }
        s-=120;t-=7;
    }
    if(s<=0)cout<<"Yes"<<endl<<T-t<<endl;
    else cout<<"No"<<endl<<S-s<<endl;
}*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int M,S,T;
    cin>>M>>S>>T;
    int m = M,s = S,t = T;
    while(s>0&&t>0){
        if(m>=10){m-=10;s-=60;t-=1;continue;}
        if(s<=17||t<=1){s-=17;t-=1;continue;}
        if(m>=6){s-=60;t-=2;m = m+4-10;continue;}
        if(s<=34||t<=2){s-=34;t-=2;continue;}
        if(m>=2){s-=60;t-=3;m = m+8-10;continue;}
         if(s<=51||t<=3){s-=51;t-=3;continue;}
          if(s<=68||t<=4){s-=68;t-=4;continue;}
           if(s<=85||t<=5){s-=85;t-=5;continue;}
           if(s<=102||t<=6){s-=102;t-=6;continue;}
        s-=120;t-=7;
    }
    if(s<=0)cout<<"Yes"<<endl<<T-t<<endl;
    else cout<<"No"<<endl<<S-s<<endl;
}



















