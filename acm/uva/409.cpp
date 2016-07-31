#include<bits/stdc++.h>
using namespace std;
#define XINF ll_MAX
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define repp(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define fors(i,s) for(auto i = (s).begin();i!=(s).end();i++)
#define all(s) (s).begin(),(s).end()
#define clr(A,X) memset(A,X,sizeof(A))
#define it iterator
#define lson l,m,((rt)<<1)
#define rson m+1,r,((rt)<<1|1)
#define in(x) scanf("%d",&x)
#define in2(x,y) scanf("%d%d",&x,&y)
#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define out1(x)  prllf("%lld\n",x)
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const int maxn = 55;
stringstream ss;
char buf[maxn];
int main()
{
	int m,n,i,j,num[20],max,t=1,a,k,len;
	char one[20][20],two[20][71],three[20][71],temp[71];
	while(scanf("%d%d",&m,&n) == 2)
	{
		for(i=0; i<m; i++)
			scanf("%s",one[i]);
        getchar();
		for(i=0; i<n; i++)
		{
			num[i] = 0;
			gets(two[i]);
			len=strlen(two[i]);
			strcpy(three[i],two[i]);
			rep(j,len){
                if(isalpha(three[i][j]))three[i][j] = tolower(three[i][j]);
                else three[i][j] = ' ';
            }
            ss.clear();
            ss.str(three[i]);
            while(ss>>buf){

                for(k=0; k<m; k++)
                    if(strcmp(buf,one[k])==0)
                    {
                        num[i]++;
                        break;
                    }
            }
		}
		max = 0;
		for(i = 0; i< n; i++)
		{
			if(max < num[i])
				max = num[i];
		}
		printf("Excuse Set #%d\n",t++);
		for(i=0; i<n; i++)
		{
			if(num[i]==max)
				printf("%s\n",two[i]);
		}
		printf("\n");
	}
	return 0;
}
