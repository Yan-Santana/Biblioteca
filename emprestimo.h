typedef struct emprestimo {
  int id_Livro;
  char titulo[100];
  char autor[50];
  unsigned long int RGA;
  struct emprestimo *prox;  
} Emprestimo;