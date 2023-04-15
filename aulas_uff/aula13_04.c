/*Dados um vetor e seu tamanho, escreva uma função que cria uma
árvore binária com as seguintes regras:
    1. o elemento do meio do vetor é a raíz - vet[n/2];
    2. os elementos antes da raíz estão na SAE (subárvore esquerda);
    3. os elementos depois da raíz estão na SAD (subárvore direita);
*/

#include <stdio.h>
#include <stdlib.h>

// tipo da arvore binaria
typedef struct arvbin {
    int info;
    struct arvbin *esq, *dir;
} TAB;

// inicializa a arvore
TAB *TAB_inicializa(void){
    return NULL;
}

// cria a arvore
TAB *TAB_cria(int info, TAB *esq, TAB *dir){ // criar arvore n pode usar um metodo recursivo
    TAB *a = (TAB*)malloc(sizeof(TAB));
    a->info = info;
    a->esq = esq;
    a->dir = dir;
    return a;
}

TAB *vet_2_ab(int *vet, int n){
    if(n <= 0) {
        return NULL;
    }
    return TAB_cria(vet[n/2], vet_2_ab(vet, n/2), vet_2_ab(&vet[n/2 +1], n - n/2 - 1));
}

int main(){
    int vetor[10] = {5, 2, 7, 5, 21, 57, 23, 1, 4012};
    TAB *arvore;

    arvore = TAB_inicializa();
    arvore = vet_2_ab(vetor, 10);
    //imprime_arvore(arvore);
    return 0;
}