#include "avl.h"
#include <stdio.h>

int main() {
/*    Arvore *AVL = NULL;

    printf("Passo 1:\n");
    AVL = inserir(AVL, 'Q');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 2:\n");
    AVL = inserir(AVL, 'Z');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 3:\n");
    AVL = inserir(AVL, 'B');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 4:\n");
    AVL = inserir(AVL, 'Y');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 5:\n");
    AVL = inserir(AVL, 'T');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 6:\n");
    AVL = inserir(AVL, 'M');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 7:\n");
    AVL = inserir(AVL, 'E');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 8:\n");
    AVL = inserir(AVL, 'W');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 9:\n");
    AVL = inserir(AVL, 'X');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 10:\n");
    AVL = inserir(AVL, 'S');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 11:\n");
    AVL = inserir(AVL, 'F');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 12:\n");
    AVL = inserir(AVL, 'G');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 13:\n");
    AVL = inserir(AVL, 'A');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 14:\n");
    AVL = inserir(AVL, 'H');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 15:\n");
    AVL = inserir(AVL, 'N');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 16:\n");
    AVL = inserir(AVL, 'O');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 17:\n");
    AVL = inserir(AVL, 'P');
    imprimir_in_order(AVL, 0);
    printf("\n\n");

    printf("Passo 18:\n");
    AVL = inserir(AVL, 'R');
    imprimir_in_order(AVL, 0);
    printf("\n\n");*/

    printf("Exercicio2 \n\n");

    Arvore *AVL2 = NULL;

    AVL2 = inserir_int(AVL2, 14);
    AVL2 = inserir_int(AVL2, 5);
    AVL2 = inserir_int(AVL2, 28);
    AVL2 = inserir_int(AVL2, 2);
    AVL2 = inserir_int(AVL2, 8);
    AVL2 = inserir_int(AVL2, 18);
    AVL2 = inserir_int(AVL2, 33);
    AVL2 = inserir_int(AVL2, 1);
    AVL2 = inserir_int(AVL2, 3);
    AVL2 = inserir_int(AVL2, 6);
    AVL2 = inserir_int(AVL2, 11);
    AVL2 = inserir_int(AVL2, 15);
    AVL2 = inserir_int(AVL2, 20);
    AVL2 = inserir_int(AVL2, 30);
    AVL2 = inserir_int(AVL2, 38);
    AVL2 = inserir_int(AVL2, 4);
    AVL2 = inserir_int(AVL2, 7);
    AVL2 = inserir_int(AVL2, 10);
    AVL2 = inserir_int(AVL2, 12);
    AVL2 = inserir_int(AVL2, 16);
    AVL2 = inserir_int(AVL2, 19);
    AVL2 = inserir_int(AVL2, 21);
    AVL2 = inserir_int(AVL2, 29);
    AVL2 = inserir_int(AVL2, 31);
    AVL2 = inserir_int(AVL2, 35);
    AVL2 = inserir_int(AVL2, 39);
    AVL2 = inserir_int(AVL2, 13);
    AVL2 = inserir_int(AVL2, 22);
    AVL2 = inserir_int(AVL2, 32);
    AVL2 = inserir_int(AVL2, 34);
    AVL2 = inserir_int(AVL2, 36);
    AVL2 = inserir_int(AVL2, 40);
    AVL2 = inserir_int(AVL2, 37);

    //imprimir_in_order_int(AVL2, 0);

    AVL2 = remover_int(AVL2, 1);

    printf("\n\n");

    imprimir_in_order_int(AVL2, 0);
}
