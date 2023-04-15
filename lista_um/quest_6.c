/*Defina uma função em C que, dada uma lista l qualquer, retorne, numa lista de saída,
os elementos ímpares e os elementos pares da lista l, na ordem em que os elementos
aparecem em l. Ao final da execução desta função, a lista resultante terá todos os
elementos da lista l (primeiro os ímpares, depois os pares, na ordem em que eles
aparecem em l), e a lista l continuará contendo os seus elementos. O protótipo da função
é o seguinte: TLSE* i_p (TLSE *l).*/

#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

TLSE *ordena_i_p(TLSE *lista){
    TLSE *pares = tlse_inicializa(), *impares = tlse_inicializa(), *aux = lista;

    while(aux != NULL){
        if(aux->info % 2 == 0){
            pares = tlse_insere_final(pares, aux->info);
        } else {
            impares = tlse_insere_final(impares, aux->info);
        }
        aux = aux->prox;
    }
    while(pares != NULL){
        impares = tlse_insere_final(impares, pares->info);
        pares = pares->prox;
    }
    
    tlse_libera(pares);
    return impares;
}


int main(){
    TLSE *lista = tlse_inicializa(), *lista_dois = tlse_inicializa();
    int el, n;

    printf("tam de elementos na lista: \n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("elemento %d: \n", i+1);
        scanf("%d", &el);
        lista = tlse_insere_final(lista, el);
    }
    tlse_imprime(lista);

    lista_dois = ordena_i_p(lista);
    tlse_imprime(lista_dois);

    tlse_libera(lista);
    tlse_libera(lista_dois);
    return 0;
}