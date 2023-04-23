#include <stdio.h>
#include <assert.h>

#include "./quicksort.h"

int main()
{
    int vector[] = {5, 2, 4, 7, 6, 1, 3};
    int sorted[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 6;

    Quicksort::sort(vector, 0, size);

    printf("List sorted with quicksort\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d", vector[i]);

        if (i < size - 1)
            printf(" - ");
    }

    printf("\n\nList sorted without quicksort\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d", sorted[i]);

        if (i < size - 1)
            printf(" - ");
    }

    printf("\n\nTest if the values are equal...");
    for (int i = 0; i < size; i++)
        assert(vector[i] == sorted[i]);

    return 0;
}