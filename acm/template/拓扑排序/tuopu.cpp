#include<bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define lson ((rt)<<1),l,m
#define rson ((rt)<<1|1),m+1,r
#define ls(t) ((t)<<1)
#define rs(t) ((t)<<1|1)
#define in(x) scanf("%d",&x)
#define in2(x,y) scanf("%d%d",&x,&y)
#define in3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define out1(x)  printf("%d\n",x)

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int maxn = 100010;
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<PII,int>PPI;

//队列版 复杂度O(n+m),一般应用，能判断有无环/*hdu3342*/
int n,m;
int ans;//已经出来的节点
int deg[maxn];//入度
int Ans[maxn];//记录的路径或其他内容
vector<int> G[maxn];//存图

void addedge(int u,int v){
    G[u].PB(v);
	deg[v]++;
}

void init(int n){
	memset(deg,0,sizeof(deg));
	memset(Ans,0,sizeof(Ans));
    for(int i=0;i<=n;i++){
        G[i].clear();
    }
}

void toposort(int n) {//拓扑排序
	queue<int> Q;
    ans= 0;
	int k = 0;//记录路径
	for (int i = 0; i < n; i++) {
		 if (deg[i] == 0) {//找到
			Q.push(i);
		 }
	}
	while(!Q.empty()){
		int top = Q.front();Q.pop();
		ans++;
		Ans[k++] = top;
		deg[top]--;
		for (int j = 0; j < G[top].size(); j++){//遍历所有的点
			int t = G[top][j];
			deg[t]--;//让这个点的入度-1
		if(deg[t] == 0)
			Q.push(t);
		}
	}
}


int main()
{
	while(cin>>n>>m&&!(n==0&&m==0)){
		init(n);
		for(int i=1;i<=m;++i){
			int a,b;
			cin>>a>>b;
			//a++;b++;
			addedge(a,b);
			}
		toposort(n);
		if(ans >= n){
			cout<<"YES"<<endl;
			/*for(int i=0;i<n;++i){
				sum += Ans[i]*i;
			 }
			 cout<<sum<<endl;*/
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
//优先队列版（当有多种输出方案时，序号最小的先输出）O(n+m)
//不同之处（声明定义，取头（top,front））
int n,m;
int ans;//已经出来的节点
int deg[maxn];//入度
int Ans[maxn];//记录的路径或其他内容
vector<int> G[maxn];//存图

void addedge(int u,int v){
    G[u].PB(v);
	deg[v]++;
}

void init(int n){
	memset(deg,0,sizeof(deg));
	memset(Ans,0,sizeof(Ans));
    for(int i=0;i<=n;i++){
        G[i].clear();
    }
}

void toposort(int n) {//拓扑排序
	priority_queue<int,vector<int>,greater<int> >Q;
    ans= 0;
	int k = 0;//记录路径
	for (int i = 0; i < n; i++) {
		 if (deg[i] == 0) {//找到
			Q.push(i);
		 }
	}
	while(!Q.empty()){
		int top = Q.top();Q.pop();
		ans++;
		Ans[k++] = top;
		deg[top]--;
		for (int j = 0; j < G[top].size(); j++){//遍历所有的点
			int t = G[top][j];
			deg[t]--;//让这个点的入度-1
		if(deg[t] == 0)
			Q.push(t);
		}
	}
}

// O(m+n) 记录深度的拓扑排序//hdu2647
int n,m;
int deg[maxn];//入度
int ans;//已经出来的边数
int Ans[maxn];//记录的深度
int Cnt[maxn];//记录每次出来的信息

vector<int> G[maxn];
void add_edge(int u,int v){
    G[u].PB(v);
	deg[v]++;
}
void init(int n){
	memset(deg,0,sizeof(deg));
	memset(Ans,0,sizeof(Ans));
    for(int i=0;i<=n;i++){
        G[i].clear();
    }
}

void toposort(int n) {//拓扑排序
	queue<int> Q;
    ans= 0;
	int cnti = 0;
	int cntj = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		 if (deg[i] == 0) {//找到
			Q.push(i);
			cnti = i;
		 }
	}
	while(!Q.empty()){
		int top = Q.front();Q.pop();
		ans++;
		Ans[cnt]++;
		deg[top]--;
		for (int j = 0; j < G[top].size(); j++){//遍历所有的点
            deg[G[top][j]]--;//让这个点的入度-1
            if(deg[G[top][j]] == 0){
                Q.push(G[top][j]);
                cntj = G[top][j];
            }
		}
		if(top == cnti){cnti = cntj;cnt++;}
	}
}

int main()
{
	while(cin>>n>>m){
        init(n);
        for(int i=1;i<=m;++i){
            int a,b;
            cin>>a>>b;
            //a++;b++;
            add_edge(b,a);
        }
        toposort(n);
        int sum = 888*n;
        if(ans >= n){
            //cout<<"YES"<<endl;
            for(int i=0;i<n;++i){
                sum += Ans[i]*i;
             }
             cout<<sum<<endl;
        }else{
            cout<<"-1"<<endl;
        }
	}
	return 0;
}
