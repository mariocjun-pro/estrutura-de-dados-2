#include "hash.h"

/* Endereçamento Aberto */

int linear_probing (int chave, int iter, int M) {
    return (chave + iter) % M;
}

int quadratic_probing (int chave, int iter, int M) {
    return (chave + iter + iter*iter) % M;
}

int double_hash (int chave, int iter, int M) {
    return (chave + iter * (1 + (chave % (M - 1)))) % M;
}

/* */
Hash* create_hash (int M) {
    int h;
    Hash *H = (Hash *)malloc(M * sizeof(Hash));
    for (h = 0; h < M; h++) {
        H[h].key = EMPTY;
    }
    return H;
}

/* */
void free_hash (Hash *H, int M) {
    free(H);
}

/* */
int hash_search (Hash *H, int M, int key) {
    int j, i = 0;
    do {
        j = linear_probing (key, i, M);
        //j = quadratic_probing (key, i, M);
        //j = double_hash (key, i, M);
        printf("Testando chave: %d\n", j);
        if (H[j].key == key) {
            return j;
        }
        i++;
    } while ((i != M) || (H[j].key != EMPTY));
    return -1;
}

/* */
int hash_insert (Hash *H, int M, int key, int *colisoes) {
    int j, i = 0;
    do {
        j = linear_probing (key, i, M);
        //j = quadratic_probing (key, i, M);
        //j = double_hash (key, i, M);
        if (H[j].key == EMPTY) {
            H[j].key = key;
            return j;
        }
        else {
            *colisoes = *colisoes + 1;
        }
        i++;
    } while (i != M);
    return -1;
}

/* */
void hash_print (Hash *H, int M) {
    int i;
    for (i = 0; i < M; i++) {
        if (H[i].key != EMPTY) {
            printf("%2d - %d\n", i, H[i].key);
        }
        else {
            printf("%2d -   \n", i);
        }
    }
}