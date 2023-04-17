#include <stdio.h>

#include "./quicksort.h"

int Quicksort::partition(int *vector, int left, int right)
{
    int pivot = vector[right];
    int pointer = left;

    for (int index = left; index < right; index++)
    {
        if (vector[index] < pivot)
        {
            int aux = vector[pointer];
            vector[pointer] = vector[index];
            vector[index] = aux;

            pointer += 1;
        }
    }

    int aux = vector[pointer];
    vector[pointer] = vector[right];
    vector[right] = aux;

    return pointer;
}

void Quicksort::sort(int *vector, int left, int right)
{
    if (left < right)
    {
        int pivot = Quicksort::partition(vector, left, right);

        Quicksort::sort(vector, pivot + 1, right);
        Quicksort::sort(vector, left, pivot - 1);
    }
}