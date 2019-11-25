#include <stdio.h>
#include <stdlib.h>
#include "listaSimplesAlunos.h"

struct listaSimplesAlunos{
    char[50] nome;
    int ra;
    float nota1;
    float nota2;
    float media;
    listaSimplesAlunos *prox;
};

listaSimplesAlunos *criar(){
	return NULL;
}

listaSimplesAlunos *alocar(char[50] nome, int ra, float n1, float n2){
	listaSimplesAlunos *novo = (listaSimplesAlunos *) malloc (sizeof(listaSimplesAlunos));
	if(novo == NULL){
		printf("Erro na reserva de memoria");
	}
	else{
		novo->nome = nome;
		novo->ra = ra;
		novo->nota1 = n1;
		novo->nota2 = n2;
		novo->media = 0.0;
		novo->prox = NULL;
	}
	return novo;
}

listaSimplesAlunos *inserirFim(listaSimplesAlunos* L, char[50] nome, int ra, float n1, float n2){
	listaSimplesAlunos *aux, *novo;
	aux = L;
	novo = alocar(nome, ra, n1, n2);
	if (aux == NULL){
		L = novo;
	}
	else{
		while (aux->proximo != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
	return L;
}

listaSimplesAlunos *inserirInicio(listaSimplesAlunos* L, char[50] nome, int ra, float n1, float n2){
	listaSimplesAlunos *novo = alocar(nome, ra, n1, n2);
	novo->proximo = L;
	L = novo;
}

listaSimplesAlunos *buscar(listaSimplesAlunos *L, int dado){ //FAZER ALTERAÇÕES
	listaSimplesAlunos *aux = L;
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

listaSimplesAlunos *calcularMedia(listaSimplesAlunos *L){
    //rodar toda a lista para calcular a média de cada aluno
}

listaSimplesAlunos *buscarMaiorMedia(listaSimplesAlunos *L){ //FAZER ALTERAÇÕES
	listaSimplesAlunos *aux = L;
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

listaSimplesAlunos *alterarDados(listaSimplesAlunos *L){
    //criar código de alteração, menos média
}

void mostrar(listaSimplesAlunos *L){
	listaSimplesAlunos *aux;
	aux = L;
	if (aux == NULL){
		printf("Lista vazia!");
	}
	else{
		while (aux != NULL){
            printf("\n__________________________");
			printf("\nNome do aluno: %s", aux->nome);
            printf("\nRa: %i", aux->ra);
            printf("\nNota 1: %f", aux->nota1);
            printf("\nNota 2: %f", aux->nota2);
            printf("\nMédia: %f", aux->media);
            printf("\n__________________________");
            aux = aux->proximo;
		}
	}
}

void mostrarAprovados(listaSimplesAlunos *L){
    listaSimplesAlunos *aux;
	aux = L;
	if (aux == NULL){
		printf("Lista vazia!");
	}
	else{
		while (aux != NULL){
            if(aux->media>=6.0){
                printf("\n__________________________");
                printf("\nNome do aluno: %s", aux->nome);
                printf("\nRa: %i", aux->ra);
                printf("\nNota 1: %f", aux->nota1);
                printf("\nNota 2: %f", aux->nota2);
                printf("\nMédia: %f", aux->media);
                printf("\n__________________________");
            }
            aux = aux->proximo;
		}
	}
}

void mostrarReprovados(listaSimplesAlunos *L){
    listaSimplesAlunos *aux;
	aux = L;
	if (aux == NULL){
		printf("Lista vazia!");
	}
	else{
		while (aux != NULL){
            if(aux->media<6.0){
                printf("\n__________________________");
                printf("\nNome do aluno: %s", aux->nome);
                printf("\nRa: %i", aux->ra);
                printf("\nNota 1: %f", aux->nota1);
                printf("\nNota 2: %f", aux->nota2);
                printf("\nMédia: %f", aux->media);
                printf("\n__________________________");
            }
            aux = aux->proximo;
		}
	}
}

listaSimplesAlunos *excluir(listaSimplesAlunos *L, int ra){
 	listaSimplesAlunos *excluir;
	listaSimplesAlunos *aux = L;
	excluir = buscar(L, ra);
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



