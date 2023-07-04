/* Q2) sucessor de um elemento na árvore. Se o elemento for o maior da estrutura, sua
função deve retornar INT_MAX: int suc (TARVB *a, int elem); */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "TARVB.c"

int suc(TARVB *a, int elem){
    if(!a) return INT_MAX;
    TARVB *aux = TARVB_Busca(a, elem);
    if(!aux) return INT_MAX; // se o elemento não estiver na árvore, retorna int_max
    int i;
    if(aux->nchaves == 1) return INT_MAX; // se tiver uma chave só, retorna int_max
    if(aux->chave[aux->nchaves - 1] == elem) return INT_MAX; // se aux->chave na ultima pos for igual ao elemento, retorna int_max
    for(i = 0; i < a->nchaves; i++){
        if(aux->chave[i] == elem && i < aux->nchaves) return aux->chave[i+1];
    }
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

    int sucessor = suc(arvore, 6);
    printf("o sucessor do elemento escolhido eh %d \n", sucessor);

    TARVB_Libera(arvore);

    return 0;
}