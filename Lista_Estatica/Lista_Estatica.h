#ifndef LISTA_ESTATICA_H_INCLUDED
#define LISTA_ESTATICA_H_INCLUDED

//tipo exportado
typedef struct tipo_lista lista;
//funcoes exportadas
lista* criar(int tam);
void liberar(lista* L); //libera a memoria ocupada pela lista
void inicializar(lista* L);
void inserir_inicio(lista* L, int valor);
void mostrar(lista* L);
void inserir_fim(lista* L, int valor);

#endif // LISTA_ESTATICA_H_INCLUDED
