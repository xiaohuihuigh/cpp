#include<bits/stdc++.h>
using namespace std;
int b[205][305];
int main()
{
    int a[305];

    int n;
    cin>>n;
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=n+1;i<=2*n;++i)a[i]=a[i-n];
    int ans=0;
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=2*n-1;++j)
        {
            for(int k=j+1;k<i+j;++k)
            {
                b[j][i+j]=max(b[j][i+j],b[j][k]+b[k][i+j]+a[j]*a[k]*a[i+j]);


            }
            //cout<<"j i+j  "<<j<<' '<<i+j<<' '<<b[j][i+j]<<endl;
        }
        for(int i=1;i<=n;++i)ans=max(ans,b[i][i+n]);
    }
    cout<<ans<<endl;
    return 0;
}
