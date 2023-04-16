/*Refaça Q11, alterando a lista passada como parâmetro. O protótipo desta função é
o seguinte: void ordena (TLSE *l).*/

#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

void ordena(TLSE *l){
    TLSE *laux = tlse_inicializa(), *aux = l;

    while(aux != NULL){
        laux = tlse_insere_ordenado_recursivo(laux, aux->info);
        aux = aux->prox;
    }
    *l = *laux;
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

    ordena(lista);
    printf("lista ordenada: \n");
    tlse_imprime(lista);

    tlse_libera(lista);
    
    return 0;
}