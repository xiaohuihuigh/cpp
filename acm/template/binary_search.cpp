
#include<iostream>
using namespace std;

int main(){
    int a[] = {0,0,0,1,1,2,3,4,4,4,4,5,8};
    int n = 13;
//ok_left,no_right
    int find;
    while(cin>>find){
        int l = 0;int r = n-1;
        while(l<r){
            int mid = (l+r)/2;
            if(a[mid]>=find) r = mid;
            else l = mid+1;
        }
        cout<<r<<endl;
//no_left,ok_right
        l = 0;r = n-1;
        while(l<r){
            int mid = (l+r-1)/2+1;
            if(a[mid]<=find) l = mid;
            else r = mid-1;
        }
        cout<<l<<endl;
    }

}
