/*implemente um procedimento que, dados uma tabela hash, uma matrícula e um cr,
retire dessa tabela todos os dados com a mesma colisão da matrícula passada
como parâmetro de entrada, e que tenham cr menor ou igual ao cr supracitado:
void f(char *hash, char *dados, int N, int mat, float cr);*/

// sendo N o tamanho da hash

#include <stdio.h>
#include <stdlib.h>
#include "TH.c"

void f(char *hash, char *dados, int N, int mat, float cr){
    FILE *arquivo_hash = fopen(hash, "rb");
    if(!arquivo_hash) exit(1);
    int posicao, hash = TH_hash(mat, N); // calcula o tamanho da hash
    fseek(arquivo_hash, hash * sizeof(int), SEEK_SET); // posiciona o ponteiro no arquivo na pos indicada pela hash
    fread(&posicao, sizeof(int), 1, arquivo_hash); // le a linha e guarda a informação na variavel int posicao
    fclose(arquivo_hash); // fecha o arquivo de hash

    /*modo rb+ permite escrita e leitura */
    FILE *arquivo_dados = fopen(dados, "rb+");
    if(!arquivo_dados) exit(1);
    TA aux;
    // fseek(arquivo_dados, posicao * sizeof(TA), SEEK_SET);
    // fread(&aux, sizeof(TA), 1, arquivo_dados);
    // // if(aux.prox == -1){ // só tem um elemento, então a checagem ocorre pro primeiro
    //     if(aux.cr <= cr){
    //         aux.status = -1; // -1 no status significa que o elemento foi removido
    //         fseek(arquivo_dados, posicao * sizeof(TA), SEEK_SET); // reposiciona o ponteiro para o arquivo
    //         fwrite(&aux, sizeof(TA), 1, arquivo_dados);
    //         fclose(arquivo_dados);
    //         return;
    //     }
    // }
    while(posicao != -1){ // enquanto o proximo endereço for diferente de -1, ou seja, nao chegar no ultimo elemento
        fseek(arquivo_dados, posicao * sizeof(TA), SEEK_SET);
        fread(&aux, sizeof(TA), 1, arquivo_dados);
        if(aux.cr <= cr){
            aux.status = -1;
            fseek(arquivo_dados, posicao * sizeof(TA), SEEK_SET);
            fwrite(&aux, sizeof(TA), 1, arquivo_dados);
        }
        posicao = aux.prox;
    }
    fclose(arquivo_dados);
    return;
}

int main(void){
  int m;
  printf("Digite o tamanho da hash... ");
  scanf("%d", &m);

  if(m <= 1) return 0;

  char nome_dados[31], nome_hash[31];
  printf("Digite nome do arquivo de dados... ");
  scanf("%s", nome_dados);
  printf("Digite nome do arquivo de hash... ");
  scanf("%s", nome_hash);

  TH_inicializa(nome_hash, nome_dados, m);

  int mat;
  float cr;
  do{
    printf("Digite a matricula e o cr...\n");
    scanf("%d", &mat);
    scanf("%f", &cr);
    if(mat <= 0) break;
    TH_insere(nome_hash, nome_dados, m, mat, cr);
  }while(1);
  TH_imprime(nome_hash, nome_dados, m);

  char resp;
  do{
    printf("Digite a matricula a ser removida... ");
    scanf("%d", &mat);
    cr = TH_retira(nome_hash, nome_dados, m, mat);
    if(cr != -1) printf("%d %f saiu\n", mat, cr);
    printf("Quer continuar? ");
    scanf(" %c", &resp);
  }while((resp != 'N') && (resp != 'n'));
  TH_imprime(nome_hash, nome_dados, m);

  return 0;
}