/*Implemente uma função que copie uma lista. A lista original deve permanecer
inalterada. O protótipo da função é o seguinte: TLSE *copia (TLSE *l).*/

#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

TLSE *copia_lista(TLSE *lista){
    TLSE *aux = lista, *l2 = tlse_inicializa();

    while(aux != NULL){
        l2 = tlse_insere_final_recursivo(l2, aux->info);
        aux = aux->prox;
    }
    return l2;
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

    lista_dois = copia_lista(lista);
    printf("copia da lista: \n");
    tlse_imprime(lista_dois);

    tlse_libera_recursivo(lista);
    tlse_libera_recursivo(lista_dois);
    
    return 0;
}