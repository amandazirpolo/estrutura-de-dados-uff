/*(Q4) uma função em C que, dada uma árvore binária de busca qualquer, retorne, num vetor, todos
os elementos menores que N. A função deve ter o seguinte protótipo: int* mN(TABB*a, int
N);*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_busca.c"

int maior(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int calcula_tamanho(TABB *a){
    if(!a){
        return -1;
    }
    if(!a->esq){
        return 0;
    }
    if(!a->dir){
        return 0;
    }
    return 1 + maior(calcula_tamanho(a->esq), calcula_tamanho(a->dir));
}

void insere_vetor(int *vet, int elem, int i){
    vet[i] = elem;
}

TABB *percorre_arvore(TABB *a){
    if(!a){
        return NULL;
    }
    return a->esq, a->dir;
}

int menores_n(TABB *a, int n){
    if(!a){
        return 0;
    }
    int tam = calcula_tamanho(a); // tamanho da arvore
    int *vet, i = 0;

    a = percorre_arvore(a);
    vet = (int*)malloc((sizeof(int)) * tam);
    if(a->esq->info < n){
        insere_vetor(vet, a->esq->info, i);
        i++;
    }
    if(a->dir->info < n){
        insere_vetor(vet, a->dir->info, i);
        i++;
    }

    return *vet;
}

void imprime_vet(int *vet, int i){
    printf("%d - ", vet[i]);
    imprime_vet(vet, i+1);
}

int main(){
    TABB *a = TABB_inicializa();
    int elemento = 15;
    int *vetor_inteiros;

    a = TABB_cria(10, TABB_cria(8, TABB_cria(4, TABB_cria(2, NULL, NULL), NULL) ,TABB_cria(9,TABB_cria(5, NULL, NULL), TABB_cria(15, NULL, NULL))), TABB_cria(12, TABB_cria(11, NULL, NULL), TABB_cria(13, NULL, TABB_cria(17, NULL, NULL))));

    printf("arvore original: \n");
    TABB_imp_ident(a);

    printf("\n\n elementos menores que %d: \n", elemento);
    *vetor_inteiros = menores_n(a, elemento);
    imprime_vet(vetor_inteiros, 0);
    
    TABB_libera(a);
    return 0;
}