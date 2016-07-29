/*
题意：此题的大意思说有一串珠子，每个珠子都有自己的欣赏值value，现在给你一
    串珠子每个的欣赏值，并给出一些询问，查询某个区间内部总欣赏值是多少，但是有
    一个约定就是如果这个区间内部有两个珠子的欣赏值是一样的，那么他们就视为一个。
    其实也就是求某个区间内部不同的数的和。

采用离线操作
离线
    通常情况下对一种固定的序列，进行多种不同的询问操作。由于这些操作会对序列
    产生影响，使后面的询问无法得出正确结果。所以把所有询问记录下来，然后经过
    特定的排序处理后再进行操作

本题离线原因：
    由于询问一段区间内不同元素的和，那么相同元素就要选择一个作为代表（序列中相同元素
    的最右边的元素为代表），由于区间
    不同，所以选择的代表不同。
    比如数据
    1 1 1 1 1
    询问
    1 4
    2 3
    我们用最右边元素为代表
    则询问1 4 时 序列为 0 0 0 1 1 结果为1
    在询问2 3 时 结果变成0，所以不同询问之间产生了影响。所以想到用离线进行处理。

本题如何离线：（序列从左向右移动，需要用右边为代表）
    一、关于询问的特殊处理
        由于我们采用了最右边的元素为代表，则
        我们知道
        1）如果对n组询问的右边界不变，则前面的询问操作不影响后面的操作。
        2）如果对n组询问的右边界递增，则前面的询问操作不影响后面的操作。

        所以对询问的右边界进行增序排序
    二、关于询问对序列的改变
        用map<int ,int >Hash存储出现元素和代表的位置,用r1表示上次的右边界
        r表示当前询问的右边界
        则遍历区间[r1+1,r]元素a[i]
            如果已经存在的代表元素要进行更换即if(Hash[a[i]] != 0)
            那么原来的代表要处理掉即树状数组上的add操作
            然后对新出现的代表进行更新处理树状数组
        遍历结束后，通过树状数组进行区间和询问。
    完成离线过程

*/
#include<bits/stdc++.h>
using namespace std;
#define sa(x) scanf("%d",&x)
const int maxn = 50010;
int a[maxn];
map<int ,int > Hash;
long long ans[maxn*4];
long long su[maxn*4];

struct node{
    int i,l,r;
}q[maxn*4];

template<typename X>
struct tree_arr{
    X bits[maxn*4];
    int n;
    void init(int s){
        n = s;
        for(int i = 1;i<=n;i++)bits[i] = 0;
    }
    void add(int x,X y){
        while(x<=n){
            bits[x]+=y;
            x+=x&(-x);
        }
    }
    X query(int i){
        X s = 0;
        while(i>0){
            s+=bits[i];
            i-=i&(-i);
        }
        return s;
    }
};
tree_arr<long long > TR;
int cmp1(node a,node b){
    return a.r<b.r;
}
int main(){
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i = 1;i<=n;i++)cin>>a[i];
        int m;
        cin>>m;
        for(int i= 0;i<m;i++){
            cin>>q[i].l>>q[i].r;
            if(q[i].l>q[i].r)swap(q[i].l,q[i].r);
            q[i].i = i;
        }
        sort(q,q+m,cmp1);
        Hash.clear();
        int r = 1;
        TR.init(n);
        for(int i = 0;i<m;i++){
             while(r<=q[i].r){
                if(Hash[a[r]]!=0)
                    TR.add(Hash[a[r]],-a[r]);
                Hash[a[r]] = r;
                TR.add(r,a[r]);
                r++;
             }
             ans[q[i].i] = TR.query(q[i].r) - TR.query(q[i].l-1);
        }
        for(int i = 0;i<m;i++){
            cout<<ans[i]<<endl;
        }
    }

}

