/* Q7) quantidade de nós internos: int ni(TARVB *a);*/

#include <stdio.h>
#include <stdlib.h>
#include "TARVB.c"

int ni_aux(TARVB *a){
    if(!a) return 0;
    if(a->folha) return 0;
    int i, cont = 0;
    for(i = 0; i <= a->nchaves; i++){
        cont += ni_aux(a->filho[i]);
    }
    return cont + 1;
}

int ni(TARVB *a){ // usa auxiliar pra nao contar a raiz 
    if(!a) return 0;
    int i, cont = 0;
    for(i = 0; i <= a->nchaves; i++){
        cont += ni_aux(a->filho[i]);
    }
    return cont;
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

    printf("%d \n", ni(arvore));

    TARVB_Libera(arvore);

    return 0;
}