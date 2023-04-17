#include <stdio.h>
#include <assert.h>

#include "./quicksort.h"

int main(int argc, char *argv[])
{
    int actual[6] = {4, 2, 3, 6, 1, 5};
    int expected[6] = {1, 2, 3, 4, 5, 6};
    size_t size = sizeof(actual) / sizeof(actual[0]);

    Quicksort::sort(actual, 0, size - 1);

    for (int i = 0; i < size; i++)
        assert(actual[i] == expected[i]);

    return 0;
}