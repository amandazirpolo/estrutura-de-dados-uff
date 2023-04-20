#include <stdio.h>
#include <stdlib.h>

/*lifo - last in, first out (ultimo a entrar é o primeiro a sair)*/
/*insere no inicio e remove a primeira ocorrencia*/

// tipo da pilha
typedef struct pilha {
    int info;
    struct pilha *prox;
} TP;

TP *tp_cria(){
    return NULL;
}

TP *tp_insere_inicio(TP *pilha, int x){
    TP *novo = (TP*)malloc(sizeof(TP));
    novo->info = x;
    novo->prox = pilha;
    return novo;
}

TP *tp_remove(TP *pilha){
    TP *t;
    pilha = pilha->prox;
    free(t);
    return pilha;
}

void tp_libera(TP *pilha){
    TP *aux = pilha, *t;
    while(aux != NULL){
        t = aux;
        aux = aux->prox;
        free(t);
    }
}

void tp_imprime(TP *pilha){
    TP *aux = pilha;
    while(aux != NULL){
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
    printf("NULL \n");
}