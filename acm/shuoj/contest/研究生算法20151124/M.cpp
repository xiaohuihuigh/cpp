#include<bits/stdc++.h>
using namespace std;
int a[1005];//保存每个的个数
int s[1005];//前缀和
int id[1000005];//保存值
int main(){
    int n;
    while(~scanf("%d",&n)){
            memset(a,0,sizeof(a));
            int c;
        for(int i = 0;i<n;i++){
            scanf("%d",&id[i]);
            a[id[i]-1000]++;
        }
        int b;
        scanf("%d",&b);
        int sumn = 0;int t;int yn = 0;

        for(int i = 0;i<=1000;i++){
            sumn += a[i];
            s[i] = sumn;
            if(sumn >= n/2+1&&yn ==0){t = i;yn = 1;}
         }

        int sumg = 0;
        for(int i = 0;i<1000;i++){
            int x = (t - i)*a[i];
            sumg += x>0?x:-x;
        }
        sumg += b;

        int  l = 0,r = t, mid;
        int ans = 0;
		while(l!=r){
			mid = (l+r)/2;
			int sum = 0;
			for(int i = 0;i<=1000;i++){
                int x = (mid - i)*a[i];
                sum += x>0?x:-x;
            }

            sum -= b;
            if(sum > sumg)l = mid+1;
            else r = mid;
		}
        ans = s[r-1];

		l = t,r = 1001;//左右中
		while(l!=r){
			mid = (l+r)/2+1;
			int sum = 0;
			for(int i = 0;i<=1000;i++){
            int x = (mid - i)*a[i];
            sum += x>0?x:-x;
        }
			sum = sum - b;
			if(sum <= sumg)l = mid;
            else r = mid-1;
		}
		ans = s[r] - ans;

		if(ans == 1){

            printf("YES\n");
        for(int i = 0;i<n;i++){
            if(id[i] == t+1000){printf("%d\n",i+1);break;}
        }
		}

        else
        printf("NO\n%d\n",ans);
    }
    return 0;
}
