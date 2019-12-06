#include <stdio.h>
#include <stdlib.h>
#include "listaSimplesAlunos.h"

struct listaSimplesAlunos{
    char nome[50] ;
    int ra;
    float nota1;
    float nota2;
    float media;
    struct listaSimplesAlunos *prox;
};

//MÉTODOS COM RETORNO TIPOS BÁSICOS DE DADOS
int menuAtualiza(){
  int op;
  printf("O que deseja editar?");
  printf("\n1-Nome do aluno");
  printf("\n2-Nota 1");
  printf("\n3-Nota 2");
  scanf(" %i", &op);
  return op;
}

float calcularMedia(float n1, float n2){
    return (n1+n2)/2;
}

void mostrar(Alunos *L){
	Alunos *aux;
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
            printf("\nMedia: %f", aux->media);
            printf("\n__________________________");
            aux = aux->prox;
		}
	}
}

void mostrarAprovados(Alunos *L){
  Alunos *aux;
	aux = L;
	if (aux == NULL){
		printf("Lista vazia!");
	}
	else{
    printf("\nLista dos reprovados:");
		while (aux != NULL){
            if(aux->media>=6.0){
                printf("\n__________________________");
                printf("\nNome do aluno: %s", aux->nome);
                printf("\nRa: %i", aux->ra);
                printf("\nNota 1: %f", aux->nota1);
                printf("\nNota 2: %f", aux->nota2);
                printf("\nMedia: %f", aux->media);
                printf("\n__________________________");
            }
            aux = aux->prox;
		}
	}
}

void mostrarReprovados(Alunos *L){
  Alunos *aux;
	aux = L;
	if (aux == NULL){
		printf("Lista vazia!");
	}
	else{
    printf("\nLista dos reprovados:");
		while (aux != NULL){
            if(aux->media<6.0){
                printf("\n__________________________");
                printf("\nNome do aluno: %s", aux->nome);
                printf("\nRa: %i", aux->ra);
                printf("\nNota 1: %f", aux->nota1);
                printf("\nNota 2: %f", aux->nota2);
                printf("\nMedia: %f", aux->media);
                printf("\n__________________________");
            }
            aux = aux->prox;
		}
	}
}

void liberar(Alunos *L){
	Alunos *excluir;
	while(L != NULL){
	 	excluir = L;
		L = L->prox;
		free(excluir);
	}
	free(L);
}

//MÉTODOS COM RETORNO TIPO Alunos



Alunos *criar(){
	return NULL;
}

Alunos *alocar(char nome[50] , int ra, float n1, float n2){
	Alunos *novo = (Alunos *) malloc (sizeof(Alunos));
	if(novo == NULL){
		printf("Erro na reserva de memoria");
	}else{
		novo->nome[50] = nome;
		novo->ra = ra;
		novo->nota1 = n1;
		novo->nota2 = n2;
		novo->media = calcularMedia(n1, n2);
		novo->prox = NULL;
	}
	return novo;
}

Alunos *inserirInicio(Alunos* L, char nome[50] , int ra, float n1, float n2){
  Alunos *aux, *novo;
  novo = alocar(nome, ra, n1, n2);
  aux = L;
  if(aux == NULL){
  	aux = novo;
  }else{
    novo->prox = aux;
    aux = novo;
  }
	return aux;
}

Alunos *inserirFim(Alunos* L, char nome[50] , int ra, float n1, float n2){
	Alunos *aux, *novo;
	novo = alocar(nome, ra, n1, n2);
  aux = L;
	if (aux == NULL){ // Confere se L ainda está vazia
		aux = novo;
	}else{ // Se L não estiver vazia
		while (aux->prox != NULL){ //roda a lista até achar o último
			aux = aux->prox;
		}
		aux->prox = novo;
	}
	return L;
}

Alunos *buscar(Alunos *L, int raBusca){
	Alunos *aux = L;
	while (aux != NULL){
		if (aux->ra == raBusca){
			return aux;
		}
		else{
			aux = aux->prox;
		}
	}
	return L;
}

Alunos *buscarMaiorMedia(Alunos *L){
	Alunos *maiorMedia, *aux = L;
	maiorMedia->media = 0.0;
	if(aux==NULL){
        printf("A lista está vazia");
        return NULL;
	}else{
        while (aux != NULL){
            if (aux->media > maiorMedia->media){
                maiorMedia = aux;
            }
            else{
                aux = aux->prox;
            }
        }
	}
  return maiorMedia;
}

Alunos *alterarDados(Alunos *L){
  Alunos *alunoPraMudar, *aux = L;
  int raAlterar;
  printf("Informe o RA do aluno: ");
  scanf(" %i", &raAlterar);
  alunoPraMudar = buscar(aux, raAlterar);
  if(alunoPraMudar!=NULL){
    int op = menuAtualiza();
    switch (op) {
      case 1:
        printf("Informe o nome:");
        gets(aux->nome);
        printf("Pronto! O novo nome eh: %s", aux->nome);
        break;
      case 2:
        printf("Informe a nota 1:");
        scanf(aux->n1);
        aux->media = calcularMedia(aux->nota1, aux->nota2);
        printf("Pronto! A nova nota eh %f e a nova media eh %f", aux->nota1, aux->media);
        break;
      case 3:
        printf("Informe a nota 2:");
        scanf(aux->nota2);
        aux->media = calcularMedia(aux->nota1, aux->nota2);
        printf("Pronto! A nova nota eh %f e a nova media eh %f", aux->nota2, aux->media);
        break;
      default:
        printf("A opção eh invalida");
        break;
    }
  }
}

Alunos *excluir(Alunos *L, int ra){
 	Alunos *excluir, *aux = L;
	excluir = buscar(aux, ra);
	if(excluir != NULL){
		if (aux == excluir){ 	//se for excluir o primeiro
			aux = excluir->prox;
		}else{
			while(aux->prox!= excluir) {
				aux = aux->prox;
			}
			aux->prox = excluir->prox;
		}
		free(excluir); // OU delete excluir; //(em C++)
	}
	else{
		printf("\nElemento nao encontrado");
	}
	return L;
 }
