/*(Q3) maior elemento da árvore: TAB* maior(TAB *a);*/

#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.c"

TAB *compara(TAB *no_antigo, TAB *no_arvore){
    if(!no_arvore){
        return no_antigo;
    }
    no_antigo = compara(no_antigo, no_arvore->esq);
    if(no_antigo->info < no_arvore->info){
        return no_arvore;
    }
    no_antigo = compara(no_antigo, no_arvore->dir);
    if(no_antigo->info < no_arvore->info){
        return no_arvore;
    }
    return no_antigo;    
}

TAB *maior_ab(TAB *a){
    if(!a){
        return a;
    }
    TAB *aux = a;
    return compara(aux, a);
}

int main(){
    TAB *a = TAB_inicializa(), *maior;

    a = TAB_cria(3, TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(1, NULL, NULL)), TAB_cria(5, TAB_cria(9, NULL, NULL), TAB_cria(10, TAB_cria(11, NULL, NULL), TAB_cria(8, TAB_cria(7, NULL, NULL), NULL))));

    TAB_imp_ident(a);
    maior = maior_ab(a);
    
    printf("o maior elemento da arvore é: %d \n", maior->info);

    TAB_libera(a);
 
    return 0;
}