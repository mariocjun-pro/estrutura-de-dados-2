#include "arvore.h"
int main() {

  Arvore *a;
  a = // constroi_arv('',cria_arv_vazia(),cria_arv_vazia())
      constroi_arv('a', // raiz da arvore
                   constroi_arv('b',
                                constroi_arv('n', //folha
                                             cria_arv_vazia(), // se esq e dir sao vazias, entao o nó pai é uma folha
                                             cria_arv_vazia()),
                                constroi_arv('d', //folha
                                             cria_arv_vazia(),
                                             cria_arv_vazia())),
                   constroi_arv('c',
                                constroi_arv('e',
                                             constroi_arv('m', // folha
                                                          cria_arv_vazia(),
                                                          cria_arv_vazia()),
                                             constroi_arv('f',
                                                          constroi_arv('g', // folha
                                                                       cria_arv_vazia(),
                                                                       cria_arv_vazia()),
                                                          cria_arv_vazia())),
                                constroi_arv('z', // folha
                                             cria_arv_vazia(),
                                             cria_arv_vazia()))
      );

  // imprime a arvore em pre-ordem
  printf("Pre-ordem: ");
  pre_ordem(a);

  // imprime a arvore em ordem
  printf("\nIn-ordem:  ");
  in_ordem(a);

  // imprime a arvore em pos-ordem
  printf("\nPos-ordem: ");
  pos_ordem(a);

  // verifica cada letra do alfabeto para ver se esta na arvore e as imprime
  printf("\n\n");
  printf("Pertence: ");
  for (int i = 97; i <= 122; i++) {
    if (pertence(a, i)) {
      printf("%c ", i);
    }
  }

  // calcula a altura da arvore e imprime o maior caminho encontrado
  printf("\n\nCaminho da maior altura (%d): ", calcula_altura(a));
  mostra_maior_caminho(a);

  // calcula a quantidade de nos da arvore e imprime os nos internos
  printf("\nQuantidade de nós (%d). Nós internos (%d): ", conta_nos(a), conta_nos_internos(a));
  mostra_nos_internos(a);

  // conta as folhas e imprime
  printf("\nFolhas: (%d) - ", conta_folhas(a));
  mostra_folhas(a);
  printf("\n");

  // mostra os nos de cada nivel
  for (int i = 1; i <= calcula_altura(a); i++) {
    printf("\nNós no nível (%d) - %d: ", i, conta_nos_nivel(a, i));
    mostra_neste_nivel(a, i);
  }

  // mostra o menor caminho
  printf("\n\nMenor caminho: ");
  mostra_menor_caminho(a);

  // mostra maior caminho sem recursão
  printf("\nMaior caminho: ");
  mostra_maior_caminho_iterativo(a);

  // libera a memoria alocada para a arvore
  arv_libera(a);

  //funcao pow recursiva implementada
  int x = 2;
  int y = 3;



  return 0;
}

