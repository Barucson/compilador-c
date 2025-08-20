#include <stdio.h>
#include <stdlib.h>

#define NUM 256
#define ID 257

void erro_lexico(){
    printf("Erro lexico\n");
    exit(1);
}

char c;
int analex(){
    c = getchar();

    if(c == '+')
        return '+';
    else if(c == '*')
        return '*';
    else if(c >= '0' && c <= '9')
        return NUM;
    else if(c >= 'a' && c<='z' || (c >= 'A' && c<= 'Z') )
        return ID;
    else if(c != '\n' && c != ';')
        erro_lexico();
}