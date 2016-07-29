#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
struct haha
{
    int pos;
    int val;
}temp,q;
vector<struct haha>a[44444];
int n,m,flag,e,vis[444444];
void DFS(int s,int ans)
{
    //printf("s=%d\n",s);
    int size,i;
    if(vis[s]) return ;
    if(flag) return ;
    if(s==e) {printf("%d\n",ans);flag=1;return;}
     if(a[s].empty())  return ;
     else
     {
    vis[s]=1;
     size=a[s].size();
     for(i=0;i<size;i++)
        DFS(a[s][i].pos,ans+a[s][i].val);
     vis[s]=0;
     }
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        int i,j,x,y,z;
        scanf("%d %d",&n,&m);
        for(i=0;i<n-1;i++)
        {
                scanf("%d %d %d",&x,&y,&z);
                q.pos=y;q.val=z;
                a[x].push_back(q);
                q.pos=x;q.val=z;
                a[y].push_back(q);
        }
        for(j=0;j<m;j++)
        {
            memset(vis,0,sizeof(vis));
            flag=0;
            int s;
            scanf("%d %d",&s,&e);
            DFS(s,0);
        }
        for(i=0;i<n;i++)
        {
            a[i].clear();
        }
    }
      return 0;
}
