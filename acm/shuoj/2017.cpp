//首先不能暴力求解，类似于fast_mod，然后不能用‘%’效率太低了。

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
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
bign mod10n(bign t,int n) {
        if(t.len> n)
            t.len = n;
        while(t.len > 1 && t.s[t.len - 1] == 0)
            t.len--;
        return t;
    }
int getcircle(bign a, int k) {
    a = mod10n(a,k);
    bign x1 = a;
    int ans = 0;
    do {
        x1 *= a;
        x1 = mod10n(x1,k);
        ans++;
    }while(ans <= 10 && x1 != a);
    return ans > 10 ? -1 : ans;
}
int main()
{
    bign a, b , ans;
    int k;
    while(cin>>a>>k)
    {
        ans = 1;
        a.clean();
        for(int i = 1; i <= k; i++) {
            bign t = a;
            int c = getcircle(t, i);
            if(c < 0) {
                ans = -1;
                break;
            }
            ans *= c;
            t = 1;
            for(int j = 0; j < c; j++) {
                t *= a;
                t = mod10n(t,k);
            }
            a = t;
        }
        cout<<ans<<endl;
    }
    return 0;
}

//http://blog.csdn.net/yuyanggo/article/details/48225515
