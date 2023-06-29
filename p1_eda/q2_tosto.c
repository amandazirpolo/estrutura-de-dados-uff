#include <stdio.h>
#include <stdlib.h>
#include "TG.c"

int testek_1(TG *g, int no1, int no2, int k)
{
    if (k==0) return 0;
    TG *aux = TG_busca_no(g,no1);
    if (!aux) return 0;
    TVIZ *v = aux->prim_viz;
    int resp=0;
    while (v){
        if (v->id_viz == no2) return 1;
        resp = testek_1(g, v->id_viz, no2, k-1);
        if (resp==1) return 1;
        v = v->prox_viz;
    }
    return resp;
}

int main()
{
    TG *g = TG_inicializa();
    for (int i=0;i<10;i++)
    {
        g=TG_ins_no(g,i,i);
        if (i>0)
            TG_ins_aresta(g,i-1,i);    
    }

    int passos = testek_1(g,1,5,4);
    if (passos) printf("It is possible to reach the node!");
    else printf("It is not possible to reach the node!");

    TG_libera(g);
    return 0;
}