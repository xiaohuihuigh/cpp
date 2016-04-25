#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int s[100005];
vector<pair<int,int> > T;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(s,0,sizeof(s));
        T.clear();
        for(int i = 0;i<n;i++)scanf("%d",&a[i]);
        for(int i = 0;i<n;i++)scanf("%d",&b[i]);
            //    for(int i = 0;i<n;i++)cout<<b[i];

        for(int i = 0;i<n;i++)T.push_back(make_pair(a[i],b[i]));
       // for(int i= 0;i<n;i++)cout<<T[i].second;
        std::sort(T.begin(),T.end());
       // for(int i = 0;i<n;i++)cout<<a[i];
        for(int i= 0;i<n;i++)a[i] = T[i].second;
        reverse(a,a+n);
       /*  for(int i = 0;i<n/2;i++)
         {
             int t;
             t = a[i];
             a[i] = a[n-1-i];
             a[n-1-i] = t;
         }*/
         // for(int i = 0;i<n;i++)cout<<a[i];
        int len = 1;
        s[1] = a[0];
        for(int i = 1;i<n;i++)
        {
            int t = a[i];
            if(t>s[len])
                s[++len] = a[i];
            else{
                int l = 1,r = len,mid;
                int ans = 0;
                while(l<=r)
                {
                    mid = (r+l)/2;
                    if(s[mid]<t){
                        l = mid+1;
                        ans=max(ans, mid);
                    }
                    else r = mid-1;
                }
                s[ans+1] = t;
            }
        }
    /* for(int i= 0;i<n+8;i++)cout<<s[i];*/
        printf("%d\n",len);
    }
    return 0;
}

/**************************************************************
    Problem: 1936
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:1272 ms
    Memory:4284 kb
****************************************************************/
