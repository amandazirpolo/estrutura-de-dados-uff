/*(Q7) se esta estrutura TAB tivesse um campo cor (int cor), defina uma função em C que, ao
receber uma árvore binária “sem cor” e totalmente balanceada (isto é, a distância da raiz a qualquer
folha da árvore é sempre a mesma), retorne esta árvore com os nós coloridos somente de vermelho e
preto, sendo que o nó pai NUNCA pode ter a mesma cor de seus filhos. A função deve possuir o
seguinte protótipo: void colore (TAB* arv);*/

#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.c"

/*typedef struct arvbin{
  int info, cor;
  struct arvbin *esq, *dir;
} TAB;*/

void colore_g(TAB *a){
    if(!a){
        return;
    }
    a->cor = 1;
    colore_g_aux(a, a->esq);
    colore_g_aux(a, a->dir);
}

void colore_g_aux(TAB *pai, TAB *arvore){
    if(!arvore){
        return;
    }
    arvore->cor = !(pai->cor);
    colore_g_aux(arvore, arvore->esq);
    colore_g_aux(arvore, arvore->dir);
}

void colore(TAB *a){
    if(!a){
        return;
    }
    colore(a->esq);
    colore(a->dir);
    if(!a->esq && !a->dir){
        a->cor = 1;
    } else {
        if(a->esq){
            if(a->esq->cor == 1){
                a->cor = 0;
            } else {
                a->cor = 1;
            }
        }
        if(a->dir){
            if(a->dir->cor == 1){
                a->cor = 0;
            } else {
                a->cor = 1;
            }
        }
    }
}

int main(){
    TAB *a = TAB_inicializa();

    // a = TAB_cria(9, TAB_cria(3, TAB_cria(4, NULL, NULL), TAB_cria(6, NULL, NULL)), TAB_cria(5, TAB_cria(7, NULL, NULL), TAB_cria(8, NULL, NULL)));
    a = TAB_cria(3, TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(1, NULL, NULL)), TAB_cria(5, TAB_cria(9, NULL, NULL), TAB_cria(10, TAB_cria(11, NULL, NULL), TAB_cria(8, TAB_cria(7, NULL, NULL), NULL))));


    printf("arvore original: \n");
    TAB_imp_pre(a);

    colore_g(a);
    printf("\n\n arvore colorida: \n");
    TAB_imp_ident(a);
    
    TAB_libera(a);
    return 0;
}