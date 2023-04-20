/*Escreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l. 
O protótipo da função de inversão é o seguinte: void inverte (TLSE* l).*/

#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

/*void inverte_lista(TLSE *lista){
    TLSE *lista_aux = lista;

    lista = tlse_inicializa();
    while(lista_aux != NULL){
        lista = tlse_insere_inicio(lista, lista_aux->info);
        lista_aux = lista_aux->prox;
    }
    // tlse_imprime(lista);
    // tlse_libera(lista_aux);
}
*/

void inverte_lista(TLSE *lista){
    TLSE *la = NULL, *p = lista;
    while(p){
        la = tlse_insere_inicio(la, p->info);
        p = p->prox;
    }
    p = la;
    while(p){
        lista->info = p->info;
        p = p->prox;
        lista = lista->prox;
    }
    tlse_libera(la);
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
    printf("lista original: \n");
    tlse_imprime(lista);

    inverte_lista(lista);
    printf("lista invertida: \n");
    tlse_imprime(lista);

    tlse_libera(lista);
    return 0;
}
