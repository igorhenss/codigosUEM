#include "Lista_Estatica.h"
#include <stdio.h>
#include <stdlib.h>
int const TAM = 5;
int menu()
{
    int opcao;
    printf("\nOpcoes:");
    printf("\n0. Sair");
    printf("\n1. Inserir um numero no inicio da lista");
    printf("\n2. Mostrar a lista");
    printf("\n3. Inserir valor no fim da lista");
    printf("\n4. Buscar elemento na lista");
    printf("\n5. Excluir elemento da lista");
    printf("\nInforme a opcao: ");
    scanf("%d", &opcao);
    return opcao;
}
int main()
{
    int opcao, elemento;
    lista *L;
    L = criar(TAM);
    inicializar(L);
    do{
        opcao = menu();
        switch (opcao)
        {
        case 1:
            printf("\nInforme o valor: ");
            scanf("%d", &elemento);
            inserir_inicio (L, elemento);
            break;
        case 2:
            printf("\nValores armazenados no vetor:\n");
            mostrar(L);
            break;
        case 3:
            printf("\nInforme o valor: ");
            scanf("%d", &elemento);
            inserir_fim(L, elemento);
            break;
        case 4:
            printf("\nInforme o valor: ");
            scanf("%d", &elemento);
            buscar(L, elemento);
            break;
        case 5:
            printf("\nInforme o valor: ");
            scanf("%d", &elemento);
            excluir(L, elemento);
            break;
        }
    }
    while(opcao);
    liberar(L);
    return 0;
}
