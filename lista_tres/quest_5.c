/*Retornar todos os ancestrais de um nó na árvore de busca binária, da raiz da árvore até o elemento 
passado como parâmetro, usando a biblioteca de lista encadeada - TLSE* ancestrais(TABB *a, int elem);*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_busca.c"

// TLSE *rda(TABB *a, int elem){
//     if((!a) || (a->info == elem)){
//         return NULL;
//     }
//     if(TABB_busca(a->esq, elem)){
//         return tlse_insere_inicio(rda(a->esq, elem), a->info);
//     }
//     return tlse_insere_inicio(rda(a->dir, elem), a->info);
// }

// TLSE *retorna_ancestrais(TABB *a, int elem){
//     if((!a) || (!TABB_busca(a, elem))){
//         return NULL;
//     }
//     return rda(a, elem);
// }

TLSE *ancestrais_aux(TLSE *lista, TABB *a, int elem){
    if(a->info > elem){
        lista = tlse_insere_inicio(lista, a->info);
        return ancestrais_aux(lista, a->esq, elem);
    }
    else if(a->info < elem){
        lista = tlse_insere_inicio(lista, a->info);
        return ancestrais_aux(lista, a->dir, elem);
    }
    else {
        return lista;
    }
}

TLSE *ancestrais_amanda(TABB *a, int elem){
    if(!a){
        return NULL;
    }
    if(!TABB_busca(a, elem)){
        return NULL;
    }
    TLSE *lista_ancestrais = tlse_inicializa();
    return ancestrais_aux(lista_ancestrais, a, elem);
}

int main(){
    TABB *a = TABB_inicializa();
    TLSE *l_ancestrais = tlse_inicializa();
    int elemento = 9;

    a = TABB_insere(a, 10);
    a = TABB_insere(a, 8);
    a = TABB_insere(a, 12);
    a = TABB_insere(a, 4);
    a = TABB_insere(a, 9);
    a = TABB_insere(a, 2);
    a = TABB_insere(a, 11);
    a = TABB_insere(a, 13);
    a = TABB_insere(a, 5);
    a = TABB_insere(a, 17);
    a = TABB_insere(a, 15);

    printf("arvore: \n");
    TABB_imp_ident(a);

    printf("\n\n ancestrais do elemento %d: \n", elemento);
    l_ancestrais = ancestrais_amanda(a, elemento);
    tlse_imprime(l_ancestrais);
    
    TABB_libera(a);
    tlse_libera(l_ancestrais);

    return 0;
}