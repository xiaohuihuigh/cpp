#include<stdio.h>
 int GCD(int x, int y)
 {
     int z;
    while(x % y != 0 && y%x != 0)
    {
        if(x > y)
        {
            z = x - y;
            x = z;
        }
        else
        {
            z = y - x;
            y = z;
        }
    }
    if(x > y)
        return y;
    else
        return x;
}
 int main()
 {
    int a,b,c,d,n = 1,gcd,lcm;
    while(scanf("%d",&a) == 1 && scanf("%d",&b) == 1){
        printf("Case %d:\n",n++);
        if(a < 0)
            c = -a;
        else
            c = a;
        if(b < 0)
            d = -b;
        else
            d = b;
        if(a == 0 && b == 0)
            printf("no GCD\nno LCM\n\n");
        else if(a != 0 && b != 0){

            printf("GCD(%d,%d) = %d\nLCM(%d,%d) = %d\n\n",a,b,GCD(c,d),a,b,c*d/GCD(c,d));
         }
        else if(a == 0){
            printf("GCD(%d,%d) = %d\nno LCM\n\n",a,b,d);
         }
         else if(b == 0){
            printf("GCD(%d,%d) = %d\nno LCM\n\n",a,b,c);
         }

    }
    return 0;
}
