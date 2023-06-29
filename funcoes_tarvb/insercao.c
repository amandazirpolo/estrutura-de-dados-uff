#include <stdio.h>
#include <stdlib.h>
#include "TARVB.c"

int main(){
    TARVB *a;

    a = TARVB_Cria(2);

    a = TARVB_Insere(a, 20, 2);
    a = TARVB_Insere(a, 50, 2);
    a = TARVB_Insere(a, 60, 2);
    a = TARVB_Insere(a, 1, 2);
    a = TARVB_Insere(a, 64, 2);
    a = TARVB_Insere(a, 12, 2);
    a = TARVB_Insere(a, 18, 2);
    a = TARVB_Insere(a, 66, 2);
    a = TARVB_Insere(a, 38, 2);
    a = TARVB_Insere(a, 95, 2);
    a = TARVB_Insere(a, 58, 2);
    a = TARVB_Insere(a, 59, 2);
    a = TARVB_Insere(a, 70, 2);
    a = TARVB_Insere(a, 68, 2);
    a = TARVB_Insere(a, 39, 2);
    a = TARVB_Insere(a, 62, 2);
    a = TARVB_Insere(a, 7, 2);
    a = TARVB_Insere(a, 55, 2);
    a = TARVB_Insere(a, 43, 2);
    a = TARVB_Insere(a, 16, 2);
    a = TARVB_Insere(a, 67, 2);    
    a = TARVB_Insere(a, 34, 2);
    a = TARVB_Insere(a, 35, 2);

    // a = TARVB_Retira(a, 50, 2);
    a = TARVB_Retira(a, 95, 2);
    a = TARVB_Retira(a, 70, 2);
    a = TARVB_Retira(a, 60, 2);
    a = TARVB_Retira(a, 35, 2);

    TARVB_Imprime(a);

    TARVB_Libera(a);
    return 0;
}