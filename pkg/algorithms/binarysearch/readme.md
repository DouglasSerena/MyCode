# Binary search

### Overview

Binary search é um algoritmo de busca que utiliza a técnica de dividir para conquistar. A ideia é dividir o vetor em duas partes e verificar se o elemento que se deseja encontrar está na primeira ou na segunda parte. Após isso, a primeira ou a segunda parte do vetor é descartada e o processo é repetido.

### Complexidade

O algoritmo de Binary search possui complexidade de tempo O(log n) e complexidade de espaço O(1).

### Implementação

A implementação do algoritmo de Binary search possui duas funções: a função `BinarySearch` que é a função principal e a função `binarySearch` que é responsável por fazer a busca recursivamente.
A função `BinarySearch` recebe como parâmetro um vetor `v` e um elemento `x` que é o elemento que se deseja encontrar. A função `BinarySearch` chama a função `binarySearch` passando como parâmetro o vetor `v`, o elemento `x`, o índice `0` e o índice `v.length - 1`. A função `binarySearch` retorna um índice `i` que é o índice do elemento `x` no vetor `v`. Caso o elemento `x` não esteja no vetor `v`, a função `binarySearch` retorna `-1`.