#ifndef ED2_AULA_1_20_08_2022_ARVORES_INTRODUCAO_ARVORE_H
#define ED2_AULA_1_20_08_2022_ARVORES_INTRODUCAO_ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
  char info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

Arvore *cria_arv_vazia(void);
Arvore *constroi_arv(char c, Arvore *e, Arvore *d);

void arv_libera(Arvore *a);

int verifica_arv_vazia(Arvore *a);
int pertence(Arvore *a, char c);
int conta_nos(Arvore *a);
int calcula_altura(Arvore *a);
int conta_folhas(Arvore *a);
int conta_nos_internos(Arvore *a);
int conta_nos_nivel(Arvore *a, int n);

void pre_ordem(Arvore *a);
void in_ordem(Arvore *a);
void pos_ordem(Arvore *a);

void mostra_maior_caminho(Arvore *a);
void mostra_maior_caminho_iterativo(Arvore *a);
void mostra_menor_caminho(Arvore *a);
void mostra_neste_nivel(Arvore *a, int n);
void mostra_folhas(Arvore *a);
void mostra_nos_internos(Arvore *a);

#endif //ED2_AULA_1_20_08_2022_ARVORES_INTRODUCAO_ARVORE_H
