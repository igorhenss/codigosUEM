#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

//tipo exportado
typedef struct listaSimples fila;

//funcoes exportadas
fila* criar();
fila* enfileirar(fila *F, int valor);
fila* desenfileirar(fila *F);
fila* excluir(fila *F, int valor);
void mostrar(fila *F);

#endif // FILAS_H_INCLUDED
