#ifndef ESTRUTURA_DE_DADOS_2_ABB_H
#define ESTRUTURA_DE_DADOS_2_ABB_H

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct arvore {
    int info;
    struct arvore *esq;
    struct arvore *dir;
} Arvore;

Arvore *cria_arv_vazia(void);

void arv_libera(Arvore *a);

Arvore *inserir(Arvore *a, int v);

Arvore *remover(Arvore *a, int v);

int buscar(Arvore *a, int v);

void pre_order(Arvore *a);

void in_order(Arvore *a);

void pos_order(Arvore *a);

int menor_valor(Arvore *a);

int maior_valor(Arvore *a);

int maior_ramo(Arvore *a);

void imprime_decrescente(Arvore *a);

#endif //ESTRUTURA_DE_DADOS_2_ABB_H
