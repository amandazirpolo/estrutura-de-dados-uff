#include <stdio.h>
#include "arvore_binaria_busca.c"

int main(){
    TABB *a = TABB_inicializa();

    a = TABB_insere(a, 64);
    a = TABB_insere(a, 59);
    a = TABB_insere(a, 95);
    a = TABB_insere(a, 66);
    a = TABB_insere(a, 90);
    a = TABB_insere(a, 68);
    
    TABB_imp_ident(a);

    TABB_libera(a);

}