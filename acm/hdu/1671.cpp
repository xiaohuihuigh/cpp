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
#define max_node 10
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const int maxn = 10000;
struct phone{
    int len;
    char s[11];
    bool operator<(const struct phone s)const {
        return len<s.len;
    }
}P[maxn];
typedef struct node{
    node *next[max_node];
    int v;
    node(){
        memset(next,NULL,sizeof(next));
        v = 0;
    }
}node,*Trie;
node *root;
bool creatTire(char *s){
    int len = strlen(s);
    Trie p = root;
    rep(i,len){
    	int id = s[i] - '0';
    	if(p->next[id] == NULL) p->next[id] = new node();
    	p = p->next[id];
    	if(p->v == -1)return true;
//    	p->v++;
    }
    p->v = -1;
    return false;
}
int findTrie(char *s){
    int len = strlen(s);
    Trie p = root,q;
    rep(i,len){
    	int id = s[i] - '0';
    	p = p->next[id];
    	if(p == NULL)return 0;
//    	if(p->v == -1) return 1;//字符集中已有串是此串的前缀
    }
    return p->v;//此串是字符集中某串的前缀
}
int delTire(Trie T){
    int i;
    if(T == NULL)return 0;
    rep(i,max_node){
        if(T->next[i]!= NULL)delTire(T->next[i]);
    }
    free(T);
    return 0;
}


int main(){
    int T;
    in(T);
    while(T--){
        root = new node();
        int n;in(n);
        char s[15];
        rep(i,n){
            scanf("%s",s);
            int len = strlen(s);
            P[i].len = len;
//            P[i].s = s;
            strcpy(P[i].s,s);
        }
        sort(P,P+n);
        int yn = 0;
        rep(i,n){
            if(creatTire(P[i].s)){
                yn = 1;
                break;
            }
        }
        if(yn == 1)printf("NO\n");
        else printf("YES\n");
        delTire(root);
    }n
    return 0;
}

/**
3
3
911
97625999
91125426
3
911
97625999
91125426
5
113
12340
123440
12345
98346
*/
