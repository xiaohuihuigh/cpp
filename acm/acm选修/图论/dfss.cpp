
#include<iostream>
#include<vector>
using namespace std;
/*第一次搜索到边（u，v）时v是如果白色，为树边，灰色，后向边，黑色，前向或横向边*/
/*拓扑排序：没搜完一个节点，加到桟中，全部搜完，出栈就是拓扑排序*/
/*强连通分量：1.原图dfs。2.将图反转。3.按照原图节点完成时间的降序dfs，pa为-1的个数为强分量的个数*/
vector<int >VZ[1000];//记录图
vector<int >VT[1000];
int id[1000];//id为完成的时间
int time_d[1000];//发现节点的时间
int time_f[1000];//完成节点的时间
int color[1000];// 0发现的节点 1发现未完成的节点2完成的节点
int pa[1000];//父亲节点
void dfs_visit(vector<int> *V,int v,int &time){
	time++;
	time_d[v] = time;
	color[v] = 1;
	int _size =  V[v].size();
	for(int i = 0;i<_size;i++)
		if(color[V[v][i]] == 0){
			pa[V[v][i]] = v;
			dfs_visit(V,V[v][i],time);
		}
	color[v] = 2;
	time++;
	time_f[v] = time;
}
void dfs(vector<int> *V,int m,int n){
	//初始化
	for(int i = 1;i<=m;i++){
		color[i] = 0;pa[i] = -1;
	}
	//对每个节点深搜
	int time = 0;
	for(int i = 1;i<=m;i++){
		if(color[i] == 0){
			dfs_visit(V,i,time);
		}
	}
}
void dfsT(vector<int> *V,int m,int n){
	//初始化
	for(int i = 1;i<=m;i++){
		color[i] = 0;pa[i] = -1;
	}
	//对每个节点深搜
	int time = 0;
	for(int i = 1;i<=m;i++){
		if(color[id[i]] == 0&&id[i]!= 0){
			dfs_visit(V,id[i],time);
		}
	}
}
int main(){
    int m,n;
    while(cin>>m>>n){
    //建图
        for(int i = 0;i<n;i++){
            int a,b;
            cin>>a>>b;
            id[i] = 0;
            VZ[a].push_back(b);
            VT[b].push_back(a);
        }
        //生成深度优先搜索树
        dfs(VZ,m,n);
        for(int i = 1;i<=m;i++){
            cout<<i<<" "<<time_f[i]<<endl;
        }cout<<endl;
         for(int i = 1;i<=m;i++)
            id[time_f[i]] = i;
        dfsT(VT,m,n);
        int ans = 0;
        for(int i = 1;i<=m;i++){
            cout<<i<<" "<<time_f[i]<<endl;
            if(pa[i] == -1)ans++;
        }
        cout<<ans;

    }
}
/*
8 14
3 4
3 7
7 6
7 8
6 7
8 8
4 3
4 8
2 3
2 5
2 6
5 1
5 6
1 2



*/
