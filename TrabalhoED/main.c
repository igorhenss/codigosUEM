#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimplesAlunos.h"

int menu(){
    int opcao;
    printf("\nOpcoes:");
    printf("\n0. Sair");
    printf("\n1. Inserir no Inicio: ");
    printf("\n2. Inserir no Fim: ");
    printf("\n3. Buscar aluno com maior media");
    printf("\n4. Alterar Dados");
    printf("\n5. Mostrar");
    printf("\n6. Mostrar Aprovados");
    printf("\n7. Mostrar Reprovados");
    printf("\n8. Excluir");
    printf("\nInforme a opcao: ");
    scanf("%d", &opcao);
    return opcao;
    }

int main(){
    int opcao, ra;
    float n1, n2;
    char nome[50];
    Alunos *L, *aluno;
    L = criar();
    do{
        opcao = menu();
        switch (opcao)
        {
        case 1:
            printf("\nInsira o nome do aluno: ");
            scanf("%[^\n]s", nome);
            printf("\nInsira o RA do aluno: ");
            scanf("%d",&ra);
            printf("\nInsira a nota 1: ");
            scanf("%f", &n1);
            printf("\nInsira a nota 2: ");
            scanf("%f", &n2);
            L = inserirInicio(L, nome , ra, n1, n2);
            break;
        case 2:
            printf("\nInsira o nome do aluno: ");
            scanf("%[^\n]s", nome);
            printf("\nInsira o RA do aluno: ");
            scanf("%d",&ra);
            printf("\nInsira a nota 1: ");
            scanf("%f", &n1);
            printf("\nInsira a nota 2: ");
            scanf("%f", &n2);
            L = inserirFim(L, nome , ra, n1, n2);
            break;
        case 3:
            printf("Aluno com maior media: ");
            aluno = buscarMaiorMedia(L);
            mostraAluno(aluno);
            /*printf("\nNome do aluno: %s", aluno->nome);
            printf("\nRa: %i", aluno->ra);
            printf("\nNota 1: %f", aluno->nota1);
            printf("\nNota 2: %f", aluno->nota2);
            printf("\nMedia: %f", aluno->media);*/
            break;
        case 4:
            printf("\nInforme o RA do aluno: ");
            scanf("%i", &ra);
            alterarDados(L, ra);
            break;
        case 5:
            printf("\nAlunos: ");
            mostrar(L);
            break;
        case 6:
            printf("\nAlunos aprovados:\n");
            mostrarAprovados(L);
            break;
        case 7:
            printf("\nAlunos reprovados:\n");
            mostrarReprovados(L);
            break;
        case 8:
            printf("\nInsira o RA do aluno que deseja excluir: ");
            scanf("%d",&ra);
            L = excluir(L, ra);
            break;
        default:
              printf("\nOpção inválida, tente novamente.");
              break;
        }
    } while(opcao);
    liberar(L);
    return 0;
}
