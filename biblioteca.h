#include "livro.h"
#include "emprestimo.h"

extern Livro *acervo;
extern Emprestimo *emprestimos;

void menu();
void add_livro(int id, char titulo[], char autor[], int ano, int totalExemplares);
void remover_Livro(int id);
void lista_Livros();
void emprestimo_exemplar(int id_Livro, unsigned long int rga_Aluno);
void devolve_livro(int id_Livro);
void lista_emprestimos();
void encerra();