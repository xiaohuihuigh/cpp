#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;
const int LIMITS = 100;
char str[10];
char piles[LIMITS][LIMITS][10];
int top_piles[LIMITS];
int num_piles;

bool Match(char* card_1,char* card_2){
	return card_1[0] == card_2[0]
	||card_1[1] == card_2[1];
}
bool Match(int x,int y){
	return piles[x][top_piles[x]-1][0] == piles[y][top_piles[y]-1][0]
		||piles[x][top_piles[x]-1][1] == piles[y][top_piles[y]-1][1] ;
}
bool Move(int pos_1,int pos_2){
	int &top_1 = top_piles[pos_1];
	int &top_2 = top_piles[pos_2];
	if(pos_1<0)return false;
	if(!Match(pos_1,pos_2))return false;
	strcpy(piles[pos_1][top_1],piles[pos_2][top_2-1]);
	++top_1;
	--top_2;
	if(!top_piles[pos_2]){
		for(int i = pos_2;i<num_piles-1;i++){
			top_piles[i] = top_piles[i+1];
			for(int j = 0;j<top_piles[i];j++){
				strcpy(piles[i][j],piles[i+1][j]);
			}
		}
		-- num_piles;
	}
	return true;
}
int main(){
	while(scanf("%s",str)){
	if(str[0] == '#')break;
	memset(piles,0,sizeof(piles));
	memset(top_piles,0,sizeof(top_piles));
	num_piles = 0;
	strcpy(piles[0][0],str);
	for(int i = 1;i<52;i++)scanf("%s",piles[i][0]);
	for(int i = 0;i<52;i++)top_piles[i] = 1;
	num_piles = 52;

	bool is_moved = true;
	while(is_moved){
		is_moved = false;
		for(int i = 0;i<num_piles;i++){
			if(Move(i-3,i)||Move(i-1,i)){
				is_moved = true;
				break;
			}
		}
	}
	printf("%d",num_piles);
	if(num_piles>1) cout<<" piles remaining:";
	else cout<<" pile remaining:";
	for(int i = 0;i<num_piles;i++){
		printf(" %d",top_piles[i]);
	}
	cout<<endl;
	}
	return 0;
}
