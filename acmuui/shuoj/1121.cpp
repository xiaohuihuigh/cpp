#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include<iostream>
using namespace std;
int main()
{
    int n,i,sum = 0;
    cin>>n;
    for(i = 1;;i++)
    {
        sum = sum +i*i*i;
        if(sum > n)
        break;
    }
    cout<<i-1;
    return 0;
}
/**************************************************************
    Problem: 1121
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1560 kb
****************************************************************/
