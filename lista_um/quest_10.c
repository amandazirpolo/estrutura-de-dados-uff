/*Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1
é a inversão de l2. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1
se as listas estão invertidas e 0, caso contrário. O protótipo desta função é o seguinte: int
Contrario (TLSE *l1, TLSE *l2).*/

#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

int igual(TLSE *l1, TLSE *l2){
    TLSE *aux1 = l1, *aux2 = l2;

    while((aux1 != NULL) && (aux2 != NULL)){
        if(aux1->info == aux2->info){
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        } else {
            break;
        }
    }
    if ((aux1 == NULL) && (aux2 == NULL)){
        return 1;
    }
    return 0;
}

int contrario(TLSE *l1, TLSE *l2){
    TLSE *laux = tlse_inicializa(), *aux_percorre = l2;

    while(aux_percorre != NULL){
        laux = tlse_insere_inicio(laux, aux_percorre->info);
        aux_percorre = aux_percorre->prox;
    }
    return igual(l1, laux);
}

int main(){
    TLSE *lista_um = tlse_inicializa(), *lista_dois = tlse_inicializa();
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

    if(contrario(lista_um, lista_dois)){
        printf("as listas sao inversas. \n");
    } else {
        printf("as listas nao sao inversas. \n");
    }

    tlse_libera(lista_um);
    tlse_libera(lista_dois);

    return 0;
}