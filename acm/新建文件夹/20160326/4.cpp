#include<iostream>
using namespace std;
int v[9000];
int d[9000];
int p[9000];
int dd[9000];
int main(){
	int n;
	while(cin>>n){
		//memset(val,-1,sizeof(val));
		for(int i = 0;i<n;i++){
			cin>>v[i]>>d[i]>>p[i];
		}
		int cnt = 0;
		 int stk2 = 0;
		for(int i  = 0;i<n;i++){
			p[i] = p[i] -stk2;
			if(p[i]>=0){
			dd[cnt++] = i+1;
			for(int j = 1;j+i<n;j++){
					if(v[i]-j+1==0)break;
					if(p[j+1]>=0)p[j+i]  = max(-1,p[j+i] - (v[i]-j+1));
				}
			}
			else{
				 stk2=min(stk2+d[i],(int)1e7);
				}
			}
		cout<<cnt<<endl;
		for(int i = 0;i<cnt;i++){
			if(i != 0)cout<<" ";
			cout<<dd[i];
		}
		cout<<endl;
	}
	return 0;
}

/*

int vis[4010];
int v[4010], d[4010], p[4010];
int main()
{
    int n;
    while(~scanf("%d",&n)) {
        CLR(vis,0);
        REP(i,n) {
            scanf("%d%d%d",&v[i],&d[i],&p[i]);
        }
        VI ans;
        REP(i,n) if(!vis[i]) {
            ans.PB(i+1);
            int V = v[i];
            int sum = 0;
            for(int j = i+1; j < n; j++) if(!vis[j]) {
                p[j] = max(-1, p[j] - V - sum);
                if(p[j] < 0) vis[j] = 1;
                V = max(V-1, 0);
                if(vis[j]) sum = min(sum + d[j], (int)1e7);
            }
        }
        printf("%d\n", (int) ans.size());
        REP(i,ans.size()) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}*/
