//fast_mod.cpp
/*
n^m(mod c)
A^13 = A^8*A^4*A^1用二进制表示A^(1101) = A^(1000)*A^(100)*A^(1)
例如：：N = 13 = 1101（2），N>>1 = 110（2） ，
*/
long long fast_mod(long long n,long long m,long long c){ //求快速幂
    long long ret=1;
    while(m){
        if(m&1)ret = ret*n%c;
        n=n*n%c;//这里保证m的移位和n的幂数对等，右移x位就为n的2^x次幂
        m>>=1;
    }
    return ret;
}
