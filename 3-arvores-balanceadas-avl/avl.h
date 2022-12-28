#ifndef ESTRUTURA_DE_DADOS_2_AVL_H
#define ESTRUTURA_DE_DADOS_2_AVL_H

// convert char to int (ASCII)
#define CHAR_TO_INT(c) ((int) c)

typedef struct node {
    char chave;
    int chave_int;
    int altura;
    struct node *esq;
    struct node *dir;
} No, Arvore;

int maior(int esq, int dir);

int altura(Arvore *a);

int atualizar_altura(Arvore *a);

int balanceamento(Arvore *a);

Arvore *rotacao_simples_esq(Arvore *a);

Arvore *rotacao_simples_dir(Arvore *a);

Arvore *rotacao_dupla_esq(Arvore *a);

Arvore *rotacao_dupla_dir(Arvore *a);

Arvore *atualizar_fb_dir(Arvore *a);

Arvore *atualizar_fb_esq(Arvore *a);

Arvore *inserir(Arvore *a, char chave);

Arvore *inserir_int(Arvore *a, int chave);

Arvore *remover(Arvore *a, char chave);

Arvore *remover_int(Arvore *a, int chave);

void imprimir_in_order(Arvore *a, int nivel);

void imprimir_in_order_int(Arvore *a, int nivel);

#endif //ESTRUTURA_DE_DADOS_2_AVL_H
