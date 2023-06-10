#include <stdio.h>
#include <stdlib.h>

typedef struct arvb{
    int nchaves, *chave, folha;
    struct arvb **filho;
}TARVB;

TARVB *TARVB_inicializa(){
    return NULL;
}

TARVB *TARVB_cria(int t){
    TARVB *a = (TARVB*)malloc(sizeof(TARVB));
    a->nchaves = 0;
    a->folha = 1;
    a->chave = (int*)malloc(sizeof(int)*((2*t) - 1));
    a->filho = (TARVB**)malloc(sizeof(TARVB) * (2*t));
    for(int i = 0; i < 2*t; i++){
        a->filho[i] = NULL;
    }
    return a;
}

void TARVB_libera(TARVB *a){
    if(!a) return;
    int i;
    for(i = 0; i <= a->nchaves; i++){
        TARVB_libera(a->filho[i]);
    }
    free(a->filho);
    free(a->chave);
    free(a);
}

TARVB *TARBV_busca(TARVB *a, int x){
    if(!a) return a;
    int i = 0;
    /* busca sequencial no nó */
    while((i < a->nchaves) && (a->chave[i] < x)){
        i++;
    }
    if((i < a->nchaves) && (x == a->chave[i])) return a;
    return TARBV_busca(a->filho[i], x);
}

void TARVB_imprime(TARVB *a){
    if(!a) return;
    int i;
    for(i = 0, i < a->nchaves; i++){
        TARVB_imprime(a->filho[i]);
        printf("%d\n", a->chave[i]);
    }
    TARVB_imprime(a->filho[i]);
}

TARVB *TARVB_divisao(TARVB *a, int pos, TARVB *filho, int t){
    TARVB *z = TARVB_cria(t);
    z->folha = filho->folha; /*cria um nó z auxiliar*/
    z->nchaves = t-1; // informa se o filho é folha ou não
    int j;
    for(j = 0; j < t-1; j++){ 
        z->chave[j] = filho->chave[j+t];
    }
    if(!filho->folha){ // verifica se o filho é follha ou não
        for(j = 0; j < t; j++){
            z->filho[j] = filho->filho[j+t]; // z recebe o filho
            filho->filho[j+t] = NULL; // o filho do filho é folha 
        }
    }
    filho->nchaves = t-1;
    for(j = a->nchaves; j >= pos; j--){
        a->filho[j+1] = a->filho[j];
    }
    a->filho[pos] = z;
    for(j = a->nchaves; j >= pos; j--){
        a->chave[j] = a->chave[j-1];
    }
    a->chave[pos-1] = filho->chave[t-1];
    a->nchaves++;
    return a;
}

TARVB *TARVB_ins_nao_completo(TARVB *a, int ch, int t){
    int i = a->nchaves - 1;
    if(a->folha){
        while((i >= 0) && (ch < a->chave[i])){
            a->chave[i+1] = a->chave[i];
            i--;
        }
        a->chave[i+1] = ch;
        a->nchaves++;
        return a;
    }
    while((i >= 0) && (ch < a->chave[i])){
        i--;
    }
    i++;
    if((a->filho[i]->nchaves) == ((2*t) - 1)){
        a = TARVB_divisao(a, (i+1), a->filho[i], t);
        if(ch > a->chave[i]) i++;
    }
    a->filho[i] = TARVB_ins_nao_completo(a->filho[i], ch, t);
    return a;
}

TARVB *TARVB_insere(TARVB *a, int ch, int t){
    if(TARBV_busca(a, ch)) return a;
    if(!a){ /* caso 1: arvore vazia*/
        a = TARVB_cria(t);
        a->nchaves = 1;
        a->chave[0] = ch;
        return a;
    }
    if(a->nchaves == (2*t) - 1){ /*caso 2: arvore cheia. divide os nós*/
        TARVB *A = TARVB_cria(t);
        A->folha = 0;
        A->filho[0] = a;
        A = TARVB_divisao(A, 1, a, t); // q porra eh essa
        A = TARVB_ins_nao_completo(a, ch, t);
        return A;
    }
    a = TARVB_insere_nao_completo(a, ch, t); /* caso 3: arvore existe e ainda n esta cheia */
    return a;
}