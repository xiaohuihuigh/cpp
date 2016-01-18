
/*
splay区间版本
打标记加区间操作版
*/
/*
bzoj1500 维修数列
操作一：在pos后面插入tot个数
操作二：在pos后面删除tot个数
操作三：将pos后面tot个数全变成c
操作四：将pos后面tot个数翻转
操作五：求pos后面tot个数的和
操作六：求全数列的最大子段和
*/
#include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)
#define key_value ts[ts[root].cld[1]].cld[0]
const int MAXN = 1000;
int n;
int a[MAXN];
int St[MAXN],top;

const int null=-1;
int cnt,root;

struct node
{
    int par,cld[2];
    int val,sum;
    int size;
    bool rev,same;
    int maxl,maxr,maxm;
} ts[MAXN];

int newnode(int key,int par)
{
	int r;
	if(top)
		r=St[--top];
	else
		r=cnt++;
    ts[r].val=ts[r].sum=key;
    ts[r].par=par;
    ts[r].size=1;
    ts[r].cld[0]=ts[r].cld[1]=null;
    ts[r].rev=ts[r].same=0;
    ts[r].maxl=ts[r].maxr=ts[r].maxm=key;
    return r;
}

//下放rev翻转标记
void update_rev(int x)
{
	if(x!=null)
	{
		swap(ts[x].cld[0],ts[x].cld[1]);
		swap(ts[x].maxl,ts[x].maxr);
		ts[x].rev^=1;
	}
}

//下放same区间相同标记
void update_same(int x,int v)
{
	if(x!=null)
	{
		ts[x].val=v;
		ts[x].sum=ts[x].size*v;
		ts[x].maxl=ts[x].maxr=ts[x].maxm=max(v,v*ts[x].size);
		ts[x].same=1;
	}
}

void push_up(int x)
{
	int l=ts[x].cld[0],r=ts[x].cld[1];
    if(l!=null && r==null)
    {
    	ts[x].sum=ts[x].val+ts[l].sum;
    	ts[x].size=1+ts[l].size;
    	ts[x].maxl=max(ts[l].maxl,ts[l].sum+ts[x].val);
    	ts[x].maxr=ts[x].val+max(0,ts[l].maxr);
    	ts[x].maxm=max(ts[l].maxm,ts[x].val+max(0,ts[l].maxr));
    }
    else if(l==null && r!=null)
    {
        ts[x].sum=ts[x].val+ts[r].sum;
    	ts[x].size=1+ts[r].size;
    	ts[x].maxl=ts[x].val+max(0,ts[r].maxl);
    	ts[x].maxr=max(ts[r].maxr,ts[r].sum+ts[x].val);
    	ts[x].maxm=max(ts[r].maxm,ts[x].val+max(0,ts[r].maxl));
    }
    else if(l!=null && r!=null)
    {
        ts[x].sum=ts[x].val+ts[l].sum+ts[r].sum;
    	ts[x].size=1+ts[l].size+ts[r].size;
    	ts[x].maxl=max(ts[l].maxl,ts[l].sum+ts[x].val+max(0,ts[r].maxl));
    	ts[x].maxr=max(ts[r].maxr,ts[r].sum+ts[x].val+max(0,ts[l].maxr));
    	ts[x].maxm=max(ts[l].maxm,ts[r].maxm);
    	ts[x].maxm=max(ts[x].maxm,max(0,ts[l].maxr)+ts[x].val+max(0,ts[r].maxl));
    }
    else
    {
    	ts[x].sum=ts[x].maxl=ts[x].maxr=ts[x].maxm=ts[x].val;
    	ts[x].size=1;
    }
}

void push_down(int x)
{
	int l=ts[x].cld[0],r=ts[x].cld[1];
	if(ts[x].same)
	{
		update_same(l,ts[x].val);
		update_same(r,ts[x].val);
		ts[x].same=0;
	}
	if(ts[x].rev)
	{
		update_rev(l);
		update_rev(r);
		ts[x].rev=0;
	}
}

//旋转，0左旋，1右旋
void rotate(int x,int k)
{
    int y=ts[x].par,z=ts[y].par;
    push_down(y);push_down(x);
    ts[y].cld[!k]=ts[x].cld[k];
    push_up(y);
    if(ts[x].cld[k]!=null)
        ts[ts[x].cld[k]].par=y;
    ts[x].par=z;
    if(z!=null)
        ts[z].cld[(y==ts[z].cld[1])]=x;
    ts[y].par=x;
    ts[x].cld[k]=y;
}

//将x伸展至S下方
void splay(int x,int S)
{
    for(push_down(x);ts[x].par!=S;)
    {
        int y=ts[x].par,z=ts[y].par;
        if(ts[y].par==S)
		    rotate(x,ts[y].cld[0]==x);
        else
        {
            int d=(ts[ts[y].par].cld[0]==y);
            if(ts[y].cld[d]==x)
                rotate(x,!d),rotate(x,d);
            else
                rotate(y,d),rotate(x,d);
        }
    }
    push_up(x);
    if(S==null)
        root=x;
}

//获取中序遍历第k位的节点编号
int get_kth(int x,int k)
{
	push_down(x);
	int ls=(ts[x].cld[0]==null?0:(ts[ts[x].cld[0]].size));
	if(k==ls+1)
		return x;
	else if(k<=ls)
		return get_kth(ts[x].cld[0],k);
	else
		return get_kth(ts[x].cld[1],k-ls-1);
}

//在p下插入l到r个数
int build(int p,int l,int r)
{
    if(r<l)
        return null;
    int mid=(l+r)>>1;
    int t=newnode(a[mid],p);
    if(p==null)
        root=t;
    ts[t].cld[0]=build(t,l,mid-1);
    ts[t].cld[1]=build(t,mid+1,r);
    push_up(t);
    return t;
}

void init()
{
	REP2(i,1,n)
		scanf("%d",&a[i]);
	top=cnt=0;
	root=null;
	root=newnode(-1,null);
	ts[root].cld[1]=newnode(-1,root);
	key_value=build(ts[root].cld[1],1,n);
	push_up(ts[root].cld[1]);
	push_up(root);
}

void printMess(int x)
{
	printf("id:%2d ",x);
	printf("fa:%2d ",ts[x].par);
	printf("lc:%2d ",ts[x].cld[0]);
	printf("rc:%2d ",ts[x].cld[1]);
	printf("va:%2d ",ts[x].val);
	printf("sum:%2d ",ts[x].sum);
	printf("sz:%2d ",ts[x].size);
	printf("rev:%2d ",ts[x].rev);
	printf("same:%2d ",ts[x].same);
	printf("ml:%2d ",ts[x].maxl);
	printf("mr:%2d ",ts[x].maxr);
	printf("mm:%2d ",ts[x].maxm);
	puts("");
}

void track(int x)
{
	if(x!=null)
	{
		track(ts[x].cld[0]);
		printMess(x);
		track(ts[x].cld[1]);
	}
}

void debug()
{
	printf("root : %2d\n",root);
	track(root);
	puts("");
}

//删除节点，回收内存
void erasenode(int x)
{
	if(x!=null)
	{
		St[top++]=x;
		erasenode(ts[x].cld[0]);
		erasenode(ts[x].cld[1]);
	}
}

//获取从pos开始连续tot个数的和
int get_sum(int pos,int tot)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	return ts[key_value].sum;
}

//获取从pos开始连续tot个数的区间最大和
int get_maxsum(int pos,int tot)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	return ts[key_value].maxm;
}

//在pos后方插入连续tot个数
void insert(int pos,int tot)
{
	REP2(i,1,tot)
		scanf("%d",&a[i]);
	splay(get_kth(root,pos+1),null);
	splay(get_kth(root,pos+2),root);
	key_value=build(ts[root].cld[1],1,tot);
	push_up(ts[root].cld[1]);
	push_up(root);
}

//在pos后方删除连续tot个数
void erase(int pos,int tot)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	erasenode(key_value);
	ts[key_value].par=null;
	key_value=null;
	push_up(ts[root].cld[1]);
	push_up(root);
}

//pos开始连续tot个数变成c
void make_same(int pos,int tot,int c)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	update_same(key_value,c);
	push_up(ts[root].cld[1]);
	push_up(root);
}

//pos开始连续tot个数翻转
void make_rev(int pos,int tot)
{
	splay(get_kth(root,pos),null);
	splay(get_kth(root,pos+tot+1),root);
	update_rev(key_value);
	push_up(ts[root].cld[1]);
	push_up(root);
}

char opt[20];

int main()
{
	//freopen("sequence2.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int m;
	while(~scanf("%d%d",&n,&m))
	{
		init();
		REP(i,m)
		{
			int x,y;
			scanf("%s",&opt);
			if(opt[2]=='S')
			{
				scanf("%d%d",&x,&y);
				insert(x,y);
			}
			else if(opt[2]=='L')
			{
				scanf("%d%d",&x,&y);
				erase(x,y);
			}
			else if(opt[2]=='V')
			{
				scanf("%d%d",&x,&y);
				make_rev(x,y);
			}
			else if(opt[2]=='T')
			{
				scanf("%d%d",&x,&y);
				if(y==0)
					puts("0");
				else
					printf("%d\n",get_sum(x,y));
			}
			else if(opt[2]=='K')
			{
				int c;
				scanf("%d%d%d",&x,&y,&c);
				make_same(x,y,c);
			}
			else if(opt[2]=='X')
			{
				if(ts[root].size==2)
					puts("0");
				else
					printf("%d\n",get_maxsum(1,ts[root].size-2));
			}
		}
	}
	return 0;
}

/*
样例
9 11
2 -6 3 5 1 -5 -3 6 3
GET-SUM 5 4
MAX-SUM
INSERT 8 3 -5 7 2
DELETE 12 1
MAKE-SAME 3 3 2
REVERSE 3 6
GET-SUM 5 4
MAX-SUM
REVERSE 7 4
MAKE-SAME 7 3 1
GET-SUM 4 6
*/
