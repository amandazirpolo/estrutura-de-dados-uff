/*(Q3) se esta estrutura tivesse um campo cor (int cor) na estrutura de grafo, teste se nós vizinhos não
tem a mesma cor. A função retorna um se os vizinhos não tem a mesma cor e zero, caso contrário:
int nao_tem_mesma_cor(TG *g);*/

#include <stdio.h>
#include <stdlib.h>
#include "TG.c"

int ntms_aux(TG *g_original, TG *p){
    if(!g_original) return 1;
    TVIZ *v = p->prim_viz;
    TG* tmp = NULL;
    while(v){
        tmp = TG_busca_no(g_original, v->id_viz);
        if(p->cor != tmp->cor) v = v->prox_viz;
        else return 0;
    }
    return 1; 
}

int nao_tem_mesma_cor(TG *g){
    TG *p = g;
    while(p){
        if(!ntms_aux(g, p)) return 0;
        p = p->prox_no;
    }
    return 1;
}

int main(){
    TG *g = TG_inicializa();
    int entrada, elem, no, aux, cor;

    printf("digite quantos nos deseja inserir: \n");
    scanf("%d", &entrada);
    for(int i = 0; i < entrada; i++){
        printf("digite um valor para o no e a cor dele: \n");
        scanf("%d %d", &elem, &cor);
        g = TG_ins_no_q3(g, elem, cor);
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

    aux = nao_tem_mesma_cor(g);
    if(aux){
        printf("\nos vizinhos nao possuem a mesma cor, ou seja, sao diferentes. \n");
    } else {
        printf("algum vizinho possui a mesma cor do no pai. \n");
    }

    TG_libera(g);
    return 0;
}