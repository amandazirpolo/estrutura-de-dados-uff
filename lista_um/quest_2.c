/*Refaça a Q1, escrevendo uma função em C que, dada uma lista l qualquer, inverta os
elementos de l em uma outra lista de saída. Portanto, a lista de entrada não pode ser
alterada. O protótipo da função de inversão é o seguinte: TLSE* inverte (TLSE* l).*/

#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

TLSE *inverte_lista(TLSE *l){
    TLSE *lista_invertida = tlse_inicializa(), *aux;

    aux = l;
    while(aux != NULL){
        lista_invertida = tlse_insere_inicio(lista_invertida, aux->info);
        aux = aux->prox;
    }
    return lista_invertida;
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

    printf("lista original: \n");
    tlse_imprime(lista);

    lista_dois = inverte_lista(lista);
    printf("lista invertida: \n");
    tlse_imprime(lista_dois);

    tlse_libera(lista);
    tlse_libera(lista_dois);

    return 0;
}