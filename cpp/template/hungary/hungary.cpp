/*hdu2063*/
VI G[555];
int match[1005];
bool used[1005];

bool h(int u) {
	used[u] = 1;
	REP(i,G[u].size()) {
		int v = G[u][i], w = match[v];
		if(w < 0 || ! used[w] && h(w)) {
			match[v] = u;
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int hungary(int n) {
	int res = 0;
	CLR(match, -1);
	REP(v, n) {
		if(match[v] < 0) {
			CLR(used, 0);
			if(h(v)) res ++;
		}
		//cout<<res<<" "<<v<<endl;
	}
	return res;
}
int main (){
    int k,m,n;
    while(scanf("%d",&k)&&k){
    scanf("%d%d",&n,&m);
    int a,b;
    REP(i,555)
    G[i].clear();/////chu shihua 
    for(int i = 0;i< k;i++){
        scanf("%d%d",&a,&b);
        a--;b--;
        G[a].PB(b+n);/////b+n
    }
    printf("%d\n",hungary(n));
    //cout<<hungary(n)<<endl;
    }
    return 0;

}