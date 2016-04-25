#include <stdio.h>
int main(){
    int a[50][50],m,i,j,x,y,z;
    while(scanf("%d",&m)== 1)
    {
        for(i = 0;i<m;i++)
        for(j = 0;j<2*i+1;j++)
        {
            scanf("%d",&a[i][j]);
        }

        for(i=1;i<m;i++)
        {
            a[i][0]=a[i-1][0]+a[i][0];

            x = a[i-1][0]+a[i][1];
            y = a[i-1][1]+a[i][1];
            if(x>y)
                a[i][1] = x;
            else
                a[i][1] = y;
                a[i][2*i] = a[i-1][2*i-2]+a[i][2*i];
            if(i != 1){
            x = a[i-1][2*i-3]+a[i][2*i-1];
            y = a[i-1][2*i-2]+a[i][2*i-1];
            if(x>y)
                a[i][2*i-1] = x;
            else
                a[i][2*i-1] = y;
            }
            for(j = 2; j<2*i-1;j++ )
            {
                x = a[i-1][j-2];
                y = a[i-1][j-1];
                z = a[i-1][j];
                if(x<y)
                x =y;
                if(x<z)
                x = z;
                a[i][j] = x +a[i][j];
            }

        }
        for(j = 0;j<2*i;j++)
        if(a[m-1][0]<a[m-1][j+1])
        a[m-1][0]=a[m-1][j+1];
        printf("%d\n",a[m-1][0]);
    }
    return 0;

}

/**************************************************************
    Problem: 1847
    User: xiaohuihui
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:988 kb
****************************************************************/
