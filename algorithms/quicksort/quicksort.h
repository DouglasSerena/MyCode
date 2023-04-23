#ifndef QUICKSORT_H
#define QUICKSORT_H

class Quicksort
{
public:
    static void swap(int *vector, int from, int to);
    static int partition(int *vector, int left, int right);
    static void sort(int *vector, int left, int right);
};

#endif