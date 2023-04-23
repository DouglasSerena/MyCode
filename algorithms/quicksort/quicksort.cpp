#include <stdio.h>

#include "./quicksort.h"

void Quicksort::swap(int *vector, int from, int to)
{
    int value = vector[from];
    vector[from] = vector[to];
    vector[to] = value;
};

int Quicksort::partition(int *vector, int left, int right)
{
    int pivot = vector[right];
    int offset = left;

    for (int index = left; index < right; index++)
        if (vector[index] < pivot)
            Quicksort::swap(vector, index, offset++);

    Quicksort::swap(vector, right, offset);

    return offset;
}

void Quicksort::sort(int *vector, int left, int right)
{
    if (left < right)
    {
        int pivot = Quicksort::partition(vector, left, right);

        Quicksort::sort(vector, pivot + 1, right);
        Quicksort::sort(vector, left, pivot - 1);
    }
};