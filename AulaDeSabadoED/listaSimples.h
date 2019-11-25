#ifndef LISTASIMPLES_H_INCLUDED
#define LISTASIMPLES_H_INCLUDED

//tipo exportado
typedef struct tipo_lista listaSimples;

//funcoes exportadas
listaSimples* criar();
void liberar(listaSimples *L);
listaSimples* inserir_fim(listaSimples* L, int valor);
listaSimples* inserir_inicio(listaSimples* L, int valor);
listaSimples* buscar(listaSimples* L, int valor);
listaSimples* excluir(listaSimples* L, int valor);
void mostrar(listaSimples* L);
int pares(listaSimples *L);
listaSimples *inverteLista(listaSimples *L);
listaSimples *concatenaListas(listaSimples *L1, listaSimples *L2);

#endif // LISTASIMPLES_H_INCLUDED
