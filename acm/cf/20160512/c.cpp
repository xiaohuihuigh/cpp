#include<bits/stdc++.h>
using namespace std;
const int maxn = 100050;
double x[maxn];
double y[maxn];
double c[maxn];
int main(){
    double ax,ay,bx,by,tx,ty;
    while(cin>>ax){
        cin>>ay>>bx>>by>>tx>>ty;
        int n;
        cin>>n;
        double mina = 0,minb = 0;
        double ans = 0;
        double sum = 0;
        for(register int i = 0;i<n;i++){
            cin>>x[i]>>y[i];
            double t;
            t = sqrt((x[i] - tx)*(x[i] - tx)+(y[i] - ty)*(y[i] - ty));
            c[i] = t;
            ans+=2*c[i];
        }
        for(register int i = 0;i<n;i++){
            double a,b,t;
            a = sqrt((x[i] - ax)*(x[i] - ax) +(y[i] - ay)*(y[i] - ay));
            t = sqrt((x[i] - tx)*(x[i] - tx) +(y[i] - ty)*(y[i] - ty));
            b = sqrt((x[i] - bx)*(x[i] - bx) +(y[i] - by)*(y[i] - by));
            c[i] = t;
            double s = t-a;
            if(s>mina){
                mina = s;
            }
            else if(s>minb){
                minb = s;
            }
        }
        sum = max(sum,mina+minb);
        mina = 0,minb = 0;
        for(register int i = 0;i<n;i++){
            double a,b,t;
            a = sqrt((x[i] - ax)*(x[i] - ax) +(y[i] - ay)*(y[i] - ay));
            t = sqrt((x[i] - tx)*(x[i] - tx) +(y[i] - ty)*(y[i] - ty));
            b = sqrt((x[i] - bx)*(x[i] - bx) +(y[i] - by)*(y[i] - by));
            c[i] = t;
            double s = t-a;
//          cout<<s<<"s"<<endl;
            if(s>minb){
                mina = s;
            }
            else if(s>mina){
                minb = s;
            }
        }
        sum = max(sum,mina+minb);
        cout<<sum<<endl;
//            else if(s>minna){
//                minna = s;
//                minnax = i;
//            }
//            s = t-b;
////                cout<<s<<"s"<<endl;
//            if(s>minb){
//                minnb = minb;
//                minnbx = minbx;
//                minb = s;
//                minbx = i;
//            }
//            else if(s>minnb){
//                minnb = s;
//                minnbx = i;
//            }
//        cout<<minax<<" "<<minbx<<" "<<endl;
//        cout<<minnax<<" "<<minnbx<<" "<<endl;
//        printf("%.12lf\n",ans);
        cout<<sum<<endl;

        printf("%.10f\n",ans - sum);
    }
}
