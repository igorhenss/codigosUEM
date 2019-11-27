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
            printf("\nMedia: %f", aux->media);
            printf("\n__________________________");
            aux = aux->prox;
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
                printf("\nMedia: %f", aux->media);
                printf("\n__________________________");
            }
            aux = aux->prox;
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
                printf("\nMedia: %f", aux->media);
                printf("\n__________________________");
            }
            aux = aux->prox;
		}
	}
}

//MÉTODOS COM RETORNO TIPO listaSimplesAlunos

listaSimplesAlunos *criar(){
	return NULL;
}

listaSimplesAlunos *alocar(char[50] nome, int ra, float n1, float n2, float media){
	listaSimplesAlunos *novo = (listaSimplesAlunos *) malloc (sizeof(listaSimplesAlunos));
	if(novo == NULL){
		printf("Erro na reserva de memoria");
	}else{
		novo->nome = nome;
		novo->ra = ra;
		novo->nota1 = n1;
		novo->nota2 = n2;
		novo->media = calcularMedia(n1, n2);
		novo->prox = NULL;
	}
	return novo;
}

listaSimplesAlunos *inserirFim(listaSimplesAlunos* L, char[50] nome, int ra, float n1, float n2, float media){
	listaSimplesAlunos *novo, *aux = L;
	novo = alocar(nome, ra, n1, n2, media);
	if (aux == NULL){ // Confere se L ainda está vazia
		aux = novo;
    novo->prox = NULL;
	}else{ // Se L não estiver vazia
		while (aux->prox != NULL){ //rodadno a lista até achar o último
			aux = aux->prox;
		}
		aux->prox = novo;
    novo->prox = NULL;
	}
	return aux;
}

listaSimplesAlunos *inserirInicio(listaSimplesAlunos* L, char[50] nome, int ra, float n1, float n2, float media){
  listaSimplesAlunos *novo = alocar(nome, ra, n1, n2, media);
  if(aux==NULL){
  	aux = novo;
  }else{
    novo->prox = aux->prox;
    aux = novo;
  }
	return aux;
}

listaSimplesAlunos *buscar(listaSimplesAlunos *L, int dado){
	listaSimplesAlunos *aux = L;
	while (aux != NULL){
		if (aux->info == dado){
			return aux;
		}
		else{
			aux = aux->prox;
		}
	}
	return aux;
}

listaSimplesAlunos *buscarMaiorMedia(listaSimplesAlunos *L){
	listaSimplesAlunos *maiorMedia, *aux = L;
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

listaSimplesAlunos *alterarDados(listaSimplesAlunos *L){
  listaSimplesAlunos *aux = L;
  int ra;
  printf("Informe o RA do aluno: ");
  scanf(" %i", &ra);
  while(aux!=NULL){
    if(aux->ra){
      int op = menuAtualiza();
      switch (op) {
        case 1:
          printf("Informe o nome:");
          gets(aux->nome);
          printf("Pronto! O novo nome é: %s", aux->nome);
        break;
        case 2:
          printf("Informe a nota 1:");
          scanf(aux->n1);
          aux->media = calcularMedia(aux->n1, aux->n2);
          printf("Pronto! A nova nota é %f e a nova média é %f", aux->n1, aux->media);
        break;
        case 3:
          printf("Informe a nota 2:");
          scanf(aux->n2);
          aux->media = calcularMedia(aux->n1, aux->n2);
          printf("Pronto! A nova nota é %f e a nova média é %f", aux->n2, aux->media);
        break;
        default:
          printf("A opção é inválida");
        break;
      }
    }
  }
}

listaSimplesAlunos *excluir(listaSimplesAlunos *L, int ra){
 	listaSimplesAlunos *excluir, *aux = L;
	excluir = buscar(aux, ra);
	if(excluir != NULL){
		if (aux == excluir){ 	//se for excluir o primeiro
			aux = excluir->prox;
		}
		else{
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
