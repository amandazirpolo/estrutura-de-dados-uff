/*Escreva uma função em C que, dada uma lista l qualquer, desloque uma vez os
elementos de l, de acordo com n. Se n é ímpar, o elemento que está na última posição
passa a ser o primeiro quando a lista é deslocada. Senão, o elemento que está na
primeira posição passa a ser o último. O protótipo desta função é o seguinte: TLSE*
desloca (TLSE* l, int n).*/

#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

TLSE *desloca(TLSE *lista, int n){
    TLSE *aux = lista, *ant = NULL;

    while(aux->prox != NULL){
        ant->prox = aux;
        aux = aux->prox;
    }
    if(n % 2 == 0){
        aux->prox = lista;
        lista = lista->prox;
        aux->prox->prox = NULL;
        return lista;
    }
    aux->prox = lista;
    ant->prox = NULL;
    return aux;
}

int main(){
    TLSE *lista = tlse_inicializa(), *lista_dois = tlse_inicializa();
    int el, n, tam;

    printf("entre com o tamanho da lista: \n");
    scanf("%d", &tam);
    for(int i = 0; i < tam; i++){
        printf("elemento %d: \n", i+1);
        scanf("%d", &el);
        lista = tlse_insere_final(lista, el);
    }
    
    tlse_imprime(lista);

    printf("entre com um valor n: \n");
    scanf("%d", &n);

    lista_dois = desloca(lista, n);
    printf("lista deslocada: \n");
    tlse_imprime(lista_dois);

    tlse_libera(lista);
    tlse_libera(lista_dois);

    return 0;
}