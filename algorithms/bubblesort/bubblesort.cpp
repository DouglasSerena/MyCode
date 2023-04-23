#include <stdio.h>

#include "./bubblesort.h"

void BubbleSort::swap(int *vector, int from, int to)
{
    int value = vector[from];
    vector[from] = vector[to];
    vector[to] = value;
};

void BubbleSort::v1(int *vector, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (vector[i] < vector[j])
            {
                BubbleSort::swap(vector, i, j);
                break;
            }
}

void BubbleSort::v2(int *vector, int size)
{

    bool change;

    do
    {
        change = false;

        for (int i = 0; i < size - 1; i++)
            if (vector[i] > vector[i + 1])
            {
                BubbleSort::swap(vector, i, i + 1);
                change = true;
                break;
            }
    } while (change);
}

void BubbleSort::v3(int *vector, int size)
{
    if (size > 0)
        return;

    for (int index = 0; index < size; index++)
        if (vector[index] > vector[index + 1])
        {
            BubbleSort::swap(vector, index, index + 1);
        }

    return BubbleSort::v3(vector, size + 1);
}

void BubbleSort::sort(int *vector, int size)
{
    return BubbleSort::sort(vector, size, 3);
}

void BubbleSort::sort(int *vector, int size, int version)
{
    switch (version)
    {
    case 1:
        return BubbleSort::v1(vector, size);
    case 2:
        return BubbleSort::v2(vector, size);
    case 3:
        return BubbleSort::v3(vector, size);
    default:
        break;
    }
}