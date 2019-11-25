#include "listaSimples.h"
#include <stdio.h>
#include <stdlib.h>


int menu(){
	int opcao;
	printf("\nOpcoes:");
	printf("\n0. Sair");
	printf("\n1. Inserir um numero no fim da lista");
	printf("\n2. Inserir um numero no inicio da lista");
	printf("\n3. Mostrar a lista");
	printf("\n4. Excluir um elemento da lista");
	printf("\n5. Descobrir quantidade de numeros pares da lista");
	printf("\n6. Inverter a lista");
	printf("\n7. Concatenar duas listas");
	printf("\nInforme a opcao: ");
	scanf("%d", &opcao);
	return opcao;
}
int main() {
	int opcao, elemento, qtpares;
	listaSimples *L, *L2, *novaL;
	L = criar();
	L2 = criar();
	do{
		opcao = menu();
		switch (opcao){
			case 1:	printf("\nInforme o valor: ");
					scanf("%d", &elemento);
					L = inserir_fim (L, elemento);
					break;
			case 2:	printf("\nInforme o valor: ");
					scanf("%d", &elemento);
					L = inserir_inicio (L, elemento);
					break;
			case 3:	printf("\nValores armazenados no vetor:\n");
					mostrar(L);
					break;
			case 4:	printf("\nInforme o valor a ser excluido:\n");
					scanf("%d", &elemento);
					L = excluir(L, elemento);
					break;
            case 5: qtpares = pares(L);
                    printf("A quantidade de pares é: %i", qtpares);
            case 6: L = inverteLista(L);
            case 7: novaL = concatenaListas(L, L2);
		}
	}while(opcao);
	liberar(L);
	return 0;
}
