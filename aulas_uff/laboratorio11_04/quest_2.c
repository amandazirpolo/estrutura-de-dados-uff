/*(Q2) Retornar todos os ancestrais de um nó na árvore B, da raiz da árvore até o elemento 
passado como parâmetro, usando a biblioteca de lista encadeada - TLSEINT* misc(TAB *a, int elem)*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.c"
#include "TLSEINT.c"
#include <limits.h>

void antecessores_aux(TAB *a, int elemento, int *resp){
    if(!a) return;
    if(a->info < elemento && a->info > (*resp)) (*resp) = a->info;
    antecessores_aux(a->esq, elemento, resp);
    antecessores_aux(a->dir, elemento, resp);
}

int antecessores(TAB *a, int elemento){
    int resp = INT_MIN; /*menor elemento da arvore*/
    antecessores_aux(a, elemento, &resp);
    return resp;
}

void sucessores_aux(TAB *a, int elemento, int *resp){
    if(!a) return;
    if(a->info > elemento && a->info < (*resp)) (*resp) = a->info;
    sucessores_aux(a->esq, elemento, resp);
    sucessores_aux(a->dir, elemento, resp);
}

int sucessores(TAB *a, int elemento){
    int resp = INT_MAX; /*maior elemento da arvore*/
    sucessores_aux(a, elemento, &resp);
    return resp;
}

TLSEINT *misc_aux(TAB *a, int elem, TLSEINT *lista){
    /*condição de parada*/
    if(a->info == elem || !a) return NULL;
    if(a->info != elem){
        /*percorre a lista usando recursão*/
        lista = TLSEINT_insere(misc_aux(a->esq, elem, lista), sucessores(a, elem), antecessores(a, elem));
        lista = TLSEINT_insere(misc_aux(a->dir, elem, lista), sucessores(a, elem), antecessores(a, elem));
    }
    return lista;
}

TLSEINT *misc(TAB *a, int elem){
    if(!a) return NULL;
    if(!TAB_busca(a, elem)) return NULL;
    TLSEINT *lista = TLSEINT_inicializa();
    return misc_aux(a, elem, lista);
}

int main(){
    TAB *a = TAB_inicializa();
    TLSEINT *lista = TLSEINT_inicializa();
    int el;

    a = TAB_cria(3, TAB_cria(5, TAB_cria(1, NULL, NULL), TAB_cria(2 ,TAB_cria(4, NULL, NULL), TAB_cria(6, NULL, NULL))), TAB_cria(8, TAB_cria(7, NULL, NULL), TAB_cria(9, NULL, NULL)));

    TAB_imp_ident(a);
    printf("\n\ndigite um elemento que esteja na arvore: \n");
    scanf("%d", &el);

    lista = misc(a, el);
    
    printf("lista de ancestrais com limites inferior e superior: \n");
    TLSEINT_imprime(lista);    

    TAB_libera(a);
    TLSEINT_libera(lista);

    return 0;
}