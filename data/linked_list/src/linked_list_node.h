#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template <typename T>
class LinkedListNode
{
private:
    T value;
    LinkedListNode<T> *next;
    LinkedListNode<T> *previous;

public:
    LinkedListNode();
    LinkedListNode(T value);
    ~LinkedListNode();

    T getValue();

    LinkedListNode<T> *getNext();
    LinkedListNode<T> *getPrevious();

    void insertAfter(T value);
    void insertAfter(LinkedListNode<T> *node);

    void insertBefore(T value);
    void insertBefore(LinkedListNode<T> *node);
};

#endif