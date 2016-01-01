#include<bits/stdc++.h>
using namespace std;

#define A1
#ifndef A1
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    printf("%.3f\n",(double)(a+b+c)/3);
    return 0;
}
#endif // 1


#define A2
#ifndef A2
int main(){
    double c;
    cin>>c;
    printf("%.3f\n",5*(c - 32)/9);
    return 0;
}
#endif // 2


#define A3
#ifndef A3
int main(){
    int n;
    cin>>n;
    printf("%d\n",(n+1)*n/2);
    return 0;
}
#endif // 3


#define A4
#ifndef A4
int main(){
    int n;
    cin>>n;
    printf("sin = %f,cos = %f\n",sin(n),cos(n));
    return 0;
}
#endif // 4

#define A5
#ifndef A5
int main(){
    int n;
    cin>>n;
    printf("sin = %f,cos = %f\n",sin(n),cos(n));
    return 0;
}
#endif //5

#define A6
#ifndef A6
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int maxn;
    maxn = a>b?a:b;
    maxn= maxn>c?maxn:c;

    if(a+b>maxn&&a+c>maxn&&b+c>maxn)cout<<"yes"<<endl;
    else cout<<"no"<<endl;

    return 0;
}
#endif //6


#define A7
#ifndef A7
int main(){
    int n;
    cin>>n;
    if(n%400 == 0||(n%100 != 0 &&n%4 == 0))cout<<"yes"<<endl;
    else cout<<"no"<<endl;

    return 0;
}
#endif //7


