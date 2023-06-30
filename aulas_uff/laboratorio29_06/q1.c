/*(Q1) Uma função em C que, dada uma árvore B qualquer, retorne, num vetor, todos
os elementos maiores que N. A função deve ter o seguinte protótipo: 
int* mN(TARVB*a, int N, int *tam);*/

#include <stdio.h>
#include <stdlib.h>
#include "TARVB.c"

int maiores_que_n(TARVB *a, int n){
    if(!a) return 0;
    int i, cont = 0;
    for(i = 0; i < a->nchaves; i++){
        if(a->chave[i] > n){
            printf("%d \n", a->chave[i]);
            cont += maiores_que_n(a->filho[i], n);
            cont++;
        }
    }
    // n usar a->filho[i+1], da erro
    cont += maiores_que_n(a->filho[a->nchaves], n);
    return cont;
}

void mN_aux(TARVB *a, int N, int *vet, int *pos){
    if(!a) return;
    int i = 0;
    for(i = 0; i < a->nchaves; i++){
        if(a->chave[i] > N){
            mN_aux(a->filho[i], N, vet, pos);
            vet[*pos] = a->filho[i];
            (*pos)++;
        }
    }
    mN_aux(a->filho[a->nchaves], N, vet, pos);
    return;
}

int *mN(TARVB *a, int N, int *tam){
    if(!a) return 0;
    int *vet = (int*)malloc(sizeof(int) * (*tam));
    int pos = 0;
    mN_aux(a, N, vet, &pos);
    return vet;
}

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
    int tam = maiores_que_n(arvore, 9);
    int *resp = mN(arvore, 9, &tam);

    for(int j = 0; j < tam; j++){
        printf("%d \n", resp[j]);
    }

    TARVB_Libera(arvore);
    return 0;
}