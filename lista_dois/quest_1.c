/*(Q1) cópia de uma árvore: TAB* copia (TAB *a);*/

#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.c"

TAB *copia_arvore(TAB *a){
    if (!a){
        return a;
    }
    return TAB_cria(a->info, copia_arvore(a->esq), copia_arvore(a->dir));
}

int main(){
    TAB *a = TAB_inicializa(), *a_aux = TAB_inicializa();

    a = TAB_cria(3, TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(1, NULL, NULL)), TAB_cria(5, TAB_cria(9, NULL, NULL), TAB_cria(10, TAB_cria(11, NULL, NULL), TAB_cria(8, TAB_cria(7, NULL, NULL), NULL))));

    a_aux = copia_arvore(a);

    TAB_imp_ident(a);
    printf("copia da arvore binaria: \n\n\n");
    TAB_imp_ident(a_aux);

    TAB_libera(a);
    TAB_libera(a_aux);
 
    return 0;
}