/*Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void i_p (TLSE *l).*/

#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

void ordena_i_p(TLSE *lista){
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
    *lista = *impares;
}


int main(){
    TLSE *lista = tlse_inicializa();
    int el, n;

    printf("tam de elementos na lista: \n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("elemento %d: \n", i+1);
        scanf("%d", &el);
        lista = tlse_insere_final(lista, el);
    }
    tlse_imprime(lista);

    ordena_i_p(lista);
    tlse_imprime(lista);
    
    tlse_libera(lista);
    return 0;
}