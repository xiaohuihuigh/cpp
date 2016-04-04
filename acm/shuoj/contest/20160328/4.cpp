#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s=0;
int r=0,jishu=0;
int x[100],y[100];
int xt[100],yt[100];
int cnt[100];
int xx[100][2],yy[100][2];
ll ans;

bool inin(int x1,int x2,int y1,int y2,int x3,int x4,int y3,int y4){
	if(x1>=x3&&x1<=x4&&y1>=y3&&y1<=y4)return 1;
	if(x1>=x3&&x1<=x4&&y2>=y3&&y2<=y4)return 1;
	if(x2>=x3&&x2<=x4&&y2>=y3&&y2<=y4)return 1;
	if(x2>=x3&&x2<=x4&&y1>=y3&&y1<=y4)return 1;
	return 0;
}
void zuhe(int k,int n,int kk)
{
	if(k==kk){
	int mix = 600,miy = 600,maax = 0,may = 0;
		for(int j = cnt[k-1]+1;j<=n;j++){
					mix = min(x[j],mix);
					miy = min(y[j],miy);
					maax = max(x[j],maax);
					may = max(y[j],may);}
					//cout<<maax<<" "<<mix<<" "<<may<<" "<<miy<<endl;
					xx[k][0] = mix;xx[k][1]  = maax;
					yy[k][0] = miy;yy[k][1]  = may;
					int yn = 0;
					for(int tt = 0;tt<k;tt++){
					if(inin(mix,maax,miy,may,xx[tt][0],xx[tt][1],yy[tt][0],yy[tt][1])){
						yn = 1;break;
					}
				}
				if(yn == 1);
				else {s+=(maax - mix)*(may- miy);
				cout<<s<<endl;
				ans = min(ans,s);
				s-=(maax - mix)*(may- miy);}
	}
	else{
		for(int i=r;i<n;i++){
			r=i+1;
			cnt[k] = i;
			int mix = 600,miy = 600,maax = 0,may = 0;
			for(int j = cnt[k-1]+1;j<=cnt[k];j++){
				mix = min(x[j],mix);
				miy = min(y[j],miy);
				maax = max(x[j],maax);
				may = max(y[j],may);}
				xx[k][0] = mix;xx[k][1]  = maax;
				yy[k][0] = miy;yy[k][1]  = may;
				int yn = 0;
				for(int tt = 0;tt<k;tt++){
					if(inin(mix,maax,miy,may,xx[tt][0],xx[tt][1],yy[tt][0],yy[tt][1])){
						yn = 1;break;
					}
				}
				if(yn == 1)continue;
			//ŝ	cout<<maax<<" "<<mix<<" "<<may<<" "<<miy<<endl;
			s+=(maax - mix)*(may- miy);
			zuhe(k+1,n,kk);
			s-=(maax - mix)*(may- miy);

			r=0;
		}
	}
}
int main()
{
	int n,k;
	while(cin>>n>>k){
		for(int i = 0;i<n;i++){
			cin>>xt[i]>>yt[i];
		}
		s=0,r=0;
		 ans = 0x3f3f3f3f;
		 cnt[0] = -1;

			for(int j = 0;j<=n;j++){
			 for(int i  = 0;i<n;i++){
				x[i] = xt[i+j];
				y[i] = yt[i+j];
			}
			zuhe(1,n-1,k);
		 }

		 cout<<ans<<endl;
	}
	 return 0;
}

/*f
5 2
1 1
1 3
2 2
3 3
4 2

*/
