#include<stdio.h>
char s;
int main(){
	while((s=getchar())&&(s!= EOF)){
		if(s != ' ')printf("%c",s);
	}
}
