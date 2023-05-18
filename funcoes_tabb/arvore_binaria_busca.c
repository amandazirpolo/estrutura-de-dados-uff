#include <stdio.h>
#include <stdlib.h>
#include "func_li.c"

typedef struct arvbin_busca {
    int info;
    struct arvbin_busca *esq, *dir;
} TABB;

TABB *TABB_inicializa(void){
  return NULL;
}

TABB *TABB_cria(int raiz, TABB *esq, TABB *dir){
  TABB *novo = (TABB *) malloc(sizeof(TABB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  return novo;
}

TABB *menor(TABB *a){ /*menor nó da árvore*/
    if(!a){
        return a;
    }
    if(!a->esq){
        return a;
    }
    return menor(a->esq);
}

TABB *TABB_busca(TABB *a, int x){
    if((!a) || (a->info == x)){
        return a;
    }
    if(a->info < x){
        return TABB_busca(a->dir, x);
    }
    return TABB_busca(a->esq, x);
}

TABB *TABB_insere(TABB *a, int x){
    if(!a){
        return TABB_cria(x, NULL, NULL);
    }
    if(a->info > x){
        a->esq = TABB_insere(a->esq, x);
    } else if(a->info < x){
        a->dir = TABB_insere(a->dir, x);
    }
    return a;
}

TABB *TABB_retira(TABB *a, int x){
    if(!a){
        return a;
    }
    if(a->info > x){
        a->esq = TABB_retira(a->esq, x);
    } else if(a->info < x){
        a->dir = TABB_retira(a->esq, x);
    }
    else { /*x encontrado*/
        if((!a->esq) && (!a->dir)){ /*caso 1: folha*/
            free(a);
            a = NULL;
        } else if((!a->esq) || (!a->dir)){ /*caso 2: pai com 1 filho*/
            TABB *tmp = a;
            if(!a->esq){
                a = a->dir;
            } else{
                a = a->esq;
            }
            free(tmp);
        } else { /*caso 3: pai com 2 filhos*/
            TABB *filho = a->esq;
            while(filho->dir){
                filho = filho->dir;
            }
            a->info = a->info;
            filho->info = x;
            a->esq = TABB_retira(a->esq, x);
        }
    }
    return a;
}

void TABB_imp_sim(TABB *a){
  if(a){
    TABB_imp_sim(a->esq);
    printf("%d ", a->info);
    TABB_imp_sim(a->dir);
  }
}

void TABB_imp_pre(TABB *a){
  if(a){
    printf("%d ", a->info);
    TABB_imp_pre(a->esq);
    TABB_imp_pre(a->dir);
  }
}

void TABB_imp_pos(TABB *a){
  if(a){
    TABB_imp_pos(a->esq);
    TABB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

void imp_aux(TABB *a, int andar){
  int j;
  if(a){
    imp_aux(a->dir, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t"); //printf("   ");
    printf("%d\n", a->info);
    imp_aux(a->esq, andar + 1);
  }
  else{
   for(j = 0; j <= andar; j++) printf("\t");
   printf("N\n");
  }
}

void TABB_imp_ident(TABB *a){
  imp_aux(a, 0);
}


void TABB_libera(TABB *a){
  if(a){
    TABB_libera(a->esq);
    TABB_libera(a->dir);
    free(a);
  }
}

// int main(){
//     TABB *a = TABB_inicializa();

//     a = TABB_cria(2, (TABB_cria(1, NULL, NULL)), TABB_cria(4, TABB_cria(3, NULL, NULL), NULL));

//     TABB_imp_sim(a);
//     printf("\n");
//     TABB_imp_pos(a);
//     printf("\n");
//     TABB_imp_pre(a);
//     printf("\n \n \n");
//     TABB_imp_ident(a);
//     printf("\n");

//     TABB_libera(a);

//     return 0;
// }