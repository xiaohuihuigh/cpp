#include<bits/stdc++.h>
using namespace std;
using namespace std;
#define INF 0x3FFFFFFF
#define PB(X) push_back(X)
#define MP(X,Y) make_pair(X,Y)
#define lson l,m,rt<<1
#define rson m+1,r,tr<<1|1
#define all(x) x.begin(),x.end()
typedef pair<int,int>PII;
typedef vector<PII>VII;
const int MAXN = 100010;
inline int input() { int x; scanf("%d", &x); return x;}
inline void print(char s = NULL,int t = 0){printf("%s%d ",s,t);}
vector<int> waste;
string ss[] = {"Carrots","Kiwis","Grapes"};
int main(){
    ios::sync_with_stdio(false);
    int n,m,k,t;
    while(cin>>n>>m>>k>>t){
        for (int i = 0;i<k;i++){
        	int x,y;
        	cin>>x>>y;
        	x--,y--;
        	waste.PB(x*m+y);
        }
//        sort(waste.begin(),waste.end());
        sort(all(waste));
        for(int i = 0;i<t;i++){
            int x,y;
            cin>>x>>y;
            x--,y--;
            int l = 0,r = k;
            while(l<r){
                int mid = (l+r)/2;
                if(waste[mid]>=x*m+y)r = mid;
                else l = mid+1;
            }
//            cout<<l<<endl;
            if(waste[l] == x*m+y){
                cout<<"Waste"<<endl;
            }
            else{
                int s = x*m+y - l;
                cout<<ss[s%3]<<endl;
            }
        }
    }
}
