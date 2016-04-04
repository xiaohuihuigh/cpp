#include<cstdio>
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
#define MAX 26
struct Trie
{
	Trie *next[MAX];
	int v;//根据需要变化
};
Trie root;
void init(){
	for(int i = 0;i<MAX;i++){
		root.next[i] = NULL;
	}
}
void creatTrie(char *str){
	int len = strlen(str);
	Trie *p = &root,*q;
	for(int i = 0;i<len;i++){
		int id = str[i]-'a';
		if(p->next[id] == NULL){
			q = (Trie*)malloc(sizeof(Trie));
			q->v = 1;
			for(int j = 0;j<MAX;++j)
				q->next[j] = NULL;
			p->next[id] = q;
		}
		else{
			p->next[id]->v++;
		}
		p = p->next[id];
	}
	p->v = -1;//结尾将v变为-1
}
int findTrie(char *str){
	int len = strlen(str);
	Trie*p = &root;
	for(int i = 0;i<len;i++){
		int id = str[i]-'a';//'0'根据需要变化
		p = p->next[id];
		if(p == NULL)return 0;//不存在以此为前缀的串
		if(i == len-1&&p->v == -1)return 1;
		if(p->v ==-1)return 0;//有串为此串的前缀
	}
	return p->v;//此串为某串的前缀
}
//为了避免超内存
int dealTrie(Trie*T){
	int i;
	if(T == NULL)return 0;
	for(int i = 0;i<MAX;i++){
		if(T->next[i]!=NULL){
			dealTrie(T->next[i]);
		}
	}
	free(T);
	return 0;
}

int main(){
	string s;
	init();
	while(getline(cin,s)&&s.size()){
		creatTrie((char*)s.c_str());
	}
	while(cin>>s){
		cout<<findTrie((char*)s.c_str())<<endl;
	}
	dealTrie(&root);
	return 0;
}











