/*Implemente uma função em C que, dadas duas listas, faça a concatenação das
mesmas ao final de l1. O protótipo da função é o seguinte: TLSE* junta_listas (TLSE*
l1, TLSE* l2).*/

#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

TLSE *junta_listas(TLSE *l1, TLSE *l2){
    TLSE *aux = l1;

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = l2;
    return l1;
}

int main(){
    TLSE *lista_um = tlse_inicializa(), *lista_dois = tlse_inicializa(), *lista_tres = tlse_inicializa();
    int el, n;

    printf("tam de elementos na lista 1: \n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("elemento %d: \n", i+1);
        scanf("%d", &el);
        lista_um = tlse_insere_final(lista_um, el);
    }

    printf("tam de elementos na lista 2: \n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("elemento %d: \n", i+1);
        scanf("%d", &el);
        lista_dois = tlse_insere_final(lista_dois, el);
    }

    tlse_imprime(lista_um);
    tlse_imprime(lista_dois);

    printf("listas concatenadas: \n");
    lista_tres = junta_listas(lista_um, lista_dois);
    tlse_imprime(lista_tres);

    tlse_libera(lista_um);
    tlse_libera(lista_dois);
    tlse_libera(lista_tres);

    return 0;
}