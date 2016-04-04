#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[7];
	while(true){
		int yn = 1;
		for(int i = 0;i<6;i++){
			cin>>a[i];
			if(a[i]!= 0)yn = 0;
		}
		if(yn == 1)break;
		int sum = a[0]+a[1];
		int del = a[0]+a[2]+a[4] - a[1] - a[3]-a[5];

		cout<<"Anna's won-loss record is "<<(sum-del)/2<<"-"<<(sum+del)/2<<"."<<endl;
	}
}
