#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000+100;
int id[maxn],x[maxn],n;
bool isStack(){
	stack<int >s;
	for(int i = 0;i<n;i++){
		if(id[i] == 1)s.push(x[i]);
		else{
			if(s.empty())return false;
			int val = s.top(); s.pop();
			if(x[i]!=val)return false;
		}
	}
	return true;
}
bool isQueue(){
	queue<int>q;
	for(int i = 0;i<n;i++){
		if(id[i] == 1)q.push(x[i]);
		else{
			if(q.empty())return false;
			int val = q.front(); q.pop();
			if(x[i]!=val)return false;
		}
	}
	return true;
}
bool isPriority(){
	priority_queue <int > q;
	for(int i = 0;i<n;i++){
		if(id[i] == 1)q.push(x[i]);
		else{
			if(q.empty())return false;
			int val = q.top(); q.pop();
			if(x[i]!=val)return false;
		}
	}
	return true;
}
int main(){
	while(cin>>n){
		for(int i = 0;i<n;i++)cin>>id[i]>>x[i];
		int  st=0,qu=0,pq=0;
		st = isStack();qu = isQueue();pq = isPriority();
		int sum = st+qu+pq;
		if(sum == 0)cout<<"impossible"<<endl;
		else if(sum>1)cout<<"not sure"<<endl;
		else if(st) cout<<"stack"<<endl;
		else if(qu) cout<<"queue"<<endl;
		else if(pq) cout<<"priority queue"<<endl;
	}
}





