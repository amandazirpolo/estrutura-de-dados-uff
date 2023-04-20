#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.c"

int main(){
    TAB *arvore = TAB_inicializa();
    int x1 = 10, x2 = 4, x3 = 16;

    arvore = TAB_cria(x1,TAB_cria(x2,NULL,NULL),TAB_cria(x3,NULL,NULL));

    TAB_imp_pre(arvore);

    TAB_libera(arvore);

    return 0;
}