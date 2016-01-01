#include<stdio.h>
int x,y,z;
int geshu(int a1,int b1,int c1){
    int i,j,k;
    for(i =100/a1; i >=1;i--)
        for(j = (100-a1*i)/b1;j >= 1;j--)
            for(k=1;k <= (100-a1*i - b1*j)/c1;k++)
            if(a1*i + b1*j + c1 * k == 100 && i + j + 3 * k == 100)
            {
                x = i;
                y = j;
                z = 3*k;
                return 1;
            }
    return 0;

}
int main()
{
    int a,b,c,n = 1;
    while(scanf("%d",&a) == 1 && scanf("%d",&b) == 1 && scanf("%d",&c) == 1)
    {
        printf("Case %d:\n",n++);
        if(geshu(a,b,c))
            printf("%d %d %d\n",x,y,z);
        else
            printf("Impossible\n");
    }
    return 0;
}
