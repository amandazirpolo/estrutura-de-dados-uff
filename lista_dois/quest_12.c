/* Testar se duas árvores possuem as mesmas informações - int mi(TAB *a1, TAB *a2);*/

#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.c"

// int mesmas_informacoes(TAB *a1, TAB *a2){
//     if(!a1 && !a2){
//         return 1;
//     }
//     if(!a1 || !a2){
//         return 0;
//     }
//     TAB *procura_info = TAB_busca(a1, a2->info);
//     /*se o elemento de a2 estiver em a1 continua a busca*/
//     /*primeiro procura em toda a esquerda e depois em toda a direita*/
//     if((procura_info->info == a2->info) && (mesmas_informacoes(a1, a2->esq)) && (mesmas_informacoes(a1, a2->dir))){
//         return 1;
//     }
//     return 0;
// }

int mesmas_aux(TAB *a1, TAB *a2){
    if(!a2) return 1;
    return TAB_busca(a1, a2->info) && mesmas_aux(a1, a2->esq) && mesmas_aux(a1, a2->dir);
}

int mesmas_informacoes(TAB *a1, TAB *a2){
    if(!a1 && !a2)
        return 1;
    if(!a1 || !a2)
        return 0;
    return TAB_busca(a1, a2->info) && mesmas_aux(a1, a2->esq) && mesmas_aux(a1, a2->dir);
}

int main(){
    TAB *a = TAB_inicializa(), *b = TAB_inicializa();
    int mi;

    a = TAB_cria(10, TAB_cria(13, TAB_cria(14, NULL, NULL), TAB_cria(15, NULL, NULL)), TAB_cria(11, TAB_cria(16, NULL, NULL), TAB_cria(17, NULL, NULL)));
    b = TAB_cria(10, TAB_cria(11, TAB_cria(14, NULL, NULL), TAB_cria(15, NULL, NULL)), TAB_cria(13, TAB_cria(16, NULL, NULL), TAB_cria(17, NULL, NULL)));

    printf("arvore 1: \n");
    TAB_imp_ident(a);
    printf("\n\n arvore 2: \n");
    TAB_imp_ident(b);

    mi = mesmas_informacoes(a, b);
    if(mi){
        printf("\n as arvores possuem as mesmas informacoes \n");
    } else {
        printf("\n a arvores nao possuem as mesmas informacoes \n");
    }
        
    TAB_libera(a);
    TAB_libera(b);
    return 0;
}