#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char array[101];
//二叉树结点
typedef struct BiTNode{
char data;
struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//按先序序列创建二叉树
int CreateBiTree(BiTree &T,int &index,int &n){
    if(index == n){
        return 0;
    }
    //按先序次序输入二叉树中结点的值（一个字符），‘#’表示空树
    if(array[index] == '#'){
    T = NULL;
    index++;
    }
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        //生成根结点
        T->data = array[index];
        index++;
        //构造左子树
        CreateBiTree(T->lchild,index,n);
        //构造右子树
        CreateBiTree(T->rchild,index,n);
    }
    return 0;
}

//输出
void Visit(BiTree T){
    if(T->data != '#'){
        printf("%c ",T->data);
    }
}

//中序遍历
int InOrder(BiTree T){
    if(T != NULL){
        //访问左子结点
        InOrder(T->lchild);
        //访问根节点
        Visit(T);
        //访问右子结点
        InOrder(T->rchild);
    }
return 0;
}
int main()
{
    int len,index;
    while(scanf("%s",array) != EOF){
        BiTree T;
        len = strlen(array);
        index = 0;
        //创建二叉树
        CreateBiTree(T,index,len);
        //中序遍历
        InOrder(T);
        printf("\n");
    }
    return 0;
}
