#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

// gcc -Wall -Wextra -g3 main.c biblioteca.c -o main.exe  -> compilar no terminal

int main() {
  char op;
  int id, ano, total_Exemplares;
  unsigned long int rga;
  char titulo[100], autor[50];

  do {
    menu();
    printf("\nDigite a opcao: ");
    scanf(" %c", &op);

    switch (op) {

    case 'A':
    printf("Informe os dados do livro (ID / Titulo / Autor / ano / Total de exemplares): ");

    scanf("%d", &id);
    scanf(" \"%99[^\"]\"s", titulo);
    scanf(" \"%49[^\"]\"s", autor);
    scanf("%d", &ano);
    scanf("%d", &total_Exemplares);
  
    add_livro(id, titulo, autor, ano, total_Exemplares);
    break;

    case 'R':
        printf("Informe o ID do livro: ");
        scanf("%d", &id);

        remover_Livro(id);
        break;

    case 'P':
        lista_Livros();
        break;

    case 'E':
        printf("Informe o ID do livro: ");
        scanf("%d", &id);

        printf("Informe o RGA do aluno: ");
        scanf("%ld", &rga);

        emprestimo_exemplar(id, rga);
        break;

    case 'D':
        printf("Informe o ID do livro que deseja devolver: ");
        scanf("%d", &id);

        devolve_livro(id);
        break;

    case 'I':
        lista_emprestimos();
        break;

    default:
        printf("Comando invalido. Tente novamente.\n\n");
        break;
    }
  } while (op != 'S');

  printf("\n\n PROGRAMA ENCERRADO!\n\n");
  encerra();

  return 0;
}
