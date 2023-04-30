/*(Q1) maior elemento da árvore: TABB* maior(TAB *a);*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_busca.c"

TABB *maior(TABB *a){
    if(!a){  /*caso 1: arvore vazia*/
        return NULL;
    }
    if(!a->dir){ /*caso 2: não existe direita */
        return a;
    }
    return maior(a->dir);
}

int main(){
    TABB *a = TABB_inicializa();

    a = TABB_cria(10, TABB_cria(8, TABB_cria(4, TABB_cria(2, NULL, NULL), NULL) ,TABB_cria(9,TABB_cria(5, NULL, NULL), TABB_cria(15, NULL, NULL))), TABB_cria(12, TABB_cria(11, NULL, NULL), TABB_cria(13, NULL, TABB_cria(17, NULL, NULL))));

    printf("arvore: \n");
    TABB_imp_ident(a);

    a = maior(a);
    printf("maior elemento da arvore: %d", a->info);
    
    TABB_libera(a);
    return 0;
}