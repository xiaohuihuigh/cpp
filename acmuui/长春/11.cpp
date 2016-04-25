#include<iostream>
using namespace std;
struct xiaojin{
private:
    int nian;
public:
    xiaojin(int x = 0){
    nian = x;
    }
    int get(){
        return nian;
    }
};
    int main(){
    xiaojin x;
    cout<<x.get();
}







