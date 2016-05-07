#include<stdio.h>
int main(){
    int i,j,m,n,a[2000],b[2000];
    scanf("%d%d",&n,&m);
    for(i =0;i<n;i++)
        scanf("%d",&a[i]);
    for(i =0;i<m;i++)
        scanf("%d",&b[i]);
        i = 0;
        j = 0;
    while(a[n-1]!= 0&&b[m-1]!= 0)
    {
        if(a[i]>=33)
        {

            if(a[i]>b[j]&&b[j] != 31&&b[j] != 30)
            {
                b[j] = 0;
                j++;
            }
            else if(a[i]<b[j]||b[j] == 31)
            {
                a[i]=0;
                i++;
            }
            else if(a[i] == b[j]||b[j] == 30)
            {
                a[i]=0;
                b[j]=0;
                i++;
                j++;
            }
        }

        else if(a[i] == 32)
        {
            if(b[j]>32)
            {
                a[i]=0;
                i++;
            }
            else if(b[j]==32||b[j]==30)
            {
                a[i]=0;
                b[j]=0;
                i++;
                j++;
            }
            else if(b[j]==31)
            {
                b[j] = 0;
                j++;
            }
        }
        else if(a[i]==31)
        {
            if(b[j]>32)
            {
                b[j] = 0;
                j++;
            }
            else if(b[j]==32)
            {
                a[i]=0;
                i++;
            }
            else if(b[j]==31)
            {
                printf("Draw");
                return 0;
            }
            if(b[j] == 30)
            {
                a[i]=0;
                b[j]=0;
                i++;
                j++;
            }
        }
        else //if(a[i]==30)
        {
                a[i]=0;
                b[j]=0;
                i++;
                j++;
        }
    }
    if(a[n-1]== 0&&b[m-1]== 0)
        printf("Draw");
    else if(a[n-1]== 0)
        printf("Second");
    else
        printf("First");
    return 0;
}
/**************************************************************
    Problem: 1848
    User: xiaohuihui
    Language: C
    Result: Accepted
    Time:0 ms
    Memory:988 kb
****************************************************************/
