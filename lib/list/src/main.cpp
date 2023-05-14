#include <stdio.h>
#include <assert.h>

#include "./list.h"

int main()
{
    List<int> *list = new List<int>();

    // Check list initialization
    assert(list->getSize() == 0);
    assert(list->isEmpty() == true);

    // Checks if the value is pushed onto the list
    for (int i = 0; i < 5; i++)
        list->push(i);

    assert(list->getSize() == 5);

    // Checks if the value is unshifted onto the list
    for (int i = 5; i < 10; i++)
        list->unshift(i);

    assert(list->getSize() == 10);

    // Checks if the value is inserted into the list
    list->insert(5, 10);

    assert(list->getSize() == 11);

    // Checks if the value is popped from the list
    assert(list->pop() == 4);
    assert(list->getSize() == 10);

    // Checks if the value is shifted from the list
    assert(list->shift() == 9);
    assert(list->getSize() == 9);

    // Checks if the value is removed from the list
    list->removeAt(0, 3);

    assert(list->getSize() == 6);

    // Checks if the list is sliced
    List<int> *sliced = list->slice(2, 4);

    assert(sliced->getSize() == 2);

    // Checks if the value is at the index
    assert(list->at(0) == 5);

    // Checks if the value is at the index
    assert(list->indexOf(2) == 4);

    // Checks if it contains value inside the queue
    assert(list->contains(1) == true);
    assert(list->contains(32) == false);

    // Checks if the list is empty
    assert(list->isEmpty() == false);

    // Checks if the list is not empty
    assert(list->isNotEmpty() == true);

    // Checks if list is cleared
    list->clear();

    assert(list->getSize() == 0);
    assert(list->isEmpty() == true);
    assert(list->isNotEmpty() == false);

    return 0;
}