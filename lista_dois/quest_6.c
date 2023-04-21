/*(Q6) uma função em C que, dada uma árvore binária qualquer, retire todos os elementos pares da
árvore original. A função deve ter o seguinte protótipo: TAB* retira_pares (TAB* arv);*/

#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.c"


int main(){
    TAB *a = TAB_inicializa(), *maior;

    a = TAB_cria(3, TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(1, NULL, NULL)), TAB_cria(5, TAB_cria(9, NULL, NULL), TAB_cria(10, TAB_cria(11, NULL, NULL), TAB_cria(8, TAB_cria(7, NULL, NULL), NULL))));

    TAB_imp_ident(a);
    maior = maior_ab(a);
    
    printf("o maior elemento da arvore é: %d \n", maior->info);

    TAB_libera(a);
 
    return 0;
}