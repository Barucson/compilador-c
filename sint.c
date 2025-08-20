#include "analex.h"

void S();
void E();
void T();
void E_linha();
void T_linha();
void F();
void erro_sintatico();

int token;

void consome(int t){
    if(token == t)
        token = analex();
    else   
        erro_sintatico();
}

void S(){
    E();
}

void E(){
    T();
    E_linha();
}

void E_linha(){
    if(token == '+'){
        consome('+');
        T();
        E_linha();
    } else if(token == '-'){
        consome('-');
        T();
        E_linha();
    }
}

void T(){
    F();
    T_linha();
}

void T_linha(){
    if(token == '*'){
        consome('*');
        F();
        T_linha();
    } else  if(token == '/'){
        consome('/');
        F();
        T_linha();
    }
}

void F(){
    if(token == ID)
        consome(ID);
    else if(token == NUM)
        consome(NUM);
    else if(token == '('){
        consome('(');
        E();
        consome(')');
    } else {
        erro_sintatico();
    }
}

void erro_sintatico(){
    printf("Erro sintatico\n");
    exit(1);
}

int main(){
    token = analex();
    S();
    if(token != ';')
        erro_sintatico();
}