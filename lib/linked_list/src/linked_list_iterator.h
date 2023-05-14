#ifndef LINKED_LIST_ITERATOR_H
#define LINKED_LIST_ITERATOR_H

#include "./linked_list_node.h"

template <typename T>
class LinkedListIterator
{
public:
    LinkedListNode<T> *current;

    LinkedListIterator(LinkedListNode<T> *node);

    T operator*();
    LinkedListIterator<T> *operator++();
    bool operator!=(const LinkedListIterator<T> other);
};

#endif