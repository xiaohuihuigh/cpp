
/*树状数组*/
const int maxn = 1005;
int lb(int i){return (-i)&i;}
template<typename X>
struct tree_arr{
        X bits[maxn];
        int n;
        void init(int s){n = s;rep2(i,1,s)bits[i] = 0;}
        void add(int i,X y){while(i<=n){bits[i]+=y;i+=lb(i);}}
        X query(int i){X s = 0;while(i>0){s+=bits[i];i-=lb(i);}return s;}
    };
/*二维树状数组*/
const int maxn = 1005;
int lb(int i){return (-i)&i;}
template<typename X>
struct tree_mul_arr{
    struct tree_arr{
        X bits[maxn];
        int n;
        void init(int s){n = s;rep2(i,1,s)bits[i] = 0;}
        void add(int i,X y){while(i<=n){bits[i]+=y;i+=lb(i);}}
        X query(int i){X s = 0;while(i>0){s+=bits[i];i-=lb(i);}return s;}
    } bits[maxn];
    int n;
    void init(int x,int y){
        n = x;
        rep2(i,1,x){
            bits[i].init(y);
        }
    }
    void add(int i,int j,X z){
        while(i<=n){
            bits[i].add(j,z);
            i+=lb(i);
        }
    }
    X query(int i,int j){
        X s = 0;
        while(i>0){
            s+=bits[i].query(j);
            i-=lb(i);
        }
        return s;
    }
};
/*区间更新，区间求和树状数组*/
