#include <stdio.h>
#include <string.h>

int c[] = { 0, 0, 64, 32, 16, 8, 0, 4, 2, 1, 0};

int main() {
    char str[15];
    int value,i;
    gets(str);
    while(gets(str) && str[0] != '_'){
        value = 0;
        int len = strlen(str);
        for(i = 2;i < len;i++){
            if(str[i] == 'o'){
                value += c[i];
            }
        }
        printf("%c",value);
    }
}
