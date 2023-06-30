int* mN(TARVB*a, int N, int *tam);*/

#include <stdio.h>
#include <stdlib.h>
#include "TARVB.c"

int maiores_que_n(TARVB *a, int n){
    if(!a) return 0;
    int i, cont = 0;