#include "arvore.h"

// cria uma arvore vazia apenas com o nó raiz apontando para NULL
Arvore *cria_arv_vazia(void) {
  return NULL;
}

// constroi uma arvore com o nó raiz com o valor c e os filhos esq e dir apontando para NULL
Arvore *constroi_arv(char c, Arvore *e, Arvore *d) {
  Arvore *no = (Arvore *) malloc(sizeof(Arvore));
  no->info = c;
  no->esq = e;
  no->dir = d;
  return no;
}

// verifica se a arvore é vazia ou não (se o nó raiz aponta para NULL)
int verifica_arv_vazia(Arvore *a) {
  return (a == NULL);
}

// libera a memória alocada para a arvore e todos os nós internos (recursivo)
void arv_libera(Arvore *a) {
  if (!verifica_arv_vazia(a)) {
    arv_libera(a->esq);
    arv_libera(a->dir);
    free(a);
  }
}

//========= Exercício 2 - pré-ordem (recursivo) =========
void pre_ordem(Arvore *a) {
  if (!verifica_arv_vazia(a)) {
    printf("%c ", a->info);
    pre_ordem(a->esq);
    pre_ordem(a->dir);
  }
}

//========= Exercício 2 - in-ordem (recursivo) =========
void in_ordem(Arvore *a) {
  if (!verifica_arv_vazia(a)) {
    in_ordem(a->esq);
    printf("%c ", a->info);
    in_ordem(a->dir);
  }
}

//========= Exercício 2 - pós-ordem (recursivo) =========
void pos_ordem(Arvore *a) {
  if (!verifica_arv_vazia(a)) {
    pos_ordem(a->esq);
    pos_ordem(a->dir);
    printf("%c ", a->info);
  }
}

//========= Exercício 3 - pertence (recursivo) =========
int pertence(Arvore *a, char c) {
  if (verifica_arv_vazia(a)) {
    return 0;
  } else if (a->info == c) {
    return 1;
  } else {
      return pertence(a->esq, c) ? 1 : pertence(a->dir, c) != 0;
  }
}

//========= Exercício 4 - conta nós (recursivo) =========
int conta_nos(Arvore *a) {
    return verifica_arv_vazia(a) ? 0 : 1 + conta_nos(a->esq) + conta_nos(a->dir);
}

//========= Exercício 5 - calcula altura da arvore (recursivo) =========
int calcula_altura(Arvore *a) {
  if (verifica_arv_vazia(a)) {
    return 0;
  } else {
    if (calcula_altura(a->esq) > calcula_altura(a->dir)) {
      return 1 + calcula_altura(a->esq);
    } else {
      return 1 + calcula_altura(a->dir);
    }
  }
}

//========= Exercício 6 - conta folhas (recursivo) =========
int conta_folhas(Arvore *a) {
  if (verifica_arv_vazia(a)) {
    return 0;
  } else if (verifica_arv_vazia(a->esq) && verifica_arv_vazia(a->dir)) {
    return 1;
  } else {
    return conta_folhas(a->esq) + conta_folhas(a->dir);
  }
}

//========= Exercício 7 - conta nós internos (recursivo) =========
int conta_nos_internos(Arvore *a) {
  if (verifica_arv_vazia(a)) {
    return 0;
  } else if (verifica_arv_vazia(a->esq) || verifica_arv_vazia(a->dir)) {
    return 0;
  } else {
    return 1 + conta_nos_internos(a->esq) + conta_nos_internos(a->dir);
  }
}

//========= Exercício 8 - conta nós no nível n (recursivo) =========
int conta_nos_nivel(Arvore *a, int n) {
  if (verifica_arv_vazia(a)) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return conta_nos_nivel(a->esq, n - 1) + conta_nos_nivel(a->dir, n - 1);
  }
}

// ========= Exercício 10 - printa caminho da maior altura (recursivo) =========
void mostra_maior_caminho(Arvore *a) {
  if (verifica_arv_vazia(a)) {
    return;
  } else {
    int altura_esq = calcula_altura(a->esq);
    int altura_dir = calcula_altura(a->dir);
    if (altura_esq > altura_dir) {
      mostra_maior_caminho(a->esq);
      printf("%c ", a->info);
    } else {
      mostra_maior_caminho(a->dir);
      printf("%c ", a->info);
    }
  }
}

// printa caminho da maior altura (iterativo)
void mostra_maior_caminho_iterativo(Arvore *a) {
  if (verifica_arv_vazia(a)) {
    return;
  } else {
    Arvore *p = a;
    while (p != NULL) {
      printf("%c ", p->info);
      p = calcula_altura(p->esq) > calcula_altura(p->dir) ? p->esq : p->dir;
    }
  }
}

// ========= Exercício 11 - printa o menor caminho (recursivo) =========
void mostra_menor_caminho(Arvore *a) {
  if (verifica_arv_vazia(a)) {
    return;
  } else {
    int altura_esq = calcula_altura(a->esq);
    int altura_dir = calcula_altura(a->dir);
    if (altura_esq < altura_dir) {
      mostra_menor_caminho(a->esq);
      printf("%c ", a->info);
    } else {
      mostra_menor_caminho(a->dir);
      printf("%c ", a->info);
    }
  }
}

// ========= Exercício 12 - printa nós estao no nível n (recursivo) =========
void mostra_neste_nivel(Arvore *a, int n) {
  if (verifica_arv_vazia(a)) {
    return;
  } else if (n == 1) {
    printf("%c ", a->info);
  } else {
    mostra_neste_nivel(a->esq, n - 1);
    mostra_neste_nivel(a->dir, n - 1);
  }
}

// ========= Exercício 13 - printa folhas (recursivo) =========
void mostra_folhas(Arvore *a) {
  if (verifica_arv_vazia(a)) {
    return;
  } else if (verifica_arv_vazia(a->esq) && verifica_arv_vazia(a->dir)) {
    printf("%c ", a->info);
  } else {
    mostra_folhas(a->esq);
    mostra_folhas(a->dir);
  }
}

// ========= Exercício 14 - printa nós internos (recursivo) =========
void mostra_nos_internos(Arvore *a) {
  if (verifica_arv_vazia(a)) {
    return;
  } else if (verifica_arv_vazia(a->esq) || verifica_arv_vazia(a->dir)) {
    return;
  } else {
    printf("%c ", a->info);
    mostra_nos_internos(a->esq);
    mostra_nos_internos(a->dir);
  }
}
