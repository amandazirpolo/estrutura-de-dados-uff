/*(Q2) Retornar todos os ancestrais de um nó na árvore B,
da raiz da árvore até o elemento passado como parâmetro, usando 
a biblioteca de lista encadeada - 
TLSEINT* misc(TARVB *a, int elem), onde:*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "TLSEINT.c"
#include "TARVB.c"

TLSEINT *misc_aux(TARVB *a, int elem, TLSEINT *lista){
    if(!a) return lista;
    int i;
    while(i < a->nchaves && a->chave[i] < elem) i++;
    int inf = INT_MIN, sup = INT_MAX, resp;
    if(i) inf = a->chave[0]; // se i é diferente de 0, entao o limite min é o primeiro elemento do vetor
    /* se i é menor q o numero de chaves e a chave[i] é diferente do elemento,
    entao o limite superior é a chave[i] na pos i */
    if(i < a->nchaves && a->chave[i] != elem) sup = a->chave[i]; 
    /* se i é menor q o numero de chaves e a chave[i] é igual ao proprio elemento,
    verifica se i+1 é menor q o numero de chaves. se for, o limite superior recebe
    a ultima pos do vetor. se n, continua em intmax*/
    if(i < a->nchaves && a->chave[i] == elem){
        if(i + 1 < a->nchaves) sup = a->chave[a->nchaves - 1];
    }
    lista = misc_aux(a->filho[i], elem, lista);
    lista = TLSEINT_insere(lista, inf, sup);
    return lista;
}

TLSEINT *misc(TARVB *a, int elem){
    if(!a) return NULL;
    if(!TARVB_Busca(a, elem)) return NULL;
    TLSEINT *lista = NULL;
    return misc_aux(a, elem, lista);
}


int main(){
    TARVB *arvore = TARVB_Inicializa();
    int t;
    printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
    scanf("%d", &t);
    if(t < 2) t = 2;
    int num = 0, from, to;
    while(num != -1){
        printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
        scanf("%d", &num);
        if(num == -9){
        scanf("%d", &from);
        arvore = TARVB_Retira(arvore, from, t);
        TARVB_Imprime(arvore);
        }
        else if(num == -1){
        printf("\n");
        TARVB_Imprime(arvore);
        // TARVB_Libera(arvore);
        // return 0;
        }
        else if(!num){
        printf("\n");
        TARVB_Imprime(arvore);
        }
        else arvore = TARVB_Insere(arvore, num, t);
        printf("\n\n");
    }

    TLSEINT *ancestrais = misc(arvore, 9);
    TLSEINT_imprime(ancestrais);

    TLSEINT_libera(ancestrais);
    TARVB_Libera(arvore);
    return 0;
}