#include <stddef.h>
#include "abb.h"

Arvore *cria_arv_vazia(void) {
    return NULL;
}

// verifica se a arvore é vazia ou não (se o nó raiz aponta para NULL)
int verifica_arv_vazia(Arvore *a) {
    return (a == NULL);
}

void arvore_libera(Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        arvore_libera(a->esq);
        arvore_libera(a->dir);
        free(a);
    }
}

//========= Q1 - inserir na arvore binaria de busca, aceita repetições =========

Arvore *inserir(Arvore *a, int v){
    if (verifica_arv_vazia(a)) {
        a = (Arvore *) malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    } else if (v < a->info) {
        a->esq = inserir(a->esq, v);
    } else { // else if(v > a->info) se quiser evitar repetições
        a->dir = inserir(a->dir, v);
    }
    return a;
}

//========= Q1 - remover
Arvore *remover(Arvore *a, int v) {
    if (verifica_arv_vazia(a)) {
        return a;
    } else {
        if (v < a->info) {
            a->esq = remover(a->esq, v);
        } else if (v > a->info) {
            a->dir = remover(a->dir, v);
        } else {
            if (a->esq == NULL) {
                Arvore *aux = a->dir;
                free(a);
                return aux;
            } else if (a->dir == NULL) {
                Arvore *aux = a->esq;
                free(a);
                return aux;
            } else {
                a->info = menor_valor(a->dir);
                a->dir = remover(a->dir, a->info);
            }
        }
    }
    return a;
}

//========= Q1 - busca
int buscar(Arvore *a, int v) {
    if (verifica_arv_vazia(a)) {
        return 0;
    } else {
        if (v < a->info) {
            return buscar(a->esq, v);
        } else if (v > a->info) {
            return buscar(a->dir, v);
        } else {
            return 1;
        }
    }
}

//========= Q2 - menor valor da arvore
int menor_valor(Arvore *a) {
    return verifica_arv_vazia(a->esq) ? a->info : menor_valor(a->esq);
}
//========= Q2 - maior valor da arvore
int maior_valor(Arvore *a) {
    return verifica_arv_vazia(a->dir) ? a->info : maior_valor(a->dir);
}

//========= Q3 - imprime_decrescente =====
void imprime_decrescente(Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        imprime_decrescente(a->dir);
        printf("%d ", a->info);
        imprime_decrescente(a->esq);
    }
}

//========= Q4 - soma dos valores dos nos do maior ramo
int maior_ramo(Arvore *a) {
    if (verifica_arv_vazia(a)){
        return 0;
    } else {
        if (a->dir == NULL) {
            return a->info;
        } else {
            return a->info + maior_ramo(a->dir);
        }
    }
}

void pre_order(Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        printf("%d ", a->info);
        pre_order(a->esq);
        pre_order(a->dir);
    }
}

void pos_order(Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        pos_order(a->esq);
        pos_order(a->dir);
        printf("%d ", a->info);
    }
}

void in_order(Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        in_order(a->esq);
        printf("%d ", a->info);
        in_order(a->dir);
    }
}


