/*(Q4) verificar se o grafo, passado como parâmetro de entrada, possui todos os nós com grau
igual a k - int testek(TG *g, int k); */

#include <stdio.h>
#include <stdlib.h>
#include "TG.c"

int testek(TG *g, int k){
    if(!g) return 1;
    TVIZ *v = g->prim_viz;
    int i = 0;
    while(v){
        v = v->prox_viz;
        i++;
    }
    if(i == k) return testek(g->prox_no, k);
    else return 0;
}

int main(){
    TG *g = TG_inicializa();
    int entrada, elem, no, k, aux;

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

    printf("digite um valor para k: \n");
    scanf("%d", &k);

    if(testek(g, k)){
        printf("todos os nos possuem nivel k. \n");
    } else {
        printf("pelo menos um no n possui nivel k. \n");
    }

    TG_libera(g);
    return 0;
}