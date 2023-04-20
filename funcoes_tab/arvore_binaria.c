#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"
#include "fila.c"
#include "pilha.c"

// tipo da arvore binaria
typedef struct arvbin {
    int info;
    struct arvbin *esq, *dir;
} TAB;

// inicializa a arvore
TAB *TAB_inicializa(void){
    return NULL;
}

// cria a arvore
TAB *TAB_cria(int info, TAB *esq, TAB *dir){ // criar arvore n pode usar um metodo recursivo
    TAB *a = (TAB*)malloc(sizeof(TAB));
    a->info = info;
    a->esq = esq;
    a->dir = dir;
    return a;
}

int maior(int x, int y){
    if(x >= y){
        return x;
    }
    return y;
}

// calcula a altura da arvore
int calcula_altura(TAB *a){
    if(!a){
        return -1;
    }
    return 1 + maior(calcula_altura(a->esq), calcula_altura(a->dir));
}

void TAB_imp_pre(TAB *a){
    if(a){
        printf("%d - ", a->info);
        TAB_imp_pre(a->esq);
        TAB_imp_pre(a->dir);
    }
}

void TAB_imp_sim(TAB *a){
    if(a){
        TAB_imp_sim(a->esq);
        printf("%d - ", a->info);
        TAB_imp_sim(a->dir);
    }
}

void TAB_imp_pos(TAB *a){
    if(a){
        TAB_imp_pos(a->esq);
        TAB_imp_pos(a->dir);
        printf("%d - ", a->info);
    }
}

void TAB_imp_larg(TAB *a){
    TF *f = tf_cria();
    tf_insere_final(f, a);
    while(!tf_vazia(f)){
        TAB *aux = TF_retira(f);
        printf("%d - ", aux->info);
        if(aux->esq){
            tf_insere_final(f, aux->esq); // adiciona os nós da esquerda na fila
        }
        if(aux->dir){
            tf_insere_final(f, aux->dir); // adiciona os nós da direita na fila
        }
    }
    tf_libera(f);
}

void TAB_imp_pre_TP(TAB *a){
    if(!a){
        return;
    }
    TP *p = tp_cria();
    tp_insere_inicio(p, a);
    while(!tp_vazia(p)){
        TAB *aux = tp_remove(p);
        printf("%d - ", aux->info);
        if(aux->dir){
            tp_insere_inicio(p, aux->dir);
        }
        if(aux->esq){
            tp_insere_inicio(p, aux->esq);
        }
    }
    tp_libera(p);
    }

TAB *TAB_busca(TAB *a, int x){
    if((!a) || a->info == x){
        return a;
    }
    TAB *resp = TAB_busca(a->esq, x);
    if(resp){
        return resp;
    }
    return TAB_busca(a->dir, x);
}

void TAB_libera(TAB *a){
    if(a){
        TAB_libera(a->esq);
        TAB_libera(a->dir);
        free(a);
    }
}

// TAB *retira_pares(TAB *a){

// }

TLSE *ret_ans_aux(TAB *a, int x){
    if((!a) || (a->info == x)){
        return NULL;
    }
    if(TAB_busca(a->esq, x)){
        return tlse_insere_inicio(ret_ans_aux(a->esq, x), a->info);
    }
    return tlse_insere_inicio(ret_ans_aux(a->dir, x), a->info);
}

TLSE *retorna_ancestrais(TAB *a, int x){
    if((!a) || (!TAB_busca(a, x))){
        return NULL;
    }
    return ret_ans_aux(a, x);
}

int main(){
    TAB *a = TAB_inicializa();
    int altura;
    // cria da raiz para as folhas 
    a = TAB_cria(5, TAB_cria(3, NULL, NULL), TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(1, NULL, NULL)));
    altura = calcula_altura;(a);
    return 0;
}