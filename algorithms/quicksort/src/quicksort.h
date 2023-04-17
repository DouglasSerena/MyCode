#ifndef QUICKSORT_H
#define QUICKSORT_H

class Quicksort
{
private:
    int static partition(int *vector, int left, int right);

public:
    void static sort(int *vector, int left, int right);
};

#endif // QUICKSORT_H