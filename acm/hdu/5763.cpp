#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 100005;
int ne_xt[N];
char S[N], T[N];
int yns[N];
long long dp[N];
int slen, tlen;

void getne_xt()
{
    int j, k;
    j = 0; k = -1; ne_xt[0] = -1;
    while(j < tlen)
        if(k == -1 || T[j] == T[k])
            ne_xt[++j] = ++k;
        else
            k = ne_xt[k];

}
/*
返回模式串T在主串S中首次出现的位置
返回的位置是从0开始的。
*/
int KMP_Index()
{
    int i = 0, j = 0;
    getne_xt();

    while(i < slen && j < tlen)
    {
        if(j == -1 || S[i] == T[j])
        {
            i++; j++;
        }
        else
            j = ne_xt[j];
    }
    if(j == tlen)
        return i - tlen;
    else
        return -1;
}
/*
返回模式串在主串S中出现的次数
*/
int KMP_Count()
{
    int ans = 0;
    int i, j = 0;

    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0]){
            yns[0] = 1;
            return 1;
            }
        else
            return 0;
    }
    getne_xt();
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = ne_xt[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            yns[i] = true;
            ans++;
            j = ne_xt[j];
        }
    }
    return ans;
}
int main()
{
//        freopen("1001.in", "r", stdin);
////    freopen("1001.out", "w", stdout);
//    freopen("data.out", "w", stdout);
    int TT;
    int i, cc;
    cin>>TT;
    int ca = 0;
    while(TT--)
    {
        ca++;
        memset(yns,0,sizeof(yns));
//        for(int i = 0;i<100000;i++)S[i] = 'a';
        cin>>S>>T;
        slen = strlen(S);
        tlen = strlen(T);
        KMP_Count();
        dp[0]= 1;
        for(int i = 1;i<=slen;i++){
            if(i>=tlen)
                dp[i] = (dp[i-1]+dp[i-tlen]*yns[i-1])%mod;
            else dp[i] = dp[i-1]%mod;
        }
        cout<<"Case #"<<ca<<": "<<dp[slen]<<endl;
    }
    return 0;
}

//int main(){
//    for(int i = 0;i<100000;i++)cout<<"a";
//}
