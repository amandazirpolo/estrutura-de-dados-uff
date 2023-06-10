#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_tg.c"

/* q1 */
int nn(TG *g){
    if(!g) return 0;
    return 1 + nn(g->prox_no);
}

/* q2 */
int na_aux(TG *g, int *contador){
    if(!g) return (*contador);
    TVIZ *aux_vizinho = g->prim_viz;
    int cont = 0;
    while(aux_vizinho){
        aux_vizinho = aux_vizinho->prox_viz;
        (*contador)++;
    }
    return na_aux(g->prox_no, contador);
}

int na(TG *g){
    if(!g) return 0;
    int contador = 0;
    return na_aux(g, &contador);
}

/* q3 */
int ntms_aux(TG *g_original, TG *no){
    if(!no) return 1;
    TVIZ *vizinho = no->prim_viz;
    TG *aux = NULL;
    while(vizinho){
        aux = TG_busca_no(g_original, no->id_no);
        if(aux->cor != no->cor) vizinho = vizinho->prox_viz;
        else return 0;
    }
    return 1;
}

int nao_tem_mesma_cor(TG *g){
    if(!g) return 1;
    TG *aux = g;
    while(g){
        if(!ntms_aux(g, g)) return 0;
        g = g->prox_no;
    }
    return 1;
}

/* q4 */


int main(){
    TG *g = TG_inicializa();
    int entrada, elem, no, cor;

    printf("digite quantos nos deseja inserir no grafo: \n");
    scanf("%d", &entrada);
    for(int i = 0; i < entrada; i++){
        printf("digite um valor e a cor para o no: \n");
        scanf("%d", &elem, &cor);
        g = TG_ins_no(g, elem, cor);
    }

    printf("agora insira as arestas nos nos enquanto a entrada nao for 0: \n");
    while(entrada != 0){
        printf("digite em qual no deseja inserir o elemento e digite o elemento: \n\n");
        scanf("%d %d", &no, &elem);
        TG_ins_aresta(g, no, elem);
        printf("digite 0 para parar e qualquer valor para continuar... \n");
        scanf("%d", &entrada);
    }

    TG_imprime(g);
    
    if(nao_tem_mesma_cor(g)){
        printf("os vizinhos nao tem a mesma cor. \n");
    } else {
        printf("os vizinhos tem a mesma cor. \n");
    }

    TG_libera(g);
    // printf("numero de nos: %d \n", nn(g));
    // printf("numero de arestas: %d \n", na(g));

    return 0;
}