#include <stdio.h>
#include <stdlib.h>
// #include "arvore_binaria.c"

/*fifo - first in, first out (primeiro que entra é o primeiro que sai)*/
/*insere no final e remove a primeira ocorrencia*/

typedef struct fila {
    TAB *filhos;
    struct fila *prox;
} TF;

TF *tf_cria(){
    return NULL;
}

TF *tf_insere_inicio(TF *fila, TAB *no){
    TF *novo = (TF*)malloc(sizeof(TF));
    novo->filhos = no;
    novo->prox = fila;
    return novo;
}

TF *tf_insere_final(TF *fila, TAB *no){
    TF *novo = tf_insere_inicio(NULL, no); /*cria o nó*/
    if(fila == NULL){
        return novo;
    }
    TF *aux = fila;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return fila;
}

TF *tf_retira(TF *fila){
    TF *t = fila;
    fila = fila->prox;
    free(t);
    return fila;
}

void tf_imprime(TF *fila){
    TF *aux = fila;
    while(aux != NULL){
        printf("%d -> ", aux->filhos);
        aux = aux->prox;
    }
    printf("NULL \n");
}

void tf_libera(TF *fila){
    TF *aux = fila, *t;
    while(aux != NULL){
        t = aux;
        aux = aux->prox;
        free(t);
    }
}

int tf_vazia(TF *fila){
    if(fila == NULL){
        return 1;
    }
    return 0;
}