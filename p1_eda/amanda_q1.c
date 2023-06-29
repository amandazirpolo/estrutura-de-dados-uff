#include <stdio.h>
#include <stdlib.h>
#include "TAB_prova.c"

typedef struct le {
    int info;
    struct le *prox;
} TLSE;

TLSE* TLSE_insere(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
}

TLSE* TLSE_busca(TLSE *l, int elem){
  TLSE *p = l;
  while((p) && (p->info != elem)) p = p->prox; 
  return p;
}

void TLSE_imprime(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("%d ", p->info);
    p = p->prox;
  } 
}

void TLSE_libera(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

/* exercicio começa a partir daquiii */
TLSE *TLSE_insere_ordenado(TLSE *lista, int x){
    TLSE *anterior = NULL, *atual = lista;
    TLSE *novo = (TLSE*)malloc(sizeof(TLSE));
    while((atual) && (x > atual->info)){
        anterior = atual;
        atual = atual->prox;
    }
    if(!anterior) {
        lista = TLSE_insere(lista, x);
        return lista;
    }
    novo->info = x;
    anterior->prox = novo;
    novo->prox = atual;
    return lista;
}

TLSE *entre_aux(TAB *a, int n, int m, TLSE *lista){
    if(!a) return lista;
    if((a->info > n) && (a->info < m)){
        if(TAB_busca(a->esq, a->info)){ // se o elemento estiver na esquerda entao insere passando a recursao pra direita
            return TLSE_insere_ordenado(entre_aux(a->esq, n, m, lista), a->info);
        }
        // se n tiver na esquerda ent ta na direita
        return TLSE_insere_ordenado(entre_aux(a->dir, n, m, lista), a->info);
    }
    lista = entre_aux(a->esq, n, m, lista); // caso o elemento n esteja entre n e m entao so percorre
    lista = entre_aux(a->dir, n, m, lista);
}

TLSE *entre(TAB *a, int n, int m){
    if(!a) return NULL;
    TLSE *lista_entre = NULL;
    return entre_aux(a, n, m, lista_entre);
}

int main(){
    int no, pai;
    printf("Digite a raiz da arvore... ");
    scanf("%d", &no);
    TAB *a = TAB_cria(no, NULL, NULL), *resp;
    char repete;
    do{
        char lado[2];
        printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
        scanf(" %c", &repete);
        if((repete == 'N') || (repete == 'n')) break;
        printf("Digite o pai (que deve existir), o filho a ser inserido e a posição E(ESQ) ou D(DIR)... ");
        scanf("%d%d%s", &pai, &no, lado);
        resp = TAB_busca(a, pai);
        if(!resp){
        TAB_libera(a);
        return 0;
        }
        if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
        else resp->dir = TAB_cria(no, NULL, NULL);
    }while(1);
    TAB_imp_ident(a);
    printf("\n");
    
    int n, m;
    printf("Digite n e m... ");
    scanf("%d%d", &n, &m);
    TLSE *l = NULL;
    l = entre(a, n, m);
    TLSE_imprime(l); 
    TLSE_libera(l);
    
    TAB_libera(a);
    return 0;
}
