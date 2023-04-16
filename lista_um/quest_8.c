/*Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1
e l2 são iguais. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se
as listas são iguais e 0, caso contrário. O protótipo desta função é o seguinte: int igual
(TLSE *l1, TLSE *l2).*/

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

    if(igual(lista_um, lista_dois)){
        printf("as listas sao iguais. \n");
    } else {
        printf("as listas sao diferentes. \n");
    }

    tlse_libera(lista_um);
    tlse_libera(lista_dois);

    return 0;
}