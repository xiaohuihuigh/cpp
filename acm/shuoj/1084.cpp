

#include<stdio.h>
#include<string.h>
int main()
{
    char c,a[100],i=0,j=0,k;
    while(scanf("%c",&c))
    {
        if(c!='}')
        {
            if(c!='\n')
            {
                a[i++]=c;
                if(c=='/'||c=='*')
                {
                    j++;
                }
            }
            else
            {
                if(j==4||j==0)
                {
                    for(k=0;k<i;k++)
                    {
                        printf("%c",a[k]);
                    }
                    printf("\n");
                }
                i=j=0;
            }
        }
        else
        {
            printf("}\n");
            break;
        }
    }
}
