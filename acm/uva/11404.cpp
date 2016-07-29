//#include<bits/stdc++.h>
//using namespace std;
//int dp[1004][1004];
//string str[1004][1004];
//const int INF = 0x3f3f3f3f;
//int main(){
//    string s;
//    string s1;
//    while(cin>>s){
//        int len = s.length();
//        memset(dp,0,sizeof(dp));
//        for(int i = 0;i<len;i++){
//            dp[i][i] = 1;
//            str[i][i] = s[i];
//        }
//        for(int p = 1;p<len;p++)
//        for(int i = 0;i<len-1;i++){
//            for(int j= i+p;j<len;j++){
//                if(dp[i+1][j]>dp[i][j-1]){
//                    dp[i][j] = dp[i+1][j];
//                    str[i][j] = str[i+1][j];
//                }
//                else if(dp[i+1][j]==dp[i][j-1]){
//                    dp[i][j] = dp[i+1][j];
//                    str[i][j] = min(str[i+1][j],str[i][j-1]);
//                }
//                else{
//                    dp[i][j] = dp[i][j-1];
//                    str[i][j] = str[i][j-1];
//                }
////                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
//                if(s[i] == s[j]){
//                    if(dp[i][j]<dp[i+1][j-1]+2){
//                        dp[i][j] = dp[i+1][j-1]+2;
////                        cout<<i<<" "<<j<<"dp"<<dp[i+1][j-1]<<"str"<<str[i+1][j-1]<<endl;
//                        str[i][j] = s[i]+str[i+1][j-1]+s[j];
//                    }
//                    else if(dp[i][j]==dp[i+1][j-1]+2){
//                        str[i][j] = min(str[i][j],s[i]+str[i+1][j-1]+s[j]);
//                    }
//                }
////                    dp[i][j] = max(dp[i][j],dp[i+1][j-1]+2);
//                else {
//                    if(dp[i][j]<dp[i+1][j-1]){
//                        dp[i][j] = dp[i+1][j-1];
//                        str[i][j] = str[i+1][j-1];
//                    }
//                    else if(dp[i][j]==dp[i+1][j-1]){
//                        str[i][j] = min(str[i][j],str[i+1][j-1]);
//                    }
//                }
////                    dp[i][j] = max(dp[i][j],dp[i+1][j-1]);
//            }
//        }
//////        cout<<dp[1][2]<<str[1][2]<<endl;
////        cout<<dp[0][len-1]<<" "<<str[0][len-1]<<endl;
//            cout<<str[0][len-1]<<endl;
//    }
//}

#include<bits/stdc++.h>
using namespace std;
#define maxn 1005

struct node
{
    int len;
    string ch;
    bool operator <(const node &x) const
    {
        if( len == x.len ) return ch > x.ch;
        else return len < x.len;
    }
};

char ch1[maxn], ch2[maxn];
node dp[maxn][maxn];

void init(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        dp[0][i].len = 0;
        dp[0][i].ch.clear();
        dp[i][0].len = 0;
        dp[i][0].ch.clear();
    }
}

int main()
{
    while(scanf("%s", ch1+1) != EOF)
    {
        int len = strlen(ch1+1);
        for(int i = 1; i <= len; ++i) ch2[i] = ch1[len-i+1];

        init(len);
        for(int i = 1; i <= len; ++i)
        {
            for(int j = 1; j <= len; ++j)
            {
                if( ch1[i] == ch2[j] )
                {
                    dp[i][j].len = dp[i-1][j-1].len+1;
                    dp[i][j].ch = dp[i-1][j-1].ch+ch1[i];
                }
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }


        node ans;
        ans.len = 0;
        ans.ch.clear();
        for(int i = 1; i < len; ++i){
//            cout<<dp[i][len-i].len<<dp[i][len-i].ch<<endl;
            ans = max(ans, dp[i][len-i]);//不包含对称轴询问过程不能重叠
        }
        ans.len = ans.len*2;
        node temp;
        for(int i = 0; i < len; ++i)
        {
            temp = dp[i][len-i-1];
            temp.len = temp.len*2+1;
            temp.ch += ch1[i+1];//加上对称轴，询问过程重叠一个字母
            ans = max(ans, temp);
//            cout<<ans.ch<<endl;
        }

        strcpy(ch1+1, ans.ch.c_str());
        int length = ans.len/2;
        for(int i = 1; i <= length; ++i)
            printf("%c", ch1[i]);
        if(ans.len%2) length += 1;
        for(int i = length; i >= 1; --i)
            printf("%c", ch1[i]);
        printf("\n");
    }

    return 0;
}
