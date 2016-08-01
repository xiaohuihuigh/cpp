
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//算法在做闭右开的区间内进行查找
//如果所有的元素都比find小，则返回值越界
int main(){
    int a[] = {0,0,0,1,1,2,3,4,4,4,4,5,8};
    int n = 13;
    int l,r;
    int find;
    while(cin>>find){
        //ok_left,no_right
        l = 0;r = n;
        while(l<r){
            int mid = (l+r)/2;
            if(a[mid]>=find) r = mid;
            else l = mid+1;
        }
        cout<<l<<endl;
        //no_left,ok_right
        l = 0;r = n;
        while(l<r){
            int mid = (l+r-1)/2+1;
            if(a[mid]<=find) l = mid;
            else r = mid-1;
        }
        cout<<l<<endl;
        //ok_left,no_right
        cout<<lower_bound(a,a+n,find) - a<<endl;
        //ok_right+1,no_right
        cout<<upper_bound(a,a+n,find) - a<<endl;
    }
}
