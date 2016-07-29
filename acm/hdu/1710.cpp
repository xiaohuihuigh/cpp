#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int  pre_arr[maxn];
int  in_arr[maxn];
int  la_arr[maxn];
//二叉树结点
int cnt = 0;
typedef struct BiTNode{
int data;
struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;





void CreateBinaryTreeHelp(BiTree &r, int pre[], int in[],
							int preLeft, int preRight, int inLeft, int inRight)
// 操作结果：已知二叉树的先序序列pre[preLeft..preRight]和中序序列in[inLeft..inRight]构造
//	以r为根的二叉树
{
	if (inLeft > inRight)
	{	// 二叉树无结点,空二叉树
		r = NULL;			// 空二叉树根为空
	}
	else
	{	// 二叉树有结点,非空二叉树
//		r = new BiTNode(pre[preLeft]);// 生成根结点
		r = (BiTree)malloc(sizeof(BiTNode));
		r->data = pre[preLeft];
		int mid = inLeft;
		while (in[mid] != pre[preLeft])
		{	// 查找pre[preLeft]在in[]中的位置,也就是中序序列中根的位置
			mid++;
		}
		CreateBinaryTreeHelp(r->lchild, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);
			// 生成左子树
		CreateBinaryTreeHelp(r->rchild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1,
			inRight);								// 生成右子树
	}
}
void CreateBiTree(BiTree &T,int pre[], int in[], int n)
// 操作结果：已知先序和中序序列构造二叉树
{
							// 二叉树的根
	CreateBinaryTreeHelp(T, pre, in, 0, n - 1, 0, n - 1);
		// 由先序和中序序列构造以r为根的二叉树
	return ;				// 返回以r为根的二叉树
}

void Visit(BiTree T){
    la_arr[cnt++] = T->data;
//    if(T->data != '#'){
//        printf("%d %d\n",T->data,cnt-1);
//    }
}
int LaOrder(BiTree T){
    if(T != NULL){
        //访问左子结点
        LaOrder(T->lchild);
        //访问右子结点
        LaOrder(T->rchild);
        //访问根节点
        Visit(T);
    }}
int main(){
    int n;
    while(cin>>n){
        for(int i = 0;i<n;i++)cin>>pre_arr[i];
        for(int i = 0;i<n;i++)cin>>in_arr[i];
        BiTree T;

        CreateBiTree(T,pre_arr,in_arr,n);
        cnt = 0;
        LaOrder(T);

        for(int i = 0;i<n;i++)i != (n-1)?cout<<la_arr[i]<<" ":cout<<la_arr[i]<<endl;

    }
}
