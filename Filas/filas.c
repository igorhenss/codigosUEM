#include<stdio.h>
#include "filas.h"

struct listaSimples{
  int valor;
  struct listaSimples *prox;
}

fila *criar(){
  return NULL;
}

fila *alocar(int valor){
  fila *novo = (fila *) malloc (sizeof(fila));
  if(novo == NULL){
    printf("Erro na reserva de memoria");
  }else{
    novo->valor = valor;
    novo->prox = NULL;
  }
  return novo;
}

fila *enfileirar(fila* , int valor){ //enfileirar
  fila *aux, *novo;
  novo = alocar(valor);
  aux = F;
  if (aux == NULL){ // Confere se L ainda está vazia
    aux = novo;
    novo->prox = NULL;
  }else{ // Se L não estiver vazia
    while (aux->prox != NULL){ //roda a fila até achar o último
      aux = aux->prox;
    }
    aux->prox = novo;
  }
  return aux;
}

fila *desenfileirar(fila *F){
  fila *excluir, *aux;
  excluir = F;
  aux = F;
  if(aux != NULL){
    printf("O elemento %i foi removido!", aux->valor);
    aux = excluir->prox;
    free(excluir); // OU delete excluir; //(em C++)
  }else{
    printf("\nFila já está vazia");
  }
  return F;
}

void liberar(fila *F){
	fila *excluir;
	while(F != NULL){
	 	excluir = F;
		F = F->prox;
		free(excluir);
	}
	free(F);
}

void *mostrar(fila *F){
  fila *aux = F;
  if (aux == NULL){
    printf("Fila vazia!");
  }else{
    while (aux != NULL){
      printf("\nValor: %i", aux->valor);
      aux = aux->prox;
    }
  }
}
