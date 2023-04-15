/* Funções de Lista Simplesmente Encadeada em C. Aula 10/04/2023. */

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} TLSE;

TLSE *tlse_inicializa(){
    return NULL;
}

TLSE *tlse_insere_inicio(TLSE *l, int x){
    TLSE *novo = (TLSE*)malloc(sizeof(TLSE));
    novo->info = x;
    novo->prox = l;
    return novo;
}

TLSE *tlse_insere_final(TLSE *l, int x){
    TLSE *novo = tlse_insere_inicio(NULL, x); // cria o no fazendo apontar pra null e insere x
    if(l == NULL){
        return novo;
    }
    TLSE *aux = l;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return l;
}

TLSE *tlse_insere_final_recursivo(TLSE *l, int x){
    if(l == NULL){
        return tlse_insere_inicio(l, x);
    }
    l->prox = tlse_insere_final_recursivo(l->prox, x);
    return l;
}

TLSE *tlse_insere_ordenado(TLSE *l, int x){
    TLSE *aux = l, *ant = NULL;
    while((aux->prox != NULL) && (aux->info < x)){
        ant = aux;
        aux = aux->prox;
    }
    if(ant == NULL){ // entao a lista esta vazia
        return tlse_insere_inicio(l, x);
    }
    ant->prox = tlse_insere_inicio(l, x); // insere o elemento depois de anterior
}

TLSE *tlse_insere_ordenado_recursivo(TLSE *l, int x){
    if((l == NULL) || (l->info >= x)){
        return tlse_insere_inicio(l, x);
    }
    l->prox = tlse_insere_ordenado_recursivo(l->prox, x);
    return l;
}

TLSE *tlse_busca(TLSE *l, int x){
    TLSE *resp = l;
    while((resp != NULL) && (resp->info != x)){
        resp = resp->prox;
    }
    return resp; //retorna o no do elemento
}

TLSE *tlse_busca_recursiva(TLSE *l, int x){
    if((l == NULL) || (l->info == x)){
        return l;
    } else {
        return tlse_busca_recursiva(l, x);
    }
}

void tlse_imprime(TLSE *l){
    TLSE *p = l;
    while(p != NULL){
        printf("%d -> ", p->info);
        p = p->prox;
    }
    printf("NULL \n");
}

void tlse_imprime_recursivo(TLSE *l){
    if(l != NULL){
        printf("%d -> ", l->info);
        tlse_imprime_recursivo(l->prox);
    }
}

void tlse_libera(TLSE *l){
    TLSE *p = l, *t;
    while(p != NULL){
        t = p;
        p = p->prox;
        free(t);
    }
}

void tlse_libera_recursivo(TLSE *l){
    if(l != NULL){
        tlse_libera_recursivo(l->prox);
        free(l);
    }
}

void tlse_imprime_invertido(TLSE *l){
    TLSE *p = l, *lAux = tlse_inicializa();
    while(p != NULL){
        lAux = tlse_insere_inicio(lAux, p->info);
        p = p->prox;
    }
    tlse_imp(lAux);
    tlse_libera(lAux);
}

void tlse_imprime_invertido_recursivo(TLSE *l){
    if(l != NULL){
        tlse_imprime_invertido_recursivo(l->prox);
        printf("%d -> ", l->info);
    }
}
