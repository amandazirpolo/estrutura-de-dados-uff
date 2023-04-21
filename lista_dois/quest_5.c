/*(Q5) uma função que, dadas duas árvores deste tipo, testa se estas árvores são iguais. A função
retorna um se elas são iguais e zero, caso contrário. A função deve obedecer ao seguinte protótipo:
int igual (TAB* a1, TAB* a2);*/

#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.c"

int igual(TAB *a, TAB *b){
    if(!a && !b){
        return 1; /*se retornar 1 então todas as condições foram satisfeitas*/
    }
    if(!a || !b || a->info != b->info){
        return 0; /*se retornar 0 então alguma condição não foi satisfeita*/
    }
    return igual(a->esq, b->esq) && igual(a->dir, b->dir);
}

int main(){
    TAB *a = TAB_inicializa(), *b = TAB_inicializa();

    a = TAB_cria(3, TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(1, NULL, NULL)), TAB_cria(5, TAB_cria(9, NULL, NULL), TAB_cria(10, TAB_cria(11, NULL, NULL), TAB_cria(8, TAB_cria(7, NULL, NULL), NULL))));

    b = TAB_cria(3, TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(1, NULL, NULL)), TAB_cria(5, TAB_cria(9, NULL, NULL), TAB_cria(10, TAB_cria(50, NULL, NULL), TAB_cria(8, TAB_cria(7, NULL, NULL), NULL))));

    printf("arvore a: \n");
    TAB_imp_ident(a);
    printf("\n\n\n arvore b: \n");
    TAB_imp_ident(b);

    if(igual(a, b)){
        printf("as arvores sao iguais. \n");
    } else {
        printf("as arvores sao diferentes. \n");
    }

    TAB_libera(a);
    TAB_libera(b);

    return 0;
}