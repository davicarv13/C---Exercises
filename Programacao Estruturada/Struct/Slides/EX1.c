#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 2

typedef struct{
	char nome[50];
	int numeroConta;
	float saldo;
}Conta;

void lp();
void preencheClientes(Conta *clientes);
int saldoAcima1000(Conta *clientes);

int main(){
	Conta *clientes=malloc(TAM*sizeof(Conta));

	setlocale(LC_ALL, "Portuguese");

	preencheClientes(clientes);
	
	printf("Quantidade de funcionários com salário:%d \n", saldoAcima1000(clientes));
}

void lp(){
	system("clear || cls");
}

void preencheClientes(Conta *clientes){
	int i;

	lp();

	for(i=0; i<TAM; i++){
		printf("Informe o nome:");
		scanf("%[^\n]s", clientes[i].nome);
		getchar();

		printf("Informe o número da conta:");
		scanf("%d", &clientes[i].numeroConta);
		getchar();

		printf("Informe o saldo:");
		scanf("%f", &clientes[i].saldo);
		getchar();

		lp();
	}
}

int saldoAcima1000(Conta *clientes){
	int i, cont=0;

	lp();

	for(i=0; i<TAM; i++){
		if(clientes[i].saldo>1000){
			cont++;
		}
	}
	return cont;
}
