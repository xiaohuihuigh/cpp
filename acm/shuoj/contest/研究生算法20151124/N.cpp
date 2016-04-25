
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int Next[100005];
int ans[100005];

void getNext(string a)
{
    int i = 0;int j = -1;
    Next[0] = -1;
    while(i<a.length()){
        if(j == -1||a[i] == a[j])
        {
            i++;j++;
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}
int kmp(string T,string S)
{
    int ans = 0;
    int i, j = 0;
    int slen = S.size();
    int tlen = T.size();
    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }
    getNext(T);
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = Next[j];
        if(S[i] == T[j])
            j++;
            ans = max(ans,j);
        if(j == tlen)
        {
            break;
        }
    }
    return ans;
}

int main() {
    char a[100005];

    while(scanf("%s",a)!= EOF&&a != NULL){

       char b[100005];
        scanf("%s",b);
    string a1 = a,b1 = b;
    printf("%d\n",kmp(b1,a1));
		getchar();
        }
    return 0;
}

