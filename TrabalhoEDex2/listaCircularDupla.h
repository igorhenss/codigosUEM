#ifndef LISTACIRCULARDUPLA_H_INCLUDED
#define LISTACIRCULARDUPLA_H_INCLUDED

typedef struct listaCircularDupla Lista;

//funcoes exportadas
Alunos* criar();
Lista* inserirFim(Lista *L, int valor);
Lista* inserirInicio(Lista *L, int valor);
Lista* buscar(Lista *L, int valor);
void mostrar(Lista *L);
Lista* excluir(Lista* L, int valor);


#endif // LISTACIRCULARDUPLA_H_INCLUDED
