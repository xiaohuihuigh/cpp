
    #include <iostream>
    #include<cstring>
    #include <algorithm>
    #define INF 0x3f3f3f3f
    using namespace std;
    const int N = 1e5 + 5;
    int s[N];
    int n,p,a[N];
    int len;
    int main()
    {
      //  cin>>n;
        while(cin>>p){

            memset(s,0,sizeof(s));
            for(int i = 0;i<p;i++)cin>>a[i];
            s[1] = a[0];len = 1;//长度从1开始
            for(int i = 1;i<p;i++){

                int t = a[i];
                if(t>s[len])s[++len] = a[i];
                else{
            /*************/int l = 1,r = len,mid;//这里的二分法采用了左闭右闭的思路
int ans = 0;
                    while(l<=r)
                    {
                        mid = (l+r)/2;
                        if(s[mid]<t)
                            {l = mid +1;ans = max(ans,mid);}//ans即为思路中的j，j必然为s数组中小于t的最大的数
                        else r = mid-1;
                    }
                    s[ans+1] = t;/******************/
                }
            }
            //for(int i = 1;i<p;i++){cout<<s[i];}//有必要可以打开看看s中存的是什么值
            cout<<len<<endl;
        }
        return 0;
    }
