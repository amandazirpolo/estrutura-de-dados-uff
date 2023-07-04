/* Q1) cópia de uma árvore: TARVB* copia (TARVB *a);*/

#include <stdio.h>
#include <stdlib.h>
#include "TARVB.c"

// TARVB *copia_aux(TARVB *a, TARVB *a2){
//     if(!a) return a2;
//     int i;
//     TARVB *aux = NULL;
//     for(i = 0; i < a->nchaves; i++){
//         aux = copia_aux(a->filho[i], a2);
//         a2 = TARVB_Cria(2);
//         a2 = TARVB_Insere(a2, a->chave[i], 2);
//         // pq esta perdendo a referencia dos ponteiros?
//         TARVB_Imprime(a2);
//     }
//     aux = copia_aux(a->filho[a->nchaves], a2);
//     return a2;
// }

TARVB *copia(TARVB *a1){
    if(!a1) return a1;
    TARVB *aux = TARVB_Cria(2);
    aux->folha = a1->folha;
    aux->nchaves = a1->nchaves;
    for(int i = 0; i < a1->nchaves; i++){
        aux->chave[i] = a1->chave[i];
    }
    for(int i = 0; i <= a1->nchaves; i++){
        aux->filho[i] = copia(a1->filho[i]);
    }
    return aux;
}

// TARVB *copia(TARVB *a){
//     if(!a) return NULL;
//     TARVB *aux = NULL;
//     return copia_aux(a, aux);
// }


int main(){
    TARVB *arvore = TARVB_Inicializa();
    int t;
    printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
    scanf("%d", &t);
    if(t < 2) t = 2;
    int num = 0, from, to;
    while(num != -1){
        printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
        scanf("%d", &num);
        if(num == -9){
        scanf("%d", &from);
        arvore = TARVB_Retira(arvore, from, t);
        TARVB_Imprime(arvore);
        }
        else if(num == -1){
        printf("\n");
        TARVB_Imprime(arvore);
        // TARVB_Libera(arvore);
        // return 0;
        break;
        }
        else if(!num){
        printf("\n");
        TARVB_Imprime(arvore);
        }
        else arvore = TARVB_Insere(arvore, num, t);
        printf("\n\n");
    }

    TARVB *b = NULL;
    b = copia(arvore);

    printf("arvore original: \n");
    TARVB_Imprime(arvore);
    TARVB_Libera(arvore);

    printf("arvore copiada: \n");
    TARVB_Imprime(b);

    TARVB_Libera(arvore);
    TARVB_Libera(b);

    return 0;
}