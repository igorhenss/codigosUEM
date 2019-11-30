#include "Lista_Estatica.h"
#include <stdio.h>
#include <stdlib.h>
struct tipo_lista
{
    int tamanho;
    int index; //indica próxima posicao disponível no final da lista
    int *vetor;
};

lista* criar (int tam)
{
    lista *temp = (lista*) malloc(sizeof(lista));
    temp -> vetor = (int*) malloc(tam*sizeof(int));
    temp -> tamanho = tam;
    temp -> index = 0;
    return temp;
}

void liberar(lista* L)
{
    free(L->vetor);
    free(L);
}

void inicializar(lista* L)
{
    int i;
    for (i=0; i<L->tamanho; i++)
    {
        L->vetor[i] = 0;
    }
}

int lista_cheia(lista* L)
{
    if (L->index == L->tamanho)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inserir_inicio(lista* L, int valor)
{
    int i;
    if(!lista_cheia(L))
    {
        for(i=L->index; i>0; i--)
        {
            L->vetor[i] = L->vetor[i-1];
        }
        L->vetor[0] = valor;
        L->index++;
    }
    else
    {
        printf("Lista cheia!");
    }
}

void inserir_fim(lista *L, int valor)
{
    if (!lista_cheia(L))
    {
        L->vetor[L->index] = valor;
        L->index++;
    }
    else
    {
        printf("A lista está cheia");
    }
}

void mostrar(lista* L)
{
    int i;
    for(i=0; i<L->tamanho; i++)
    {
        printf("%d ", L->vetor[i]);
    }
}

int buscar(lista *L, int valor)
{
    int i = -1;
    for(i=0; i<L->tamanho; i++)
    {
        if(L->vetor[i] == valor)
        {
            break; //se achar retorna a posição
        }
    }
    return i;
}

void excluir(lista *L, int valor){
    int i, j;
    i = buscar(L, valor);
    if(i!=-1){ //Se elemento no começo
        for(j=i; j<L->index; j++){  //Puxa os que vem depois
            L->vetor[j] = L->vetor[j+1];
        }
        L->index--;
    }else{
        printf("Não é possivel excluir pois esse elemento não está na lista");
    }
}
