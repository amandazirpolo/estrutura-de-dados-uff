/*(Q6) uma função em C que, dada uma árvore binária qualquer, retire todos os elementos pares da
árvore original. A função deve ter o seguinte protótipo: TAB* retira_pares (TAB* arv);*/

#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.c"

TAB *retira_pares(TAB *a){
    if(!a){
        return a;
    }
    a->esq = retira_pares(a->esq); // percorre a arvore usando recursão
    a->dir = retira_pares(a->dir);
    if(a->info % 2 == 0){ /*se a for um numero par*/
        if(!a->esq && !a->dir){
            free(a);     /*caso 1: o nó é uma folha*/
            a = NULL;
        } else if (!a->esq || !a->dir){
            TAB *aux = a;
            if(!a->esq){
                a = a->dir;  /*caso 2: o nó tem um filho (o ponteiro a troca o filho pelo
                            pai e remove o filho pois agr é o ultimo no)*/
            } else {  
                a = a->esq;
            }
            free(aux);
        } else if (a->esq && a->dir){
            TAB *aux = a->esq;
            while(aux->dir){
                aux = aux->dir;
            }
            a->info = aux->info;
            aux->info = 2; /*força a ser par*/
            a = retira_pares(a);
        }
    }
    return a;
}

int main(){
    TAB *a = TAB_inicializa();

    a = TAB_cria(3, TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(1, NULL, NULL)), TAB_cria(5, TAB_cria(9, NULL, NULL), TAB_cria(10, TAB_cria(11, NULL, NULL), TAB_cria(8, TAB_cria(7, NULL, NULL), NULL))));

    printf("arvore original: \n");
    TAB_imp_ident(a);

    printf("\n\n arvore sem pares: \n");
    a = retira_pares(a);
    TAB_imp_ident(a);
    
    TAB_libera(a);
 
    return 0;
}