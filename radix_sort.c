#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM1 50000
#define TAM2 100000
#define TAM3 500000

void lerArquivo(int dados[]){

	int coluna = 0;

	FILE *arquivo;

	// Primeiro argumento é o diretorio a qual o arquivo BASE.TXT estar
	//Mudar conforme a instancia.
	arquivo = fopen("base_50_000.txt","r");

	if (arquivo == NULL){
		printf("Não foi possivel abrir o arquivo");
	}else{
		while((fscanf(arquivo,"%d",&dados[coluna])) != EOF){
			coluna++;
		}
	}
}

double radixsort(int vetor[], int tamanho) {
clock_t begin, end;
double time_spent;

begin = clock();
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    return (time_spent);
}

int main(){

	double tempo;
	int dados[TAM1];
	lerArquivo(dados);

	int i;


	// É so passar o vetor DADOS como argumento para a sua função de ordenação
	// EXEMPLO
	tempo = radixsort(dados,TAM1);

		for (i = 0; i < TAM1; ++i){
		printf("%d\n", dados[i] );
	}

	return 0;
}
