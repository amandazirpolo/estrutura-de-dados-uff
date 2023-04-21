/*(Q9) ache a quantidade de nós folha: int nf(TAB *a);*/

#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.c"

int nf(TAB *a){
    if(!a){
        return 0;
    }
    if(!a->esq && !a->dir){
        return 1;
    }
    return nf(a->esq) + nf(a->dir);
}

int main(){
    TAB *a = TAB_inicializa();

    a = TAB_cria(3, TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(1, NULL, NULL)), TAB_cria(5, TAB_cria(9, NULL, NULL), TAB_cria(10, TAB_cria(11, NULL, NULL), TAB_cria(8, TAB_cria(7, NULL, NULL), NULL))));

    printf("arvore: \n");
    TAB_imp_ident(a);

    printf("\n\n numero de nos folha da arvore: %d", nf(a));
    
    TAB_libera(a);
    return 0;
}