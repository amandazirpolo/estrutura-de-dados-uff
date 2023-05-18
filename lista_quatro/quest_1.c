/*(Q1) descubra a quantidade de nós: int nn(TG *g);*/

#include <stdio.h>
#include <stdlib.h>
#include "TG.c"

int nn(TG *g){
    if(!g) return 0;
    return 1 + nn(g->prox_no);
}

int main(){
    TG *g = TG_inicializa();
    int entrada, elem, no;

    printf("digite quantos nos deseja inserir: \n");
    scanf("%d", &entrada);
    for(int i = 0; i < entrada; i++){
        printf("digite um valor para o no: \n");
        scanf("%d", &elem);
        g = TG_ins_no(g, elem);
    }

    printf("agora insira as arestas nos nos enquanto a entrada nao for 0: \n");
    while(entrada != 0){
        printf("digite em qual no deseja inserir o elemento e digite o elemento: \n\n");
        scanf("%d %d", &no, &elem);
        TG_ins_um_sentido(g, no, elem);
        printf("digite 0 para parar e qualquer valor para continuar... \n");
        scanf("%d", &entrada);
    }
    TG_imprime(g);

    printf("\no grafo possui %d nos. \n", nn(g));

    TG_libera(g);
    return 0;
}