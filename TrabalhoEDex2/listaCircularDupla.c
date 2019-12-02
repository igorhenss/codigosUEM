#include <stdio.h>
#include <stdlib.h>
#include "listaCircularDupla.h"


struct listaCircularDupla{
    int valor
    struct listaCircularDupla *pred;
    struct listaCircularDupla *prox;
};

listaCircularDupla *criar(){
	return NULL;
}

listaCircularDupla *alocar(int valor){
	listaCircularDupla *novo = (listaCircularDupla *) malloc (sizeof(listaCircularDupla));
	if(novo == NULL){
		printf("Erro na reserva de memoria");
	}
	else{
        novo->valor = valor;
		novo->pred = novo;
		novo->prox = novo;
	}
	return novo;
}

listaCircularDupla *inserirFim(listaCircularDupla* L, int valor){
	listaCircularDupla *novo, *aux;
	novo = alocar(valor);
  aux = L;
}

listaCircularDupla *buscar(listaCircularDupla *L, int dado){
	listaCircularDupla *aux = L;
	while (aux != NULL){
		if (aux->valor == dado){
			return aux;
		}
		else{
			aux = aux->proximo;
		}
	}
	return aux;
}

void mostrar(listaCircularDupla *L){
	listaCircularDupla *aux;
	aux = L;
	if (aux == NULL){
		printf("Lista vazia!");
	}
	else{
		while (aux != NULL){
            printf("\n__________________________");
			printf("\n%i", aux->valor);
            printf("\n__________________________");
            aux = aux->proximo;
		}
	}
}

listaCircularDupla *excluir(listaCircularDupla *L, int valor){
 	listaCircularDupla *excluir;
	excluir = buscar(L, valor);
	if(excluir != NULL){
		if (excluir == L){ 	//se for excluir o primeiro
			if (excluir->pred == excluir->prox){
                free(excluir);
                L=NULL;
                return L;
			}
			L=excluir->prox;
		}

		if(excluir == L->pred){
            L->pred = excluir->pred;
            excluir->pred->prox = excluir->prox;
            excluir->prox->pred = excluir->pred;
            free(excluir);
		}

	}else{
		printf("\nElemento nao encontrado");
	}
	return L;
 }
