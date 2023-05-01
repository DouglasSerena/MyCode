#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "./linked_list_node.h"

template <typename T>
using Predicate = void (*)(T value, int index);

template <typename T>
class LinkedList
{
private:
    int size;

    LinkedListNode<T> *head;
    LinkedListNode<T> *tail;

public:
    LinkedList();
    ~LinkedList();

    /**
     * Returns the list  size
     */
    int getSize();

    LinkedListNode<T> *getFirst();
    LinkedListNode<T> *getLast();

    void insertFirst(T value);
    void insertFirst(LinkedListNode<T> *node);

    void insertLast(T value);
    void insertLast(LinkedListNode<T> *node);

    LinkedListNode<T> *find(T value);

    /**
     * Performs the specified action for each element in an list.
     */
    void forEach(Predicate<T> predicate);

    /**
     * Determines whether the queue is empty
     */
    bool isEmpty();

    /**
     * Determines whether the queue is not empty
     */
    bool isNotEmpty();

    /**
     * Determines whether an element is in the List .
     */
    bool contains(T value);

    /**
     * 	Removes all objects from the List .
     */
    void clear();
};

#endif