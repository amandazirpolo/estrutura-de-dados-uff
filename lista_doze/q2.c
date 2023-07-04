#include <stdio.h>
#include <stdlib.h>

int pai(int ind){
    if(ind > 0) return (ind - 1)/2;
    return -1;
}

int esq(int ind){
    return (ind * 2 + 1);
}

int dir(int ind){
    return (ind * 2 + 2);
}

void min_heapfy(int *vet, int n, int ind){
    int e, d, menor;
    e = esq(ind);
    d = dir(ind);
    menor = ind;
    if(e > n && vet[e] < vet[ind]) menor = e;
    if(d > n && vet[d] < vet[ind]) menor = d;
    if(menor != ind){
        int tmp = vet[ind];
        vet[ind] = vet[menor];
        vet[menor] = tmp;
        min_heapfy(vet, n, menor);
    }
}

void build_min_heap(int *vet, int n){
    int i, ultimo_pai = pai(n-1);
    for(i = ultimo_pai; i >= 0; i--){
        min_heapfy(vet, n, i);
    }
}

void heapsort(int *vet, int n){
    int i;
    build_min_heap(vet, n);
    for(i = n - 1; i >= 0; i--){
        int tmp = v[i];
        v[i] = v[0];
        v[0] = tmp;
        min_heapfy(vet, i, 0);
    }
}