/*Crie uma função em C que remova todas as ocorrências de um elemento numa lista.
Seu protótipo O protótipo desta função é o seguinte: TLSE* rto (TLSE* l, int elem).*/

#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

TLSE *remove_todas_ocorrencias(TLSE *lista, int elem){

    while(tlse_busca(lista, elem)){
        lista = tlse_remove(lista, elem);
    }
    return lista;
}

int main(){
    TLSE *lista = tlse_inicializa();
    int el, n, valor;

    printf("tam de elementos na lista: \n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("elemento %d: \n", i+1);
        scanf("%d", &el);
        lista = tlse_insere_final(lista, el);
    }
    tlse_imprime(lista);

    printf("qual elemento deseja remover? \n");
    scanf("%d", &valor);
    
    lista = remove_todas_ocorrencias(lista, valor);
    tlse_imprime(lista);

    tlse_libera_recursivo(lista);

    return 0;
}