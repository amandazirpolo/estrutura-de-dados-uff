/* Testar se uma árvore é zigue-zague, isto é, todos os nós internos
 possuem exatamente uma sub-árvore vazia - int zz(TAB *a);*/

#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.c"

int zigue_zague(TAB *a){
    if(!a){
        return -1;
    }
    int valor;
    
    if(!a->esq || !a->dir){
        if(!a->esq && a->dir){
            valor = zigue_zague(a->dir);
            return 1;
        }
        else if(!a->dir && a->esq){
            valor = zigue_zague(a->esq);
            return 1;
        }
    }
    return 0;
}

int main(){
    TAB *a = TAB_inicializa();
    int zz;

    a = TAB_cria(10, NULL, TAB_cria(11, TAB_cria(12, NULL, TAB_cria(13, TAB_cria(14, NULL, NULL), NULL)), NULL));

    printf("arvore: \n");
    TAB_imp_ident(a);

    zz = zigue_zague(a);
    if(zz){
        printf("\n a arvore eh em zigue zague \n");
    } else {
        printf("\n a arvore nao eh em zigue zague \n");
    }
        
    TAB_libera(a);
    return 0;
}