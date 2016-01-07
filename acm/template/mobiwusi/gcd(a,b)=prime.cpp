/*
公因数为质数问题
*/
#include <iostream>
#include <bitset>
using namespace std;
typedef long long LL;
const int N = 10000010;
bitset<N> prime;
LL phi[N], f[N];
int p[N], k;
void isprime() {   //求素数组
    k = 0;
    prime.set();
    for(int i=2; i<N; i++) {
        if(prime[i]) {
            p[k++] = i;
            for(int j=i+i; j<N; j+=i)
                              prime[j] = false;
            }
       }
}
void Init() {   //求(i)
    int i,j;
    for( i=1; i<N; i++) phi[i] = i;
    for( i=2; i<N; i+=2) phi[i] >>= 1;
    for( i=3; i<N; i+=2) {
        if(phi[i] == i) {
            for( j=i; j<N; j+=i)
                phi[j] = phi[j] - phi[j] / i;
        }
    }
    f[1] = 0;
    for( i=2;i<N;i++)
        f[i] = f[i-1] + (phi[i]<<1);
}
LL Solve(int n){
    LL ans = 0;
    for(int i=0; i<k&&p[i]<=n; i++)
        ans += 1 + f[n/p[i]];
    return ans;
}
int main() {
    Init();
    isprime();
    int n;
    scanf("%d",&n);
    printf("%I64d\n",Solve(n));
    return 0;
}
