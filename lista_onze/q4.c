/* Q4) menor elemento da árvore: TARVB* menor(TARVB *a); */

#include <stdio.h>
#include <stdlib.h>
#include "TARVB.c"

TARVB *menor(TARVB *a){
    if(!a) return a;
    if(a->folha) return a;
    return menor(a->filho[0]);
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

    TARVB *aux = maior(arvore);
    TARVB_Imprime(aux);

    TARVB_Libera(arvore);
    TARVB_Libera(aux);

    return 0;
}