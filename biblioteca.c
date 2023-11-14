#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "biblioteca.h"

Livro *acervo = NULL;
Emprestimo *emprestimos = NULL;

void menu() {
  printf("\n\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("|                                   ESCOLHA UMA OPCAO:                                  |\n");
  printf("|              A. Adicionar um livro a biblioteca                                       |\n");
  printf("|              R. Remover um exemplar de livro da biblioteca.                           |\n");
  printf("|              P. Imprimir a lista de livros na biblioteca.                             |\n");
  printf("|              E. Emprestimo de um exemplar de livro da biblioteca                      |\n");
  printf("|              D: Devolucao de um exemplar de livro a biblioteca.                       |\n");
  printf("|              I: Imprimir a lista de livros da biblioteca que estao emprestados.       |\n");
  printf("|              S: Sair do programa.                                                     |\n");
  printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void add_livro(int id, char titulo[], char autor[], int ano, int totalExemplares) {
  Livro *novo = (Livro *)malloc(sizeof(Livro));
  novo->id = id;

  strcpy(novo->titulo, titulo);
  strcpy(novo->autor, autor);

  novo->ano = ano;
  novo->total_Exemplares = totalExemplares;
  novo->Exemplares_Disponiveis = totalExemplares;
  novo->prox = acervo;
  acervo = novo;

  printf("\n------- LIVRO ADICIONADO COM SUCESSO! -------\n");
}

void remover_Livro(int id) {
  Livro *atual = acervo;
  Livro *anterior = NULL;

  if (atual != NULL && atual->id == id) {
    acervo = atual->prox;
    free(atual);
    printf("\n------- LIVRO REMOVIDO COM SUCESSO! -------\n");
    return;
  }

  while (atual != NULL && atual->id != id) {
    anterior = atual;
    atual = atual->prox;
  }

  if (atual == NULL) {
    printf("\n------- LIVRO NAO ENCONTRADO! -------\n");
    return;
  }

  anterior->prox = atual->prox;
  free(atual);
  printf("\n------- LIVRO REMOVIDO COM SUCESSO! -------\n");
}

void lista_Livros() {
  Livro *aux = acervo;

  if(aux == NULL) {
    printf("MEU DEUS!!\nA biblioteca esta vazia!\n\n");
  } else {
        printf("------- LISTA DE LIVROS NA BIBLIOTECA -------\n");
        while (aux != NULL) {
            printf("ID: %d | %s | %s | %d | %d exemplar(es) disponivel(is)\n", aux->id, aux->titulo, aux->autor, aux->ano, aux->Exemplares_Disponiveis);
            aux = aux->prox;
        }
  }
}

void emprestimo_exemplar(int id_Livro, unsigned long int rgaAluno) {
    Livro *livro = acervo;
    
    while (livro != NULL && livro->id != id_Livro) {
        livro = livro->prox;
    }

    if(livro == NULL) {
        printf("\n------- LIVRO NAO ENCONTRADO! -------\n");
        return;
    }

    if(livro->Exemplares_Disponiveis == 0) {
        printf("\n------- NAO HA EXEMPLARES DISPONIVEIS PARA EMPRESTIMO! -------\n");
        return;
    }

    livro->Exemplares_Disponiveis--;

    Emprestimo *novo_emprestimo = (Emprestimo *) malloc(sizeof(Emprestimo));
    novo_emprestimo->id_Livro = id_Livro;
    strcpy(novo_emprestimo->titulo, livro->titulo);
    strcpy(novo_emprestimo->autor, livro->autor);
    novo_emprestimo->RGA = rgaAluno;
    novo_emprestimo->prox = emprestimos;
    emprestimos = novo_emprestimo;

    printf("\n------- LIVRO EMPRESTADO COM SUCESSO! -------\n");
}

void devolve_livro(int id_Livro) {
    Emprestimo *emprestimo_Atual = emprestimos;
    Emprestimo *emprestimo_Anterior = NULL;

    while (emprestimo_Atual != NULL && emprestimo_Atual->id_Livro != id_Livro) {
        emprestimo_Anterior = emprestimo_Atual;
        emprestimo_Atual = emprestimo_Atual->prox;
    }

    if (emprestimo_Atual == NULL) {
        printf("\n------- EMPRESTIMO NAO ENCONTRADO! -------\n");        return;
    }

    if (emprestimo_Anterior == NULL) {
        emprestimos = emprestimo_Atual->prox;
    } else {
        emprestimo_Anterior->prox = emprestimo_Atual->prox;
    }

    free(emprestimo_Atual);

    Livro *livro = acervo;
    bool encontrou = false;

    while(livro != NULL) {
        if(livro->id == id_Livro) {
            livro->Exemplares_Disponiveis++;
            encontrou = true;
        }
        livro = livro->prox;
    }

    if(encontrou) {
        printf("\n------- LIVRO DEVOLVIDO COM SUCESSO! -------\n");    
        } else {
        printf("\n------- LIVRO NAO ENCONTRADO! -------\n");
    }
}

void lista_emprestimos() {
    Emprestimo *atual = emprestimos;

    if (atual == NULL) {
        printf("\n------- NENHUM EXEMPLAR EMPRESTADO NO MOMENTO. -------\n");
        return;
    } else {
        printf("\n------- LISTA DE EXEMPLARES EMPRESTADOS -------\n");
        while(atual != NULL){
            printf("ID do Livro: %d | Titulo: %s | Autor: %s | RGA: %ld \n", atual->id_Livro, atual->titulo, atual->autor, atual->RGA);
            atual = atual->prox;
        }
    }
}

void encerra() {
    printf("                                                                  ..  .,.\n");
    printf("                                                              .ed$$$$???$$e\n");
    printf("                                                           .e$$$P\",zebbc`9$\n");
    printf("                                                         z$$$P\"ud$$$$$$P.dF\n");
    printf("                                                       e$$$\" z$$$$$$$P\"d$\n");
    printf("                                                    .e$$P\".d$$$$$$$P\"z$\"\n");
    printf("                                      zdd$$bbe=-  zd$P\"ud$$$$$$$$P\"z$\"\n");
    printf("                  .,uuu,.           z$$$$$$$$$$$bc:\"4d$$$$$$$P\",zdP\"\n");
    printf("            ,=.c$$$$$$$$$$bc.      J$$$$$$$$$$$$$P\"  3$$$P\".eP\"\"\n");
    printf("        .zd$,d$$$$$$$$$$$$$$$c.    \"$$$$$PPFF\"\":.zd$$b\"\".+=\"\n");
    printf("      .d$$$$$$$$$$$$$$$$$$?$$$$c    $$$Fu rx$\"d$PF\"  ``\n");
    printf("     d$$$$$$$$$$$$$$$\"   =q,`\"?$  $$$$F9 $\"/\"\n");
    printf("   .$$$$$$$$$$$$$$P\"        \"?$c`?c `$$$ EJE.\n");
    printf("  u$$$$$$$$$$$$$\"             `\"$c`?e`$$' ??\"\n");
    printf(" d$$$$$$$$$$$$$\"                  \"?`\"zed$E9\"`\\.\n");
    printf("d$$$$$$$$$$$$P\"                       $ ud$$d\"?c\n");
    printf("$$$$$$$$$$$F                         `$J$',,`?$b`.\n");
    printf("4$$$$?$$P\"                           `$$'<$$$e\"$$b.\n");
    printf("\"`          Mbc                      \"$.<$$$$$`$$$c      ,zc,.\n");
    printf("             `?MMc                     ?$ $$???$\"`\"\"..,cd$$$$$$C  _.- ~\n");
    printf("        ec,    \"MMb.         .eWe       $b`    `i   ,$$$$$$9$$$\"~   _ .\n");
    printf("        \"MMMb.  `?MM.       dMMP\"zbc,,..9$$. .,db  ,$$$$$L\"d$$F- ~\n");
    printf("          \"?MMbu  \"MMc     9MMP d$$$$$$$$$$6kuLdbP\"\"``\"$$F<$$\" = -- -\n");
    printf("             \"?MMe.P5Mbu.  9MM 9$$$$$$C\"\",$$$$$E:dx(xd`J$>)\"'\n");
    printf("               `?M\"zMMMMMMMMMM $$$$$$$$$$bc\"??$$ecu,,ud$$'\n");
    printf("       ,,umu,,.  \"dMMMMMMMMMMML`\"??$$$$$$$$$bc\"????????\"\n");
    printf("      ?MMMMMMMMMMkMMMMMMMMMMMME -~  / `\"\"\"\"\"\"`  bc-=\n");
    printf("             ``''\"?MMMMMMMMMcMF    '             \"$L   z;Cr\n");
    printf("                   `?MMMMMMM\",u   '       :(C;u   $F ,??;CF\n");
    printf("                       \"\"\",mP\"           `;?;CC= `r +;?;e;\"\n");
    printf("                          \"\",u             \"CCC:C><;?;/CcJb\n");
    printf("                            \"$k            .c'C>\">C'J?.'P JcL\n");
    printf("                             $$u         .d$E >\" dddk u,\",d$$c,\n");
    printf("                              $$$k    d$$$\"      d$$'$$$>?)'    \"?$$$b.\n");
}