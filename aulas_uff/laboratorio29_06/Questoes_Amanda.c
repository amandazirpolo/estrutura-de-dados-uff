
// Questao 1 - Retorna todos os elementos maiores doq um numero N em uma arvore B. (No nosso codigo, repara que o percorrimento garante que esse vetor tambem eh construido ordenado)

int *mN(TARVB *a, int N, int *tam){
	int num = numElemMaioresN(a,N);
	int *vet = (int*)malloc(num*sizeof(int));
	int pos = 0;
	vetorMaiorN(a,N,vet,&pos);
	return vet;
}

int numElemMaioresN(TARVB *a, int N){
	if(!a) return 0;
	int i, n = 0;
	for(i = 0; i < a->nchaves; i++){
		if(a->chave[i] > N){
			n += numElemMaioresN(a->filho[i],N);
			n++;
		}
	}
	n += numElemMaioresN(a->filho[a->nchaves],N);
	return n;
}

void vetorMaiorN(TARVB* a, int N, int*vet, int *pos){
	if(!a) return;
	int i;
	for(i = 0; i < a->nchaves; i++){
		if(a->chave[i] > N){
			vetorMaiorN(a->filho[i],N,vet,pos);
			vet[*pos] = a->chave[i];
			(*pos)++;
		}
	}
	vetorMaiorN(a->filho[i],N,vet,pos);
	return;
}



// Questao 2 - Retorna ancestrais de um elemento da arvore B

TLSEINT* misc(TARVB* a, int elem){
	if(!TARVB_busca(a,elem)) return NULL;
	TLSEINT * l = NULL;
	return misc_aux(a,elem,l);
}

TLSEINT *misc_aux(TARVB* a, int elem, TLSEINT *l){
	if(!a) return l;
	int linf = INT_MIN, lsup = INT_MAX, i = 0;
	while(i< a->nchaves && a->chave[i] < elem) i++;
	if(i) linf = a->chave[0];
	if(i < a->nchaves && a->chave[i] != elem) lsup = a->chave[i];
	if(i < a->nchaves && a->chave[i] == elem){
		if(i+1 < a->nchaves) lsup = a->chave[a->nchaves-1];
	}
	l = misc_aux(a->filho[i],elem,l);
	l = TLSEINT_insere(l,inf,sup);
	return l;
}


