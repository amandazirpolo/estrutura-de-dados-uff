/*Q3) questão de grafos do instagram - grafos orientados*/

/*Um grafo orientado, também conhecido como digrafo, possui arestas 
direcionadas. Cada aresta em um grafo orientado tem uma direção específica, 
indicando uma relação unidirecional entre dois vértices. Isso significa que 
se existe uma aresta que vai do vértice A ao vértice B, não necessariamente 
existe uma aresta que vai do vértice B ao vértice A. A relação entre os vértices 
em um grafo orientado pode ser assimétrica.*/

/*se o grafo é orientado, então inserimos as arestas em apenas um sentido */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_binaria.c"
#include "TG.c"

/*quest. 1 - int numero_seguidos(TGrafo *g, char *nome);*/

int numero_seguidos(TG *g, char *nome){
    if(!g) return 0;
    TG *aux = g;
    int cont = 0;
    while(aux){
        if(strcmp(nome, aux->nome) == 0){
            TVIZ *vizinho = aux->prim_viz;
            while(vizinho){
                cont++;
                vizinho = vizinho->prox_viz;
            }
            return cont;
        } else aux = aux->prox_no;
    }
    return 0;
}

/*quest. 2 - int seguidores(TGrafo *vertice, char *nome, int imprime);*/

void imprime_seguidores(TG *g, int elem){
    TG *aux = TG_busca_no(g, elem);
    printf("%s - ", aux->nome);
}

int seguidores_aux(TG *g_original, TG *no, int id, int *seguidos, int imprime){
    if(!no) return *seguidos;
    TVIZ *aux_vizinho = no->prim_viz;
    while(aux_vizinho){
        if(aux_vizinho->id_viz == id){
            ++(*seguidos);
            imprime = 1;
            if(imprime) imprime_seguidores(g_original, no->id_no);
        }
        aux_vizinho = aux_vizinho->prox_viz;
        imprime = 0;
    }
    return seguidores_aux(g_original ,no->prox_no, id, seguidos, imprime);
}

int seguidores(TG *g, char *nome, int imprime){
    if(!g) return 0;
    TG *aux = g;
    int id;
    while(aux){
        if(strcmp(nome, aux->nome) == 0){
            id = aux->id_no;
            break;
        } else aux = aux->prox_no;
    }
    int seguidos = 0;
    return seguidores_aux(g, g, id, &seguidos, imprime);
}

/*quest. 3 - TGrafo *mais_popular(TGrafo *g);*/

TG *mais_popular(TG *g){
    if(!g) return NULL;
    int num_seg, maior = 0;
    TG *aux = g, *no_popular = NULL;
    while(aux){
        num_seg = seguidores(aux, aux->nome, 0);
        if(num_seg > maior){
            maior = num_seg;
            no_popular = aux;
        }
        aux = aux->prox_no;
    }
    return no_popular;
}   

/*quest. 4 - int segue_mais_velho(TGrafo *g, int imprime);*/

int segue_mais_velho_aux(TG *g_original, TG *g, int *contador, int imprime){
    if(!g) return (*contador);
    TG *aux = NULL;
    TVIZ *vizinho = g->prim_viz;
    while(vizinho){
        aux = TG_busca_no(g_original, vizinho->id_viz);
        if(g->idade < aux->idade) {
            vizinho = vizinho->prox_viz;
        } else {
            break;
        }
    }
    if(!vizinho && g->prim_viz){
        ++(*contador);
        imprime = 1;
        if(imprime) printf("%s so segue pessoas mais velhas. \n", g->nome);
    }
    imprime = 0;
    return segue_mais_velho_aux(g_original, g->prox_no, contador, imprime);
}

int segue_mais_velho(TG *g, int imprime){
    if(!g) return 0;
    int contador = 0;
    return segue_mais_velho_aux(g, g, &contador, imprime);
}

int main(){
    TG *g = TG_inicializa(), *popular = NULL;
    int num_seguidos;

    g = TG_ins_no(g, 1, "Joao", 25);
    g = TG_ins_no(g, 2, "Caio", 20);
    g = TG_ins_no(g, 3, "Ana", 23);
    g = TG_ins_no(g, 4, "Pedro", 20);
    g = TG_ins_no(g, 5, "Jane", 30);
    g = TG_ins_no(g, 6, "Marcos", 19);
    g = TG_ins_no(g, 7, "Bruna", 23);
    g = TG_ins_no(g, 8, "Felipe", 20);
    g = TG_ins_no(g, 9, "Renata", 35);

    /*joao*/
    TG_ins_um_sentido(g, 1, 2); // joao segue o caio
    TG_ins_um_sentido(g, 1, 3); // joao segue a ana
    TG_ins_um_sentido(g, 1, 4); // joao segue o pedro

    /*caio*/
    // caio n segue ninguem

    /*ana*/
    TG_ins_um_sentido(g, 3, 5); // ana segue a jane
    TG_ins_um_sentido(g, 3, 1); // ana segue o joao

    /*pedro*/
    TG_ins_um_sentido(g, 4, 2); // pedro segue o caio
    TG_ins_um_sentido(g, 4, 7); // pedro segue a bruna
    TG_ins_um_sentido(g, 4, 5); // pedro segue a jane
    TG_ins_um_sentido(g, 4, 6); // pedro segue o marcos

    /*jane*/
    TG_ins_um_sentido(g, 5, 6); // jane segue o marcos
    TG_ins_um_sentido(g, 5, 7); // jane segue a bruna

    /*marcos*/
    TG_ins_um_sentido(g, 6, 8); // marcos segue o felipe
    TG_ins_um_sentido(g, 6, 9); // marcos segue a renata
    
    /*bruna*/
    TG_ins_um_sentido(g, 7, 9); // bruna segue a renata

    /*felipe*/
    TG_ins_um_sentido(g, 8, 6); // felipe segue o marcos
    TG_ins_um_sentido(g, 8, 9); // felipe segue a renata

    /*renata*/
    // renata n segue ninguem

    printf("quantidade de pessoas que seguem apenas pessoas mais velhas que ela: %d \n", segue_mais_velho(g, 0));


    // popular = mais_popular(g);
    // printf("%s eh o mais popular. \n", popular->nome);
    // printf("%d", num_nos(g));

    // printf("Pedro segue %d pessoas. \n", numero_seguidos(g, "Pedro"));
    // printf("Marcos eh seguido por %d pessoas. \n", seguidores(g, "Marcos", 0));

    // TG_imprime(g);
    
    TG_libera(g);

    return 0;
}