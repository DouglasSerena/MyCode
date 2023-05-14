#include "./linked_list_iterator.h"

template class LinkedListIterator<int>;

template <typename T>
LinkedListIterator<T>::LinkedListIterator(LinkedListNode<T> *node) : current(node) {}

template <typename T>
T LinkedListIterator<T>::operator*() { return this->current->getValue(); };

template <typename T>
LinkedListIterator<T> *LinkedListIterator<T>::operator++()
{
    this->current = this->current->getNext();

    return this;
};

template <typename T>
bool LinkedListIterator<T>::operator!=(const LinkedListIterator<T> other) { return this->current != other.current; }
