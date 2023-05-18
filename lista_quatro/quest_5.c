/*(Q5) testar se dois grafos são iguais - int ig(TG *g1, TG *g2).*/

#include <stdio.h>
#include <stdlib.h>
#include "TG.c"

int ig(TG *g1, TG *g2){
    if(!g1 || !g2) return 0;
    if(!g1 && !g2) return 1;
    TVIZ *v1 = g1->prim_viz, *v2 = g2->prim_viz;
    if(g1->id_no == g2->id_no){
        while(v1 && v2){
            if(v1->id_viz == v2->id_viz){
                v1 = v1->prox_viz;
                v2 = v2->prox_viz;
            } else {
                return 0;
            }
        }
        return ig(g1->prox_no, g2->prox_no);
    }
}

int main(){
    TG *g1 = TG_inicializa(), *g2 = TG_inicializa();
    int entrada, elem, no;

    printf("digite quantos nos deseja inserir no primeiro grafo: \n");
    scanf("%d", &entrada);
    for(int i = 0; i < entrada; i++){
        printf("digite um valor para o no: \n");
        scanf("%d", &elem);
        g1 = TG_ins_no(g1, elem);
    }

    printf("agora insira as arestas nos nos enquanto a entrada nao for 0: \n");
    while(entrada != 0){
        printf("digite em qual no deseja inserir o elemento e digite o elemento: \n\n");
        scanf("%d %d", &no, &elem);
        TG_ins_um_sentido(g1, no, elem);
        printf("digite 0 para parar e qualquer valor para continuar... \n");
        scanf("%d", &entrada);
    }

    printf("\n=============================================\n");

    printf("digite quantos nos deseja inserir no segundo grafo: \n");
    scanf("%d", &entrada);
    for(int i = 0; i < entrada; i++){
        printf("digite um valor para o no: \n");
        scanf("%d", &elem);
        g2 = TG_ins_no(g2, elem);
    }

    printf("agora insira as arestas nos nos enquanto a entrada nao for 0: \n");
    while(entrada != 0){
        printf("digite em qual no deseja inserir o elemento e digite o elemento: \n\n");
        scanf("%d %d", &no, &elem);
        TG_ins_um_sentido(g2, no, elem);
        printf("digite 0 para parar e qualquer valor para continuar... \n");
        scanf("%d", &entrada);
    }

    printf("grafo 1: \n");
    TG_imprime(g1);
    printf("grafo 2: \n");
    TG_imprime(g2);

    if(ig(g1, g1)){
        printf("os grafos sao iguais. \n");
    } else {
        printf("os grafos sao diferentes. \n");
    }

    TG_libera(g1);
    TG_libera(g2);

    return 0;
}