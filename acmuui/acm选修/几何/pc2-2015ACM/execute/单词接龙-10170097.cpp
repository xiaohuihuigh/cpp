#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

char s[30][300],head;
int glen[30][30],used[30];
int n,ans;
void LONG()
{
    memset(glen,0,sizeof(glen));
    int Min,pos,bk;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (strlen(s[i])<strlen(s[j])) Min=strlen(s[i]);
            else Min=strlen(s[j]);
            for (int k=1;k<=Min-1;k++)
            {
                bk=1;
                for (int t=1;t<=k;t++)
            if (s[j][t-1]!=s[i][strlen(s[i])-k+t-1])
                {
                   bk=0; break;
                    }
                if (bk)
                {
                    pos=k; break;
                }
            }
            if (bk) glen[i][j]=strlen(s[j])-pos;
            else glen[i][j]=0;
        }
}
void Search(int last,int len)
{
    if (len>ans) ans=len;
    for (int j=1;j<=n;j++)
        if (glen[last][j] && used[j]<2)
        {
            used[j]++;
            Search(j,len+glen[last][j]);
            used[j]--;
        }
}
int main()
{
    while(cin>>n)
	{cin.get();
    for (int i=1;i<=n;i++) cin.getline(s[i],30);

    cin>>head;
    LONG();
    ans=0;
    memset(used,0,sizeof(used));
    for (int i=1;i<=n;i++)
        if (s[i][0]==head)
        {
            used[i]=1;
            Search(i,strlen(s[i]));
            used[i]=0;
        }
   cout<<ans<<endl;
	}
    return 0;
}
