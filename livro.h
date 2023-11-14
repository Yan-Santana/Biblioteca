typedef struct livro {
  int id;
  char titulo[100]; 
  char autor[50];
  int ano;
  int total_Exemplares;
  int Exemplares_Disponiveis;
  struct livro *prox;
} Livro;