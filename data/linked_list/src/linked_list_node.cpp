#include "./linked_list_node.h"

template class LinkedListNode<int>;

template <typename T>
LinkedListNode<T>::LinkedListNode()
{
    this->next = nullptr;
    this->previous = nullptr;
}

template <typename T>
LinkedListNode<T>::LinkedListNode(T value)
{
    this->value = value;

    this->next = nullptr;
    this->previous = nullptr;
}

template <typename T>
LinkedListNode<T>::~LinkedListNode()
{
    if (this->next != nullptr)
        this->next->previous = this->previous;

    if (this->previous != nullptr)
        this->previous->next = this->next;
}

template <typename T>
T LinkedListNode<T>::getValue() { return this->value; };

template <typename T>
LinkedListNode<T> *LinkedListNode<T>::getNext() { return this->next; };

template <typename T>
LinkedListNode<T> *LinkedListNode<T>::getPrevious() { return this->previous; };

template <typename T>
void LinkedListNode<T>::insertAfter(T value) { this->insertAfter(new LinkedListNode<T>(value)); }

template <typename T>
void LinkedListNode<T>::insertAfter(LinkedListNode<T> *node)
{
    if (node->getPrevious() != nullptr and node->getNext() != nullptr)
        node->previous->next = node->next;

    node->previous = this;

    if (this->next != nullptr)
        this->next->previous = node;

    node->next = this->next;

    this->next = node;
};

template <typename T>
void LinkedListNode<T>::insertBefore(T value) { this->insertBefore(new LinkedListNode<T>(value)); }

template <typename T>
void LinkedListNode<T>::insertBefore(LinkedListNode<T> *node)
{
    if (node->getPrevious() != nullptr and node->getNext() != nullptr)
        node->previous->next = node->next;

    node->previous = this->previous;

    if (this->previous != nullptr)
        this->previous->next = node;

    node->next = this;

    this->previous = node;
};
