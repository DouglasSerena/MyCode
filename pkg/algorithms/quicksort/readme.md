# Quicksort

### Overview

Quicksort é um algoritmo de ordenação que utiliza a técnica de dividir para conquistar. A ideia é escolher um elemento do vetor como pivô e colocar todos os elementos menores que ele à esquerda e todos os elementos maiores que ele à direita. Após isso, ordena-se recursivamente as duas partes do vetor.

### Complexidade

O algoritmo de Quicksort possui complexidade de tempo O(n log n) e complexidade de espaço O(log n).

### Implementação

A implementação do algoritmo de Quicksort possui duas funções: a função `quicksort` que é a função principal e a função `partition` que é responsável por fazer a partição do vetor.
A função `quicksort` recebe como parâmetro um vetor `v` e dois índices `left` e `right` que indicam o início e o fim do vetor. A função `quicksort` chama a função `partition` passando como parâmetro o vetor `v`, o índice `left` e o índice `right`. A função `partition` retorna um índice `p` que é o índice do pivô. Após isso, a função `quicksort` chama a si mesma passando como parâmetro o vetor `v`, o índice `left` e o índice `p - 1`. A função `quicksort` também chama a si mesma passando como parâmetro o vetor `v`, o índice `p + 1` e o índice `right`.

![image](https://user-images.githubusercontent.com/61251163/232342313-14ee4c7b-690a-4629-954d-0157e9b93602.png)
