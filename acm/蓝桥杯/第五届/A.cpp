#define MAX 26
struct Trie
{
	Trie *next[MAX];
	int v;//根据需要变化
}
Trie *root;
void creatTrie(char *str){
	int len = strlen(str);
	Trie *p = root,*q;
	for(int i = 0;i<len;i++){
		int id = str[i]-'0';
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
	Trie*p = root;
	for(int i = 0;i<len;i++){
		int id = str[i]-'0';//'0'根据需要变化
		p = p->next[id];
		if(p == NULL)return 0;//不存在以此为前缀的串
		if(p->v ==-1)return -1;//有串为此串的前缀
	}
	return 1;//此串为某串的前缀
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













