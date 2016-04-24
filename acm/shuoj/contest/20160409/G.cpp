#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000;
int we[20];
int we2[20];/*
int jinwei(int j){
	for(int i = 0;i<=j;i++){
		if(we[i]>=10){
			we[i+1]+=1;
			we[i] = we[i]%10;
		}
	}
	if(we[j]!= 0)
	return j+1;
	else return j;
}
int mainn(int n){
	int t;
	cin>>t;
	while(t--){
	int n;
		cin>>n;
		memset(we,0,sizeof(we));
		int j = 0;
		int m = n;
		while(n){
			we[j] = n%10;
			n/=10;
			j++;
		}
		int w = 0;
		//if(m<=888){cout<<888<<endl;continue;}
		//if(m<=888){cout<<888<<endl;return ;}
		//if(m<1000){cout<<1888<<endl;continue;}
		//if(m<1000){cout<<1888<<endl;return ;}
		for(int i = 0;i<j;i++)if(we[i] == 8)w++;
		//for(int i = 0;i<j;i++)cout<<we[i]<<w;
		while(w!= 3){
			if(w>3){
				for(int i = 0;i<j;i++){
					if(we[i] == 8){ we[i] = 9;w--;}
					if(w <= 3) break;
				}
			}
			if(w <3){
				for(int k = 0;k<j;k++){
					if(we[k]!= 8){
						if(we[k]<8){we[k] = 8;w++;}
						else if(we[k] == 8);
						else if(we[k] == 9&&we[k+1]==7&&w ==2){we[k] = 0;we[k+1]=8;w++;if(w >= 3) break;}

						else{
							we[k+1]+=1;
							we[k] = 8;
							//cout<<k<<" "<<we[k]<<endl;
							j = jinwei(j);
							w = 0;
							for(int i = 0;i<j;i++)if(we[i] == 8)w++;
						}
						if(w >= 3) break;
					}
				}//for(int i = j-1;i>=0;i--)cout<<i<<"sd "<<we[i]<<endl;;

			}
		}
		for(int i = j-1;i>=0;i--)cout<<we[i];
		cout<<endl;
	}
}
*//*
int main(){
for(int i = 10000;i<1000000000;i++){
	mainn(i);
	int s;int jj = 0;
	for(int j = i;;j++){
		int n = j;
		s = 0;
		while(n){
			we2[s] = n%10;
			n/=10;
			s++;
		}
		int w = 0;
		for(int k = 0;k<s;k++)if(we2[k] == 8)w++;
		if(w == 3){jj = j;break;}
	}
	int f = 0;
	for(int q = 0;q<s+1;q++)if(we[q]!= we2[q]){f = 1;break;}
	if(f == 1){cout<<i<<"     "<<jj<<"   ";
	for(int q = s+1;q>=0;q--)cout<<we[q];
	cout<<endl;}
}
}*/int main(){
	int t;
	cin>>t;
	while(t--){
	int s;int jj = 0;
	int m;
	cin>>m;
	for(int j = m;;j++){
		int n = j;
		s = 0;
		while(n){
			we2[s] = n%10;
			n/=10;
			s++;
		}
		int w = 0;
		for(int k = 0;k<s;k++)if(we2[k] == 8)w++;
		if(w == 3){jj = j;break;}
	}
	for(int q = s-1;q>=0;q--)cout<<we2[q];
	cout<<endl;
	}
}

