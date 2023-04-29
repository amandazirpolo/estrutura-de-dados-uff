/*Verificar se uma árvore é estritamente binária, isto é, os nós dessa 
árvore possuem ou zero ou dois filhos - int estbin(TAB *a);*/

#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.c"

int est_bin(TAB *a){
    if(!a){
        return -1;
    }
    int valor;

    if((!a->esq && !a->dir) || (a->esq && a->dir)){
        valor = est_bin(a->esq); /*primeiro verifica os nós da esquerda */
        valor = est_bin(a->dir); /*agora verifica os nós da direita */
        return 1;
    }
    return 0;
}

int main(){
    TAB *a = TAB_inicializa();
    int eb;

    a = TAB_cria(10, TAB_cria(11, TAB_cria(14, NULL, NULL), TAB_cria(15, NULL, NULL)), TAB_cria(13, TAB_cria(16, NULL, NULL), TAB_cria(17, NULL, NULL)));

    printf("arvore: \n");
    TAB_imp_ident(a);

    eb = est_bin(a);
    if(eb){
        printf("\n a arvore eh estritamente binaria \n");
    } else {
        printf("\n a arvore nao eh estritamente binaria \n");
    }
        
    TAB_libera(a);
    return 0;
}