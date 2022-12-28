#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

int maior(int esq, int dir) {
    return esq > dir ? esq : dir;
}

int altura(Arvore *a) {
    return a == NULL ? -1 : a->altura;
}

int atualizar_altura(Arvore *a) {
    return maior(altura(a->esq), altura(a->dir)) + 1;
}

int balanceamento(Arvore *a) {
    return altura(a->esq) - altura(a->dir);
}

Arvore *rotacao_simples_esq(Arvore *a) {
    Arvore *aux = a->dir;
    a->dir = aux->esq;
    aux->esq = a;
    a->altura = atualizar_altura(a);
    aux->altura = atualizar_altura(aux);
    return aux;
}

Arvore *rotacao_simples_dir(Arvore *a) {
    Arvore *aux = a->esq;
    a->esq = aux->dir;
    aux->dir = a;
    a->altura = atualizar_altura(a);
    aux->altura = atualizar_altura(aux);
    return aux;
}

Arvore *rotacao_dupla_esq(Arvore *a) {
    a->dir = rotacao_simples_dir(a->dir);
    return rotacao_simples_esq(a);
}

Arvore *rotacao_dupla_dir(Arvore *a) {
    a->esq = rotacao_simples_esq(a->esq);
    return rotacao_simples_dir(a);
}

Arvore *atualizar_fb_dir(Arvore *a) {
    int fb = balanceamento(a);
    if (fb == -2) {
        if (balanceamento(a->dir) > 0) {
            return rotacao_dupla_esq(a);
        } else {
            return rotacao_simples_esq(a);
        }
    }
    return a;
}

Arvore *atualizar_fb_esq(Arvore *a) {
    int fb = balanceamento(a);
    if (fb == 2) {
        if (balanceamento(a->esq) < 0) {
            return rotacao_dupla_dir(a);
        } else {
            return rotacao_simples_dir(a);
        }
    }
    return a;
}

Arvore *inserir(Arvore *a, char chave) {
    if (a == NULL) {
        a = (Arvore *) malloc(sizeof(Arvore));
        a->chave = chave;
        a->altura = 0;
        a->esq = NULL;
        a->dir = NULL;
    } else if (chave < a->chave) {
        a->esq = inserir(a->esq, chave);
        a = atualizar_fb_esq(a);
    } else if (chave > a->chave) {
        a->dir = inserir(a->dir, chave);
        a = atualizar_fb_dir(a);
    }
    a->altura = atualizar_altura(a);
    return a;
}

Arvore *inserir_int(Arvore *a, int chave_int) {
    if (a == NULL) {
        a = (Arvore *) malloc(sizeof(Arvore));
        a->chave_int = chave_int;
        a->altura = 0;
        a->esq = NULL;
        a->dir = NULL;
    } else if (chave_int < a->chave_int) {
        a->esq = inserir_int(a->esq, chave_int);
        a = atualizar_fb_esq(a);
    } else if (chave_int > a->chave_int) {
        a->dir = inserir_int(a->dir, chave_int);
        a = atualizar_fb_dir(a);
    }
    a->altura = atualizar_altura(a);
    return a;
}

/*Função para remover um nó de uma árvore binária de busca balanceada!*/
Arvore *remover(Arvore *a, char chave) {
    if (a == NULL) {
        return NULL;
    } else {
        if (chave < a->chave) {
            a->esq = remover(a->esq, chave);
            a = atualizar_fb_dir(a);
        } else if (chave > a->chave) {
            a->dir = remover(a->dir, chave);
            a = atualizar_fb_esq(a);
        } else {
            if ((a->esq == NULL) && (a->dir == NULL)) {
                free(a);
                a = NULL;
            } else if (a->esq == NULL) {
                No *tmp = a;
                a = a->dir;
                free(tmp);
            } else if (a->dir == NULL) {
                No *tmp = a;
                a = a->esq;
                free(tmp);
            } else {
                No *tmp = a->esq;
                while (tmp->dir != NULL) {
                    tmp = tmp->dir;
                }
                a->chave = tmp->chave;
                tmp->chave = chave;
                a->esq = remover(a->esq, chave);
                a = atualizar_fb_dir(a);
            }
        }
        return a;
    }
}

Arvore *remover_int(Arvore *a, int chave_int) {
    if (a == NULL) {
        return NULL;
    } else {
        if (chave_int < a->chave_int) {
            a->esq = remover_int(a->esq, chave_int);
            a = atualizar_fb_dir(a);
        } else if (chave_int > a->chave_int) {
            a->dir = remover_int(a->dir, chave_int);
            a = atualizar_fb_esq(a);
        } else {
            if ((a->esq == NULL) && (a->dir == NULL)) {
                free(a);
                a = NULL;
            } else if (a->esq == NULL) {
                No *tmp = a;
                a = a->dir;
                free(tmp);
            } else if (a->dir == NULL) {
                No *tmp = a;
                a = a->esq;
                free(tmp);
            } else {
                No *tmp = a->esq;
                while (tmp->dir != NULL) {
                    tmp = tmp->dir;
                }
                a->chave_int = tmp->chave_int;
                tmp->chave_int = chave_int;
                a->esq = remover_int(a->esq, chave_int);
                a = atualizar_fb_dir(a);
            }
        }
        return a;
    }
}

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order(Arvore *a, int nivel) {
    if (a != NULL) {
        int i;
        for (i = 0; i < nivel; i++) {
            printf("      ");
        }
        printf("Chave: %c (altura: %d, fb: %+d) no nível: %d\n", a->chave, a->altura, balanceamento(a), nivel);
        imprimir_in_order(a->esq, nivel + 1);
        imprimir_in_order(a->dir, nivel + 1);
    }
}

void imprimir_in_order_int(Arvore *a, int nivel) {
    if (a != NULL) {
        int i;
        for (i = 0; i < nivel; i++) {
            printf("      ");
        }
        printf("Chave: %d (altura: %d, fb: %+d) no nível: %d\n", a->chave_int, a->altura, balanceamento(a), nivel);
        imprimir_in_order_int(a->esq, nivel + 1);
        imprimir_in_order_int(a->dir, nivel + 1);
    }
}