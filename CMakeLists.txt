cmake_minimum_required(VERSION 3.23)
set(CMAKE_C_STANDARD 23)
project(estrutura-de-dados-2)

set(aula-1 1-arvores-conceito/)
set(aula-2 2-arvores-binarias-de-busca/)
set(aula-3 3-arvores-balanceadas-avl)
set(aula-4 4-arvore-b)
set(aula-5 5-heap-and-heap-sort)
set(aula-6 6-filas-de-prioridade)
set(aula-7 7-arvore-de-huffman)
set(aula-8 8-tabelas-hash)
set(aula-9 9-grafos-conceitos)
set(aula-10 10-grafos-busca-em-profundidade-largura)

## " CONTROL + SHIFT + / " (des)comenta linha selecionada
add_executable(aula-1 ${aula-1}/main.c ${aula-1}/arvore.c ${aula-1}/arvore.h)
add_executable(aula-2 ${aula-2}/main.c ${aula-2}/abb.c ${aula-2}/abb.h)
add_executable(aula-3 ${aula-3}/main.c ${aula-3}/avl.c ${aula-3}/avl.h )
#add_executable(aula-4 ${aula-4}/main.c ${} ${}) // sem código
add_executable(aula-5 ${aula-5}/main.c ${aula-5}/heap.c ${aula-5}/heap.h)
add_executable(aula-6 ${aula-6}/min_heap.c ${aula-6}/max_heap.c)
#add_executable(aula-7 ${aula-7}/main.c ${} ${})
add_executable(aula-8 ${aula-8}/main.c ${aula-8}/hash.c ${aula-8}/hash.h)
add_executable(aula-9 ${aula-9}/main.c ${aula-9}/grafo.h ${aula-9}/grafo.c)
add_executable(aula-10 ${aula-10}/main.c ${aula-10}/grafo.h ${aula-10}/grafo.c)






