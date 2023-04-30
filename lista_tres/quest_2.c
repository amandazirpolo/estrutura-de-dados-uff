/*(Q2) menor elemento da árvore: TABB* menor(TAB *a);*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_busca.c"

TABB *menor(TABB *a){
    if(!a) return NULL; /*caso 1 = arvore vazia */
    if(!a->esq) return a; /*caso 2 = não existe esquerda*/
    return menor(a->esq);
}

int main(){
    TABB *a = TABB_inicializa();

    a = TABB_cria(10, TABB_cria(8, TABB_cria(4, TABB_cria(2, NULL, NULL), NULL) ,TABB_cria(9,TABB_cria(5, NULL, NULL), TABB_cria(15, NULL, NULL))), TABB_cria(12, TABB_cria(11, NULL, NULL), TABB_cria(13, NULL, TABB_cria(17, NULL, NULL))));

    printf("arvore: \n");
    TABB_imp_ident(a);

    a = menor(a);
    printf("menor elemento da arvore: %d", a->info);
    
    TABB_libera(a);
    return 0;
}