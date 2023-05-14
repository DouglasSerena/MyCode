#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

#include "./linked_list_node.h"
#include "./linked_list_iterator.h"

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
    void insertFirst(LinkedListNode<T> node);
    void insertFirst(LinkedListNode<T> *node);

    void insertLast(T value);
    void insertLast(LinkedListNode<T> node);
    void insertLast(LinkedListNode<T> *node);

    LinkedListNode<T> *find(T value);

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
     * Returns a string representation of the List.
     */
    std::string toString();

    /**
     * 	Removes all objects from the List .
     */
    void clear();

    LinkedListIterator<T> begin();
    LinkedListIterator<T> end();
};

#endif