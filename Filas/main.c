#include <stdio.h>
#include "filas.h"

int menu(){
    int opcao;
    printf("\nOpcoes:");
    printf("\n0. Sair");
    printf("\n1. Inserir");
    printf("\n2. Excluir um elemento");
    printf("\n3. Mostrar");
    printf("\nInforme a opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(int argc, char const *argv[]) {
  fila *F;
  int valor;
  F = criar();
  do{
      opcao = menu();
      switch (opcao){
        case 1:
            printf("\nInforme o valor: ");
            scanf("%i", &valor);
            F = inserir(F, valor);
            break;
        case 2:
            F = excluir(F);
            break;
        case 3:
            printf("Sua fila está assim: ");
            mostrar(F);
            break;
      }
  }while(opcao);
  liberar(F);
  return 0;
}
