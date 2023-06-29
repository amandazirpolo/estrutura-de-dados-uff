#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "TG_prova.c"

int mdk(TG *g, int origem, int destino, int k){
    if(!g || k < 0) return INT_MAX;
    TG *aux = TG_busca_no(g, origem);
    if(!aux) return INT_MAX;
    TVIZ *vizinho = aux->prim_viz;
    int recebe = INT_MAX, peso, aux_rec;
    /*recebe vai trocando o valor pra achar o menor, aux_rec recebe a chamada recursiva
    pra guardar a soma dos custos*/
    while(vizinho){
        /*codigo novo: verifica se da para fazer em k passos. se der, retorna 
        a soma do custo
        ai da soma do custo soma com o custo do vizinho e vai comparando para
        encontrar o menor deles */
        aux_rec = mdk(aux, vizinho->id_viz, destino, k-1);
        peso = vizinho->custo + aux_rec;
        if(peso < recebe) recebe = peso;
        /*codigo antigo: verifica se da para fazer em k passos, ai verifica se é maior
        ou igual a k e se for, troca o custo do vizinho e retorna k o q de fato nao 
        faz o menor sentido */
        // recebe = mdk(aux, vizinho->id_viz, destino, k - 1);
        // if(recebe >= k){
        //     vizinho->custo = k;
        //     return k;
        // }
        vizinho = vizinho->prox_viz;
    }
    return recebe;
}

int main(void){
    TG *g = TG_inicializa();
    int entrada, elem, no, custo;

    printf("digite quantos nos deseja inserir: \n");
    scanf("%d", &entrada);
    for(int i = 0; i < entrada; i++){
        printf("digite um valor para o no: \n");
        scanf("%d", &elem);
        g = TG_ins_no(g, elem);
    }

    printf("agora insira as arestas nos nos enquanto a entrada nao for 0: \n");
    while(entrada != 0){
        printf("digite em qual no deseja inserir o elemento, digite o elemento  o custo: \n\n");
        scanf("%d %d %d", &no, &elem, &custo);
        TG_ins_aresta(g, no, elem, custo);
        printf("digite 0 para parar e qualquer valor para continuar... \n");
        scanf("%d", &entrada);
        fflush(stdin);
    }
    TG_imprime(g);
    // int n;
    // do{
    //     scanf("%d", &n);
    //     if(n <= 0) break;
    //     g = TG_ins_no(g, n);
    // }while(1);
    
    // int m, custo;
    // do{
    //     scanf("%d%d%d", &n, &m, &custo);
    //     if((n <= 0) || (m <= 0)) break;
    //     TG_ins_aresta(g, n, m, custo);
    // }while(1);
    // TG_imprime(g);
    
    int n, m, k;
    printf("digite n, m e k: \n");
    scanf("%d%d%d", &n, &m, &k);
    int resp = INT_MAX;
    resp = mdk(g, n, m, k);
    printf("Menor distancia entre %d e %d com %d arestas e igual a %d\n", n, m, k, resp);
    TG_libera(g);
    return 0;
}