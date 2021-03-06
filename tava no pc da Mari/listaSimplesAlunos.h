#ifndef LISTASIMPLESALUNOS_H_INCLUDED
#define LISTASIMPLESALUNOS_H_INCLUDED

typedef struct listaSimplesAlunos Alunos;
//funcoes exportadas
Alunos* criar();
Alunos* inserirFim(Alunos *L, char nome[50] , int ra, float n1, float n2);
Alunos* inserirInicio(Alunos *L, char nome[50] , int ra, float n1, float n2);
float calcularMedia(float n1, float n2);
Alunos* buscarMaiorMedia(Alunos *L);
Alunos* alterarDados(Alunos *L);
Alunos* excluir(Alunos* L, int ra);
void mostrar(Alunos *L);
void mostrarAprovados(Alunos *L);
void mostrarReprovados(Alunos *L);
void liberar(Alunos *L);

#endif // LISTASIMPLESALUNOS_H_INCLUDED
