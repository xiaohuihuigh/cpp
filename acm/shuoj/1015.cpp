#include<cstring>
#include<iostream>
using namespace std;
const  int maxn = 300;
int line[maxn],sum[maxn];
int n,m,Max,Min;
int ma[200][20];
int mi[200][20];
void dp(int a[]){
    for(int i = 1;i<=n;i++)
        sum[i] = sum[i-1] + a[i];
   memset(ma,0,sizeof(ma));
   memset(mi,0x3f,sizeof(mi));

    for(int i = 1;i<=n;i++){
        ma[i][1] = mi[i][1] = (sum[i]%10+10)%10;
    }
    for(int j = 2;j<=m;j++)
    for(int i = j;i<=n;i++)
    for(int k = j-1;k<i;k++){
        ma[i][j] = max(ma[i][j] , ma[k][j-1]*(((sum[i]-sum[k])%10+10)%10));
        mi[i][j] = min(mi[i][j], mi[k][j-1]* ( ( (sum[i] - sum[k])%10+10  )%10) );
    }
    Max = max(Max,ma[n][m]);
    Min  = min(Min,mi[n][m]);
}

int main(){
     Max = 0;
     Min = 0x3f3f3f3f;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>line[i];
        line[i+n]= line[i];
    }
    for(int i = 0;i<n;i++)
        dp(line+i);
        cout<<Min<<endl<<Max<<endl;
}
