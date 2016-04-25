#include<cstdlib>

#include<iostream>
#include<bits/stdc++.h>
#define LEN 110

using namespace std;

char s[200];         // 输入串

int k;               // 输入参数

int result[LEN] ;        // 存放结果

void M2AA(int a[], int b[], int b1, int c[],int c1)

// 被乘数a,可有c1位，乘数b有b1位（b1可以为1，或大于1），积c有c1位。

{

   int i,j;

   for(i=0;i<c1;i++)     c[i]=0;

   if (b1 > c1) b1 = c1; // 取乘数的有效位



    for(i=0; i<b1; i++)  // 乘数

   {   if (b[i])

      {

         for(j=0; j<c1-i; j++)  // 被乘数

         {

           c[i+j] = a[j]*b[i] + c[i+j];

            c[i+j+1]= c[i+j+1] + c[j+i]/10;

           c[i+j] = c[i+j]%10;

          }

       }

    }

}

int main()

{

    int a[LEN],b[LEN],c[LEN],aa[LEN];

    int i,j,tp,num,n;

    cin>>s>>k;

    n=strlen(s);

    for(i=0;i<n;i++)

          a[n-i-1] = s[i] - '0';          // 将字符转换为数字保存在a数组中。

      for (i=0; i<k; i++) aa[i] = a[i];    // 将原数保存在aa中

    result[0]=1;

    for(i=0; i<k; i++)

    {

         for(j=0;j<=i;j++) b[j]=aa[j];

         tp=b[i];

         num=0;

         do

         {

               M2AA(a, b, i+1, c, i+1);

               num++;

               for(n=0; n<k; n++)  b[n]=c[n];

         } while ((num<10) && (b[i]!=tp));



         if(b[i]!=tp)

         {

           cout<<-1<<endl;

            return 0;

         }

         for(j=0;j<k;j++)

             b[j] = a[j];

         for(j=0;j<num-1;j++) // 求a=a^num

         {

             M2AA(a, b, k, c, k);

             for(n=0;n<LEN;n++)

                 a[n]=c[n];

         }

         M2AA(result, &num,1, c, LEN);

         for(n=0; n<LEN; n++)

             result[n]=c[n];

     }

     for (i=LEN-1; result[i]==0; i--);

     for( ; i>=0 ; i--)

        cout<<result[i];

     return 0;

}  /* #include<stdio.h>
#include<stdlib.h>
int main()
{
 long int t=0,k,n,i,i1,i2,a[1000];
 scanf("%ld%ld",&k,&n);
 i=n;
 i1=0;
 while(i!=0)
 {
	  a[i1]=i%2;
	  i=i/2;
	  i1++;
 }
 i2=1;
 if(a[0]==1)
	t=1;
 for(i=1;i<i1;i++)
 {
	i2=i2*k;
	if(a[i]==1)
	t+=i2;
 }
 printf("%ld\n",t);
}*/
/*#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 410;

struct bign
{
    int len, s[MAXN];
    bign ()
    {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    bign (int num) { *this = num; }
    bign (const char *num) { *this = num; }
    bign operator = (const int num)
    {
        char s[MAXN];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    bign operator = (const char *num)
    {
        for(int i = 0; num[i] == '0'; num++) ;  //去前导0
        len = strlen(num);
        for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
        return *this;
    }
    bign operator + (const bign &b) const //+
    {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; g || i < max(len, b.len); i++)
        {
            int x = g;
            if(i < len) x += s[i];
            if(i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }
    bign operator += (const bign &b)
    {
        *this = *this + b;
        return *this;
    }
    void clean()
    {
        while(len > 1 && !s[len-1]) len--;
    }
    bign operator * (const bign &b) //*
    {
        bign c;
        c.len = len + b.len;
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < b.len; j++)
            {
                c.s[i+j] += s[i] * b.s[j];
            }
        }
        for(int i = 0; i < c.len; i++)
        {
            c.s[i+1] += c.s[i]/10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }
    bign operator *= (const bign &b)
    {
        *this = *this * b;
        return *this;
    }
    bign operator - (const bign &b)
    {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; i < len; i++)
        {
            int x = s[i] - g;
            if(i < b.len) x -= b.s[i];
            if(x >= 0) g = 0;
            else
            {
                g = 1;
                x += 10;
            }
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    }
    bign operator -= (const bign &b)
    {
        *this = *this - b;
        return *this;
    }
    bign operator / (const bign &b)
    {
        bign c, f = 0;
        for(int i = len-1; i >= 0; i--)
        {
            f = f*10;
            f.s[0] = s[i];
            while(f >= b)
            {
                f -= b;
                c.s[i]++;
            }
        }
        c.len = len;
        c.clean();
        return c;
    }
    bign operator /= (const bign &b)
    {
        *this  = *this / b;
        return *this;
    }
    bign operator % (const bign &b)
    {
        bign r = *this / b;
        r = *this - r*b;
        return r;
    }
    bign operator %= (const bign &b)
    {
        *this = *this % b;
        return *this;
    }
    bool operator < (const bign &b)
    {
        if(len != b.len) return len < b.len;
        for(int i = len-1; i >= 0; i--)
        {
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        }
        return false;
    }
    bool operator > (const bign &b)
    {
        if(len != b.len) return len > b.len;
        for(int i = len-1; i >= 0; i--)
        {
            if(s[i] != b.s[i]) return s[i] > b.s[i];
        }
        return false;
    }
    bool operator == (const bign &b)
    {
        return !(*this > b) && !(*this < b);
    }
    bool operator != (const bign &b)
    {
        return !(*this == b);
    }
    bool operator <= (const bign &b)
    {
        return *this < b || *this == b;
    }
    bool operator >= (const bign &b)
    {
        return *this > b || *this == b;
    }
    string str() const
    {
        string res = "";
        for(int i = 0; i < len; i++) res = char(s[i]+'0') + res;
        return res;
    }
};

istream& operator >> (istream &in, bign &x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream& operator << (ostream &out, const bign &x)
{
    out << x.str();
    return out;
}
int main(){
	bign n;
	int k;
	cin>>n;
	cin>>k;
	bign mod = "1";
	for(int i = 0;i<k;i++)mod  = mod*10;
	//cout<<"mod"<<mod<<endl;
	n = n%mod;
	bign a1,a2;
	a1 = n;int cnt = 0;
	while(1){
		a1 = a1*n;
		a1 = a1%mod;
		cnt ++;
		//cout<<a1<<endl;
		if(a1 == n)break;
	}
	cout<<cnt<<endl;
}

int main()
{
    bign a, b, c, d, e, f, g;
    while(cin>>a>>b)
    {
        a.clean(), b.clean();
        c = a+b;
        d = a-b;
        e = a*b;
        f = a/b;
        g = a%b;
        cout<<"a+b"<<"="<<c<<endl; // a += b
        cout<<"a-b"<<"="<<d<<endl; // a -= b;
        cout<<"a*b"<<"="<<e<<endl; // a *= b;
        cout<<"a/b"<<"="<<f<<endl; // a /= b;
        cout<<"a%b"<<"="<<g<<endl; // a %= b;
        if(a != b) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}*/
