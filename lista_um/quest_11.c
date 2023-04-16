/*Defina uma função em C que, dada uma lista l qualquer, ordene os elementos de l
em uma outra lista de saída. Portanto, a lista de entrada não pode ser alterada. O
protótipo da função desta função é o seguinte: TLSE * ordena (TLSE* l).*/

#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

TLSE *ordena(TLSE *l){
    TLSE *laux = tlse_inicializa(), *aux = l;

    while(aux != NULL){
        laux = tlse_insere_ordenado_recursivo(laux, aux->info);
        aux = aux->prox;
    }
    return laux;
}

int main(){
    TLSE *lista = tlse_inicializa(), *lista_ordenada = tlse_inicializa();
    int el, n;

    printf("tam de elementos na lista: \n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("elemento %d: \n", i+1);
        scanf("%d", &el);
        lista = tlse_insere_final(lista, el);
    }

    tlse_imprime(lista);

    lista_ordenada = ordena(lista);
    printf("lista ordenada: \n");
    tlse_imprime(lista_ordenada);

    tlse_libera(lista);
    tlse_libera(lista_ordenada);

    return 0;
}