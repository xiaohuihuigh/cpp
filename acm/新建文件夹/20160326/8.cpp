    #include<stdio.h>
    #include<algorithm>
    using namespace std;
    int a[1005];
    int main()
    {
        int T, n, i;
        scanf("%d",&T);
        while(T--)
        {
            scanf("%d",&n);
            for(i = 0; i < n; i++)
                scanf("%d",&a[i]);
            sort(a,a+n);
            int sum = 0;
            while(n >= 4)
            {
                if((a[1] * 2 + a[n-1] + a[0]) > (2 * a[0] + a[n-1] + a[n-2]))
                {  //求出最长的两个人过桥所用的最短时间
                    sum += a[n-1]; //用时最短的和用时最长的一起过去
                    sum += a[0]; //用时最短的回来
                    sum += a[n-2]; //用时最短的和用时第二长的一起过去
                    sum += a[0]; //用时最短的回来
                }
                else
                {
                    sum += a[1]; //最短的和第二短的一起过去
                    sum += a[0]; //最短的回来
                    sum += a[n-1]; //最长的和第二长的一起过去
                    sum += a[1]; //第二短的回来
                }
                n -= 2;
            }
            if(n == 3)
                sum += a[1] + a[0] + a[2];
            else if(n == 2)
                sum += a[1];
            else
                sum += a[0];
            printf("%d\n",sum);
        }
        return 0;
    }
