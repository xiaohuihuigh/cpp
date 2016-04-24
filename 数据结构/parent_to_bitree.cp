#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int>pre;//保存先序遍历结果
vector<int>post;//保存后序遍历结果
int bitree[100];//保存二叉树列表形式结果
int n;
int first_son(int t,int * pa){
//    得到树的第一个孩子
    for (int i = 0;i<n;i++){
        if(pa[i] == t)return i;
    }
    return -2;
}
int next_sib(int t,int * pa){
//    得到树的孩子的下一个兄弟
    for(int i = t+1;i<n;i++){
        if(pa[i] == pa[t])return i;
    }
    return -2;
}
void pre_root(int t,int *pa){
//    先根遍历
    pre.push_back(t);
    for(int x = first_son(t,pa);x!=-2;x = next_sib(x,pa)){

        pre_root(x,pa);
    }

}
void post_root(int t,int * pa){
//    后根遍历
     for(int x = first_son(t,pa);x!=-2;x = next_sib(x,pa)){
        post_root(x,pa);
    }
    post.push_back(t);
}
void creatbitree(int fir_post,int en_post,int fir_pre,int ind){
//    根据先根遍历和后根遍历对应的先序遍历和后序遍历生成二叉树
    if(en_post-fir_post == 1){bitree[ind] = post[fir_post];return;}
    for(int i = fir_post;i<en_post;i++){
        if(post[i] == pre[fir_pre]){
            bitree[ind] = post[i];
            if(i>fir_post){
            creatbitree(fir_post,i,fir_pre+1,ind*2);}
            if(i<en_post-1){
                creatbitree(i+1,en_post,fir_pre+i-fir_post+1,ind*2+1);}
            return;
        }
    }
}
void DisplayTW( int r, int level,int *pa)
//按凹入表示法显示树，level为层次数，可设根结点的层次数为1
{
	if (r >= 0 && r < n)
	{
		cout<<endl;
		for(int i = 0; i< level - 1; i++)
			cout<<"    ";
		cout << r;
		for (int child = first_son(r,pa); child != -2; child = next_sib(child,pa))
		{
			DisplayTW(child, level + 1,pa);
		}
	}
}
void Display(int r,int level)
//按树状形式显示以r为根的二叉树，level为层次数，可设根结点的层次数为1
{
	if(bitree[r]!= -1)
	{
		Display(r*2+1, level + 1);
		cout << endl;
		for(int i = 0; i < 2*(level - 1); i++)
			cout << " ";
		cout << bitree[r];

		Display(r*2, level + 1);
	}
}
int main(){
    n = 7;
    int pa[] = {-1,0,0,0,1,1,2};
    pre.clear();
    post.clear();
    pre_root(0,pa);
    post_root(0,pa);
//    cout<<"打印树为"<<endl;
    DisplayTW(0,1,pa);
    cout<<endl;
//    cout<<"树的先根遍历（二叉树的先序遍历）："<<endl;
    for(int i = 0;i<pre.size();i++)i== pre.size()-1?cout<<pre[i]<<endl:cout<<pre[i]<<" ";
//    cout<<"树的后根遍历（二叉树的中序遍历）："<<endl;
    for(int i = 0;i<post.size();i++)i== post.size()-1?cout<<post[i]<<endl:cout<<post[i]<<" ";
    memset(bitree,-1,sizeof(bitree));
    creatbitree(0,7,0,1);
//    cout<<"打印二叉树为："<<endl;
    Display(1,1);
    cout<<endl;
}
