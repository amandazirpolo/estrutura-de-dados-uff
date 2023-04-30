/*(Q3) uma função em C que, dada uma árvore binária de busca qualquer, retire todos os elementos
ímpares da árvore original. A função deve ter o seguinte protótipo: TABB*
retira_impares(TABB* a);*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_busca.c"

TABB *retira_impares(TABB *a){
    if(!a){
        return a;
    }
    a->esq = retira_impares(a->esq); /*começa de baixo para cima*/
    a->dir = retira_impares(a->dir);
    if(a->info % 2 != 0){
        if(!a->esq && !a->dir){ /*caso 1: é uma folha*/
            free(a);
            a = NULL;
        }
        else if(!a->esq || !a->dir){ /*caso 2: tem um filho só*/
            TABB *aux = a;
            if(a->esq){
                a = a->dir;
            } else{
                a = a->esq;
            }
            free(aux);
        } else { /*caso 3: tem dois filhos */
            TABB *aux = a->esq;
            int tmp;
            while(aux->dir){
                aux = aux->dir;
            }
            tmp = a->info; /*trocando o valor dos nós*/
            a->info = aux->info;
            aux->info = tmp;
            a = retira_impares(a);
        }
    }
    return a;
}

int main(){
    TABB *a = TABB_inicializa();

    a = TABB_cria(10, TABB_cria(8, TABB_cria(4, TABB_cria(2, NULL, NULL), NULL) ,TABB_cria(9,TABB_cria(5, NULL, NULL), TABB_cria(15, NULL, NULL))), TABB_cria(12, TABB_cria(11, NULL, NULL), TABB_cria(13, NULL, TABB_cria(17, NULL, NULL))));

    printf("arvore original: \n");
    TABB_imp_ident(a);

    printf("\n\n arvore sem impares: \n");
    a = retira_impares(a);
    TABB_imp_ident(a);
    
    TABB_libera(a);
    return 0;
}