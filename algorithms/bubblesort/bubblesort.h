#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

class BubbleSort
{
public:
    static void swap(int *vector, int from, int to);
    static void v1(int *vector, int size);
    static void v2(int *vector, int size);
    static void v3(int *vector, int size);

    static void sort(int *vector, int size);
    static void sort(int *vector, int size, int version);
};

#endif