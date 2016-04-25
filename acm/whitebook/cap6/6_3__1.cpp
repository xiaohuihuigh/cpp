#include<bits/stdc++.h>
using namespace std;
void build(int n,char*pre,char*in,char*post){

    if(n<=0)return ;
    cout<<"a"<<endl;
    int x = strchr(in,pre[0])-in;
     post[n-1] = pre[0];
    build(x,pre+1,in,post);
    build(n-x-1,pre+x+1,in+x+1,post+x);
}
int main(){
    char preorder[20],inorder[20],postorder[20];
    while(cin>>preorder>>inorder){
        int n = strlen(preorder);
        build(n,preorder,inorder,postorder);
        postorder[n] = '\0';
        cout<<postorder<<endl;
    }
}

