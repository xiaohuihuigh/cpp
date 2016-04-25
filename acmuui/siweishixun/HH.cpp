#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
double a[100000];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int c = 0;c<n;c++)
        {
            cin>>a[c];
        }
        sort(a,a+n);
        printf("%.2llf,",a[0]);
        printf("%.2llf,",a[n-1]);
        double average = 0;
        for(int c = 1;c<n-1;c++)
        {
            average += a[c];
        }
        average /= (n-2);
        printf("%.2llf",average);
        cout<<endl;
    }
}
