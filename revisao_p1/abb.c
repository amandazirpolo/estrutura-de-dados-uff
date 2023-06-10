#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_abb.c"

/* q1 */
TABB *maior(TABB *a){
    if(!a) return NULL;
    if(!a->dir) return a;
    return maior(a->dir);
}

/* q2 */
TABB *menor(TABB *a){
    if(!a) return NULL;
    if(!a->esq) return a;
    return menor(a->esq);
}

/* q3 */
TABB* retira_impares(TABB* a){
    if(!a) return NULL;
    if((a->info % 2) != 0){
        TABB *tmp = NULL;
        /*caso 1: nó folha */
        if(!a->esq && !a->dir){
            tmp = a;
            a = NULL;
            free(tmp);
        }
        /*caso 2: é um nó com um filho só*/ 
        else if(!a->esq || !a->dir){
            if(a->esq && !a->dir){ // é filho da esquerda
                tmp = a;
                a = a->esq;
            } else {
                tmp = a;
                a = a->dir;
            }
            free(tmp);
        }
        /*caso 3: pai com 2 filhos*/
        TABB *aux = a->esq;
        while(aux->dir){
            aux = aux->dir;
        }
        a->info = aux->info;
        aux->info = 1; // força o ultimo elemento a ser impar
        a = retira_impares(a);
    }
    return a;
}

/* q4 */
int conta_menores(TABB *a, int n){
    if(!a) return 0;
    if(a->info < n) return 1 + conta_menores(a->esq, n) + conta_menores(a->dir, n);
    return conta_menores(a->esq, n) + conta_menores(a->dir, n);
}

void mn_aux(TABB *a, int n, int *vetor, int *i){
    if(!a) return;
    if(a->info < n){
        vetor[*i] = a->info;
        (*i++);
    }
    mn_aux(a->esq, n, vetor, i);
    mn_aux(a->dir, n, vetor, i);
}

int *mN(TABB *a, int n){
    if(!a) return 0;
    int *vetor = (int*)malloc(sizeof(int) * conta_menores(a, n));
    int i = 0;
    mn_aux(a, n, vetor, &i);
    return vetor;
}

int main(){
    TABB *a = TABB_inicializa();
    TABB *maior_elemento = NULL, *menor_elemento = NULL;
    int *vetor_menores;

    a = TABB_insere(a, 5);
    a = TABB_insere(a, 2);
    a = TABB_insere(a, 1);
    a = TABB_insere(a, 3);
    a = TABB_insere(a, 4);
    a = TABB_insere(a, 7);
    a = TABB_insere(a, 6);
    a = TABB_insere(a, 9);
    a = TABB_insere(a, 8);
    a = TABB_insere(a, 10);

    TABB_imp_ident(a);

    // maior_elemento = maior(a);
    // menor_elemento = menor(a);
    vetor_menores = mN(a, 8);

    // printf("maior elemento: %d \n", maior_elemento->info);
    // printf("menor elemento: %d \n", menor_elemento->info);
    printf("valores menores que %d: \n", 8);
    for(int i = 0; i < conta_menores(a, 8); i++){
        printf("%d ", vetor_menores[i]);
    }

    TABB_libera(a);
    return 0;
}

