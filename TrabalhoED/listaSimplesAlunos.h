#ifndef LISTASIMPLESALUNOS_H
#define LISTASIMPLESALUNOS_H

typedef struct listaSimplesAlunos Alunos;

void liberar(Alunos *L);
Alunos* criar();
Alunos* inserirFim(Alunos *L, char nome[50] , int ra, float n1, float n2);
Alunos* inserirInicio(Alunos *L, char nome[50] , int ra, float n1, float n2);
Alunos* buscarMaiorMedia(Alunos *L);
void mostraAluno(Alunos *aluno);
void alterarDados(Alunos *L, int raAlterar);
void mostrar(Alunos *L);
void mostrarAprovados(Alunos *L);
void mostrarReprovados(Alunos *L);
Alunos* excluir(Alunos* L, int ra);


#endif // LISTASIMPLESALUNOS_H_INCLUDED
