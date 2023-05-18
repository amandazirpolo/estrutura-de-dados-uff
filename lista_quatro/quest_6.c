/*(2) Testar se o grafo é completo - int completo(TG *g);*/

#include <stdio.h>
#include <stdlib.h>
#include "TG.c"

int num_nos(TG *g){
    if(!g) return 0;
    return 1 + num_nos(g->prox_no);
}

int completo_aux(TG *g, int tam, int *contador){
    if(!g){
        if((*contador) == tam) return 1;
        else return 0;
    }
    int c_aux = 0;
    TVIZ *vizinho = g->prim_viz;
    while(vizinho){
        c_aux++; // incrementa o contador de arestas 
        vizinho = vizinho->prox_viz; // passa para o proximo vizinho
    }
    if(c_aux == (tam - 1)){ // se a quantidade de arestas for igual ao numero de nos menos 1
        ++(*contador);
        return completo_aux(g->prox_no, tam, contador);
    }
    return 0;
}

int completo(TG *g){
    if(!g) return 0;
    int contador = 0, tam = num_nos(g);
    return completo_aux(g, tam, &contador);
}

int main(){
    TG *g = TG_inicializa();
    int entrada, elem, no;

    printf("digite quantos nos deseja inserir no primeiro grafo: \n");
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
        TG_ins_aresta(g, no, elem);
        printf("digite 0 para parar e qualquer valor para continuar... \n");
        scanf("%d", &entrada);
    }

    if(completo(g)){
        printf("o grafo eh completo. \n");
    } else {
        printf("o grafo nao eh completo. \n");
    }

    TG_libera(g);

    return 0;
}