#include "listaSimples.h"
#include <stdio.h>
#include <stdlib.h>

struct tipo_lista{
	int dado;
	struct tipo_lista *proximo;
};

listaSimples *criar(){
	return NULL;
}

void liberar(listaSimples* L){
	listaSimples *excluir;
	while(L != NULL){
	 	excluir = L;
		L = L->proximo;
		free(excluir);
	}
	free(L);
}

listaSimples *alocar(int dado){
	listaSimples *novo = (listaSimples *) malloc (sizeof(listaSimples));
	if(novo == NULL){
		printf("Erro na reserva de memoria");
	}
	else{
		novo->info = dado;
		novo->proximo = NULL;
	}
	return novo;
}

listaSimples* inserir_fim(listaSimples* L, int elemento){
	listaSimples *aux, *novo;
	aux = L;
	novo = alocar(elemento);
	if (aux == NULL){
		L = novo;
	}
	else{
		while (aux->proximo != NULL){
			aux = aux->proximo;
		}
		aux->proximo = novo;
	}
	return L;
}

listaSimples* inserir_inicio(listaSimples* L, int elemento){
	listaSimples *novo = alocar(elemento);
	novo->proximo = L;
	L = novo;
}

listaSimples *buscar(listaSimples *L, int dado){
	listaSimples *aux = L;
	while (aux != NULL){
		if (aux->info == dado){
			return aux;
		}
		else{
			aux = aux->proximo;
		}
	}
	return aux;
}

listaSimples *excluir(lista *L, int dado){
 	listaSimples *excluir;
	listaSimples *aux = L;
	excluir = buscar(L, dado);
	if(excluir != NULL){
		if (aux == excluir){ 	//se for excluir o primeiro
			L = excluir->proximo;
		}
		else{
			while(aux->proximo!= excluir) {
				aux = aux->proximo;
			}
			aux->proximo = excluir->proximo;
		}
		free(excluir); // OU delete excluir; //(em C++)
	}
	else{
		printf("\nElemento nao encontrado");
	}
	return L;
 }

void mostrar(listaSimples* L){
	listaSimples *aux;
	aux = L;
	if (aux == NULL){
		printf("lista vazia!");
	}
	else{
		while (aux != NULL){
			printf("%d ", aux->info);
			aux = aux->proximo;
		}
	}
}

int pares (listaSimples *L){
    listaSimples *aux = L;
    int qtdPares = 0;
    while(aux!=NULL){
        if(aux->dado % 2 == 0){
            qtPares +=1;
        }
        aux = aux->prox;
    }
    return qtPares;
}

listaSimples *inverteLista(listaSimples *L){
    listaSimples *Linvertido, *aux = L;
    while(aux->prox!=NULL){
        Linvertido = inserir_inicio(Linvertido, aux->dado);
        aux = aux->prox;
    }
    liberar(L);
    return Linvertido;
}

listaSimples *concatenaListas(listaSimples *L1, listaSimples *L2){
    listaSimples *aux1, *aux2, *novaLista = NULL;
    aux1 = L1;
    aux2 = L2;
    novaLista = criar();
    while(aux1->prox !=NULL){
        novaLista = inserir_fim(novaLista, aux1->dado);
        while(aux2->prox!=NULL){
            novaLista = inserir_fim(novaLista, aux2->dado);
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return novaLista;
}


