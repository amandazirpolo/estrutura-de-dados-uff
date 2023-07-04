#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
  int mat, prox, status;
  float cr;
}TA;

int TH_hash(int mat, int tam){
  return mat % tam;
}

void TH_inicializa(char *arq, char *dados, int n){
  FILE *fp = fopen(dados, "wb");
  if(!fp) exit(1);
  fclose(fp);
  fp = fopen(arq, "wb");
  if(!fp) exit(1);
  int i, elem = -1;
  // inicializa todas as posições do arquivo de hash com -1
  for(i = 0; i < n; i++)fwrite(&elem, sizeof(int), 1, fp);
  fclose(fp);
}

TA* TH_aloca(int mat, float cr){
  // aloca cada nó do arquivo de dados
  TA *novo = (TA*)malloc(sizeof(TA));
  novo->mat = mat;
  novo->cr = cr;
  novo->prox = -1;
  novo->status = 1;
  return novo;
}

TA* TH_busca(char *tabHash, char *dados, int n, int mat){
  // abre o arquivo de hash
  FILE *fp = fopen(tabHash,"rb");
  if(!fp)exit(1);
  /* inicializa a posicao e calcula em que posicao do arquivo está a informação,
    usando a função de hash
  */
  int pos, h = TH_hash(mat,n);
  // pula para a pos informada pela função de hash 
  fseek(fp, h*sizeof(int), SEEK_SET);
  fread(&pos, sizeof(int), 1, fp); // le a linha do arquivo
  fclose(fp); // fecha o arquivo
  if(pos == -1)return NULL; // se a pos for -1, entao o elemento n esta na estrutura
  fp = fopen(dados,"rb"); // abre o arquivo de dados
  if(!fp) exit(1);
  fseek(fp, pos, SEEK_SET); // posiciona no arquivo na pos desejaca
  TA aux; // cria uma variavel auxiliar do tipo ta para separar as informações
  fread(&aux, sizeof(TA), 1, fp); // le a linha e coloca na variavel auxiliar
  while(1){ // enquanto o arquivo existir
    if((aux.mat == mat) && (aux.status)){ // verifica se a matricula é igual a matricula desejada e verifica se ta vivo ou morto
      TA *resp = TH_aloca(aux.mat, aux.cr); // aloca o no q sera retornado passando a matricula e o cr do aluno
      resp->prox = aux.prox; // encadeia os ponteiros
      fclose(fp); // fecha o arquivo
      return resp; // retorna o valor de resp
    }
    // se isso aqui acontece, a informação n esta na lista
    if(aux.prox == -1){ // se aux->prox for igual a -1, nao tem ninguem depois dele
      fclose(fp); // fecha o arquivo e retorna null
      return NULL;
    }
    fseek(fp, aux.prox, SEEK_SET); // faz o ponteiro apontar pro proximo do elemento q acabou de ser lido
    fread(&aux, sizeof(TA), 1, fp); // le novamente a linha
  }
}

float TH_retira(char *tabHash, char *arq, int n, int mat){
  FILE *fp = fopen(tabHash,"rb"); // abre o arquivo de hash
  if(!fp) exit(1); //
  int pos, h = TH_hash(mat,n); // calcula a pos usando a função de hash
  fseek(fp, h*sizeof(int), SEEK_SET); // coloca o ponteiro na pos desejada
  fread(&pos, sizeof(int), 1, fp); // le o endereço do arquivo de hash
  fclose(fp); // fecha o arquivo de hash 
  if(pos == -1)return -1; // se a pos for -1 entao ta vazio 
  float cr = -1; // começa cr com -1
  fp = fopen(arq,"rb+"); // abre o arquivo de dados
  if(!fp)exit(1);
  TA aux; // cria uma variavel do tipo ta auxiliar
  while(1){ // enquanto o arquivo existir
    fseek(fp, pos, SEEK_SET); // posiciona o ponteiro na pos desejada
    fread(&aux, sizeof(TA), 1, fp); // le a linha
    if((aux.mat == mat) && (aux.status)){ // ve se a matricula é igual a desejada e verifica se o status ta vivo ou morto
      cr = aux.cr; // zera o cr
      aux.status = 0; // zera o status
      fseek(fp, pos, SEEK_SET); // posiciona o ponteiro novamente
      fwrite(&aux, sizeof(TA), 1, fp); // escreve na linha
      fclose(fp); // fecha o arquivo
      return cr; // retorna -1
    }
    if(aux.prox == -1){ // se for -1, chegou no final do encadeamento da hash
      fclose(fp);
      return cr;
    }
    pos = aux.prox; // atualiza a posicao e vai pro proximo
  }
}

void TH_insere(char *tabHash, char *arq, int n, int mat, float cr){
  FILE *fph = fopen(tabHash, "rb+"); // abre o arquivo de hash
  if(!fph) exit(1);
  int pos, h = TH_hash(mat, n); // calcula a pos usando a função de hash
  fseek(fph, h*sizeof(int), SEEK_SET); // posiciona o ponteiro na pos certa do arquivo
  fread(&pos, sizeof(int), 1, fph); // le o arquivo na pos certa
  int ant, prim_pos_livre;
  ant = prim_pos_livre = -1; // seta o anterior como a primeira pos livre = -1
  FILE *fp = fopen(arq,"rb+"); // abre o arquivo de dados
  if(!fp){
    fclose(fph);
    exit(1);
  }
  TA aux; // cria uma variável auxiliar do tipo aluno
  while(pos != -1){ // enqt a pos for diferente de -1, ou seja, enqt n chegar na ultima pos da hash
    fseek(fp, pos, SEEK_SET); // posiciona o ponteiro na pos certa
    fread(&aux, sizeof(TA), 1, fp); // le a linha
    if(aux.mat == mat){ // se mat for igual a matricula passada como parametro
      aux.cr = cr; // aux recebe cr
      aux.status = 1; // status recebe 1 de ativo 
      fseek(fp, pos, SEEK_SET); // posiciona o arquivo no lugar certo 
      fwrite(&aux, sizeof(TA), 1, fp); // escreve as informacoes
      fclose(fp); // fecha o arquivo de dados
      fclose(fph); // fecha o arquivo de hash
      return;
    }
    if((!aux.status) && (prim_pos_livre == -1))prim_pos_livre=pos; // se o status tiver morto e a pos for -1, atualiza a pos pra primeira_pos_livre
    ant = pos;
    pos = aux.prox;
  }
  if(prim_pos_livre == -1){ // se for menos 1 entao so insere mesmo 
    aux.mat = mat; // recebe os dados
    aux.cr = cr;
    aux.prox = -1;
    aux.status = 1;
    fseek(fp, 0L, SEEK_END); // posiciona o ponteiro no lugar certo
    pos = ftell(fp); // diz em q pos o ponteiro esta
    fwrite(&aux, sizeof(TA), 1, fp); // escreve no arquivo
    if(ant != -1){ // se anterior for igual a -1
      fseek(fp, ant, SEEK_SET); // posiciona o ponteiro passando anterior
      fread(&aux, sizeof(TA), 1, fp); // le a linha do arquivo 
      aux.prox = pos; // atualiza a posicao 
      fseek(fp, ant, SEEK_SET); // posiciona o ponteiro 
      fwrite(&aux, sizeof(TA), 1, fp); // escreve no arquivo
    }
    else{
      fseek(fph, h*sizeof(int), SEEK_SET); // atualiza o ponteiro no arquivo de hash
      fwrite(&pos, sizeof(int), 1, fph); // escreve no arquivo
    }
    fclose(fp); // fecha os 2 arquivos
    fclose(fph); // fecha os 2 arquivos
    return;
  }
  fseek(fp, prim_pos_livre, SEEK_SET); // coloca o ponteiro na primeira posicao livre
  fread(&aux, sizeof(TA), 1, fp); // le 
  aux.mat = mat; // atualiza os valores
  aux.cr = cr;
  aux.status = 1;
  fseek(fp, prim_pos_livre, SEEK_SET); // reposiciona o pnteiro
  fwrite(&aux, sizeof(TA), 1, fp); // escreve
  fclose(fp); // fecha os 2 arquivos
  fclose(fph);
  return;
}

void TH_imprime (char *nome_hash, char *nome_dados, int m){
  FILE *fp = fopen(nome_hash, "rb");
  if(!fp) exit(1);
  int vet[m];
  fread(&vet, sizeof(int), m, fp);
  fclose(fp);

  fp = fopen(nome_dados, "rb");
  if(!fp) exit(1);
  int i, pos;
  for(i = 0; i < m; i++){
    int p = vet[i];
    if(p != -1) printf("%d:\n", i);
    TA x;
    while(p != -1){
      fseek(fp, p, SEEK_SET);
      pos = ftell (fp);
      fread(&x, sizeof(TA), 1, fp);
      printf("$%d: matricula: %d\tcr: %f\tstatus: %d\tprox_end: $%d\n", pos, x.mat, x.cr, x.status, x.prox);
      p = x.prox;
    }
  }
  fclose(fp);
}
