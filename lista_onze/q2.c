/* Q2) sucessor de um elemento na árvore. Se o elemento for o maior da estrutura, sua
função deve retornar INT_MAX: int suc (TARVB *a, int elem); */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "TARVB.c"

int suc_aux(TARVB *a, int elem){
    if(!a) return 0;
    int i, resp;
    for(i = 0; i < a->nchaves; i++){
        if(a->chave[i] > elem){
            resp = suc(a->filho[i], elem);
            // se tem apenas 1 elemento, nao tem sucessor
            if(a->nchaves == 1) resp = INT_MAX;
            // se o elemento da ultima pos do vetor for igual ao parametro, n tem sucessor
            if(i < a->nchaves && a->chave[a->nchaves - 1] == elem) resp = INT_MAX;
            /* se chave[i] é igual ao elemento e i + 1 for menor q o numero de chaves, o sucessor 
            é o valor q esta na ultima pos do vetor */
            if(i < a->nchaves && a->chave[i] == elem){
                if(i + 1 < a->nchaves) resp = a->chave[a->nchaves - 1];
            }
            printf("%d \n", resp);
        }
    }
    // chama a recursao pra direita do ultimo no
    resp = suc(a->filho[a->nchaves], elem);
    return resp;
}

int suc(TARVB *a, int elem){
    if(!a) return 0;
    // fiz aqui pra arvore nao perder a referencia do elemento ja q a arvore vai ser partida na recursao
    if(!TARVB_Busca(a, elem)) return 0;
    return suc_aux(a, elem);
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
        break;
        }
        else if(!num){
        printf("\n");
        TARVB_Imprime(arvore);
        }
        else arvore = TARVB_Insere(arvore, num, t);
        printf("\n\n");
    }

    int sucessor = suc(arvore, 9);
    printf("o sucessor do elemento escolhido eh %d \n", sucessor);

    TARVB_Libera(arvore);

    return 0;
}