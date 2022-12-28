#include "hash.h"

int main () {
    int colisoes = 0;
    int M = 11;
    Hash *H = create_hash (M);
    hash_insert (H, M, 10, &colisoes);
    hash_insert (H, M, 22, &colisoes);
    hash_insert (H, M, 31, &colisoes);
    hash_insert (H, M, 4, &colisoes);
    hash_insert (H, M, 15, &colisoes);
    hash_insert (H, M, 28, &colisoes);
    hash_insert (H, M, 17, &colisoes);
    printf("Número de colisões: %d\n", colisoes);
    hash_print (H, M);
    free_hash (H, M);
    return 0;
}
