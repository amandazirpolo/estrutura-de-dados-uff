/*Q1) Uma função em C que, dada uma árvore B qualquer, retorne, num vetor, todos
os elementos maiores que N. A função deve ter o seguinte protótipo: int* mN(TAB*a, int N, int *tam);*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.c"

int maiores_que_n(TAB *a, int n){
    if(!a) return 0;
    if(a->info > n) return 1 + maiores_que_n(a->esq, n) + maiores_que_n(a->dir, n);
    return maiores_que_n(a->esq, n) + maiores_que_n(a->dir, n);
}

void mN_aux(TAB *a, int n, int *vetor, int *pos){
    if(!a) return;
    if(a->info > n){
        vetor[*pos] = a->info;
        ++*pos;
    }
    mN_aux(a->esq, n, vetor, pos);
    mN_aux(a->dir, n, vetor, pos);
}

int *mN(TAB *a, int n, int *tam){
    int *vet = (int*)malloc( *tam * sizeof(int));
    int pos = 0;
    mN_aux(a, n, vet, &pos);
    return vet;
}

int main(){
    TAB *a = TAB_inicializa();
    a = TAB_cria(3, TAB_cria(5, TAB_cria(1, NULL, NULL), TAB_cria(2 ,TAB_cria(4, NULL, NULL), TAB_cria(6, NULL, NULL))), TAB_cria(8, TAB_cria(7, NULL, NULL), TAB_cria(9, NULL, NULL)));
    int *vet, aux, tam;

    TAB_imp_ident(a);

    printf("digite um elemento inteiro e que esteja na arvore: \n");
    scanf("%d", &aux);

    tam = maiores_que_n(a, aux);
    if(TAB_busca(a, aux) && tam > 0){
        vet = mN(a, aux, &tam);
        printf("valores maiores que %d: \n", aux);
        for(int i = 0; i < tam; i++){
            if(vet[i] != 0) printf("%d / ", vet[i]);
        }
    } else {
        printf("o elemento n esta na lista. \n");
    }

    TAB_libera(a);
    free(vet);

    return 0;
}