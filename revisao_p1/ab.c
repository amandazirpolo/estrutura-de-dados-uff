#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_ab.c"

/* q1 */
TAB *copia(TAB *a){
    if(!a) return a;
    return TAB_cria(a->info, copia(a->esq), copia(a->dir));
}

/* q2 */
TAB *espelho(TAB *a){
    if(!a) return a;
    return TAB_cria(a->info, espelho(a->dir), espelho(a->esq));
}

/* q3 */ 
TAB *maior_aux(TAB *a, TAB *maior){
    if(!a) return maior;
    maior = maior_aux(a->esq, maior);
    if(a->info > maior->info) return a;
    maior = maior_aux(a->dir, maior);
    if(a->info > maior->info) return a;
    return maior;
}

TAB *maior(TAB *a){
    if(!a) return NULL;
    TAB *aux = a;
    return maior_aux(aux, a);
}

/* q4 */
TAB *menor_aux(TAB *a, TAB *menor){
    if(!a) return menor;
    menor = menor_aux(a->esq, menor);
    if(a->info < menor->info) return a;
    menor = menor_aux(a->dir, menor);
    if(a->info < menor->info) return a;
    return menor;
}

TAB *menor(TAB *a){
    if(!a) return NULL;
    TAB *aux = a;
    return menor_aux(aux, a);
}

/* q5 */
int igual(TAB* a1, TAB* a2){
    if(!a1 && !a2) return 1;
    if(a1->info == a2->info){
        return igual(a1->esq, a2->esq) && igual(a1->dir, a2->dir);
    } else return 0;
}

/* q6 */
TAB *retira_pares(TAB* a){
    if(!a) return a;
    a->esq = retira_pares(a->esq);
    a->dir = retira_pares(a->dir);
    if(a->info % 2 == 0){
        TAB *tmp = NULL;
        /* caso 1: é uma folha*/
        if(!a->esq && !a->dir){
            tmp = a;
            a = NULL;
            free(tmp);
        } 
        /* caso 2: é um pai com um filho só */
        else if(!a->esq || !a->dir){
            if(!a->esq){
                tmp = a;
                a = a->dir;
            } else {
                tmp = a;
                a = a->esq;
            }
            free(tmp);
        } 
        /* caso 3: é um pai com dois filhos */
        else {
            TAB *aux = a->esq;
            while(aux->dir){
                aux = aux->dir;
            }
            a->info = aux->info;
            aux->info = 2; // força o ultimo a ser par
            a = retira_pares(a);
        }
    }
    return a;
}

/* q7 */


/* q8 */
int ni(TAB *a){
    if(!a) return 0;
    if(!a->esq && !a->dir) return ni(a->esq) + ni(a->dir);
    else return ni(a->esq) + ni(a->dir) + 1;
}

/* q9 */
int nf(TAB *a){
    if(!a) return 0;
    if(!a->esq && !a->dir) return nf(a->esq) + nf(a->dir) + 1;
    else return nf(a->esq) + nf(a->dir);
}

/* q10 */
int zz(TAB *a){
    if(!a) return 1;
    if(a->esq && a->dir) return 0; // não é zigue zague
    if(!a->esq || !a->dir){
        if(!a->esq) return zz(a->dir);
        if(!a->dir) return zz(a->esq);
    }
}

/* q11 */
int estbin(TAB *a){
    if(!a) return 1;
    if((!a->esq && !a->dir) || (a->esq && a->dir)) return estbin(a->esq) && estbin(a->dir);
    else return 0;
}

/* q12 */
int mi(TAB *a1, TAB *a2){
    if((a1 && !a2) || (!a1 && a2)) return 0;
    if(TAB_busca(a1, a2->info)) return mi(a1, a2->esq) + mi(a1, a2->dir);
    else return 0;
}

int main(){
    TAB *a = TAB_inicializa(), *b = TAB_inicializa();

    // a = TAB_cria(3, TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(1, NULL, NULL)), TAB_cria(5, TAB_cria(9, NULL, NULL), TAB_cria(10, TAB_cria(11, NULL, NULL), TAB_cria(8, TAB_cria(7, NULL, NULL), NULL))));
    a = TAB_cria(3, TAB_cria(2, NULL, NULL), TAB_cria(4, NULL, TAB_cria(1, NULL, NULL)));
    b = TAB_cria(1, TAB_cria(2, NULL, NULL), TAB_cria(3, NULL, TAB_cria(4, NULL, NULL)));
    
    // printf("arvore original: \n");
    // TAB_imp_ident(a);

    // printf("arvore sem pares: \n");
    // a = retira_pares(a);
    TAB_imp_ident(a);
    TAB_imp_ident(b);

    if(mi(a, b)){
        printf("a1 e a2 possuem as mesmas informacoes. \n");
    } else {
        printf("a1 e a2 nao possuem as mesmas informacoes. \n");
    }

    TAB_libera(a);

    return 0;
}