#include <stdio.h>
#include <stdlib.h>

// tipo da arvore binaria
typedef struct arvbin {
    int info;
    struct arvbin *esq, *dir;
} TAB;

// inicializa a arvore
TAB *TAB_inicializa(void){
    return NULL;
}

// cria a arvore
TAB *TAB_cria(int info, TAB *esq, TAB *dir){ // criar arvore n pode usar um metodo recursivo
    TAB *a = (TAB*)malloc(sizeof(TAB));
    a->info = info;
    a->esq = esq;
    a->dir = dir;
    return a;
}

int maior(int x, int y){
    if(x >= y){
        return x;
    }
    return y;
}

// calcula a altura da arvore
int calcula_altura(TAB *a){
    if(!a){
        return -1;
    }
    return 1 + maior(calcula_altura(a->esq), calcula_altura(a->dir));
}

int main(){
    TAB *a = TAB_inicializa();
    // cria da raiz para as folhas 
    a = TAB_cria(5, TAB_cria(3, NULL, NULL), TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(1, NULL, NULL)));
    return 0;
}