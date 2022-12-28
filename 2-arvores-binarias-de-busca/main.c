#include <stdio.h>
#include <time.h>
#include "abb.h"

int main() {
    Arvore *a = cria_arv_vazia();

    a = inserir(a, 50);
    a = inserir(a, 50);
    a = inserir(a, 30);
    a = inserir(a, 90);
    a = inserir(a, 20);
    a = inserir(a, 40);
    a = inserir(a, 95);
    a = inserir(a, 10);
    a = inserir(a, 35);
    a = inserir(a, 45);
    a = inserir(a, 50);

    printf("\n(1) Imprimindo arvore em pre order:\n");
    pre_order(a);
    printf("\n(1) Imprimindo arvore em pos order:\n");
    pos_order(a);
    printf("\n(1) Imprimindo arvore em em order:\n");
    in_order(a);

    printf("\n\n(2) Menor valor da arvore: %d\n", menor_valor(a));
    printf("(2) Maior valor da arvore: %d\n\n", maior_valor(a));

    printf("(3) Soma maior ramo: %d\n\n", maior_ramo(a));

    printf("(4) Imprime a arvore decrescente:\n");
    imprime_decrescente(a);
    printf("\n\n");

    a = remover(a, 50);
    a = remover(a, 30);
    a = remover(a, 90);
    a = remover(a, 20);

    printf("[Removendo 50, 30, 90, 20]\n");
    printf("\n(1) Imprimindo arvore em pre order:\n");
    pre_order(a);
    printf("\n(1) Imprimindo arvore em pos order:\n");
    pos_order(a);
    printf("\n(1) Imprimindo arvore em em order:\n");
    in_order(a);

    printf("\n\nMenor valor: %d\n", menor_valor(a));
    printf("Maior valor: %d\n", maior_valor(a));

    printf("Soma maior ramo: %d\n\n", maior_ramo(a));

    printf("Imprime decrescente\n");
    imprime_decrescente(a);
    printf("\n");

    // ====== Q5 ====
    // produza 100000 em ordem de 0 a 999999, insira numa nova arvore, calcule o tempo gasto
    clock_t t;

    Arvore *a2 = cria_arv_vazia();
    t = clock();
    for (int i = 0; i < 1000; i++) {
        a2 = inserir(a2, i);
    }
    t = clock() - t;
    printf("Tempo gasto para inserir 1000 em ordem: %f\n", ((float)t)/CLOCKS_PER_SEC);
    printf("\n");

    // produza 100000 aleatoriamente de 0 a 999999, insira numa nova arvore, e conte o tempo que levou usando um timer
    //
    Arvore *a3 = cria_arv_vazia();
    t = clock();
    for (int i = 0; i < 1000; i++) {
        a3 = inserir(a3, rand() % 1000);
    }
    t = clock() - t;
    printf("Tempo gasto para inserir 1000 aleatoriamente: %f\n", ((float)t)/CLOCKS_PER_SEC);
    printf("\n");


    return 0;
}