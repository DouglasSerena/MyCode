#include <malloc.h>

#include "./linked_list.h"

template class LinkedList<int>;

template <typename T>
LinkedList<T>::LinkedList()
{
    this->size = 0;

    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {}

template <typename T>
int LinkedList<T>::getSize() { return this->size; }

template <typename T>
LinkedListNode<T> *LinkedList<T>::getFirst() { return this->head; }

template <typename T>
LinkedListNode<T> *LinkedList<T>::getLast() { return this->tail; }

template <typename T>
void LinkedList<T>::insertFirst(T value) { return this->insertFirst(new LinkedListNode<T>(value)); }

template <typename T>
void LinkedList<T>::insertFirst(LinkedListNode<T> node) { return this->insertFirst(new LinkedListNode<T>(node.getValue())); }

template <typename T>
void LinkedList<T>::insertFirst(LinkedListNode<T> *node)
{
    this->size += 1;

    if (this->head == nullptr)
    {
        this->head = node;
        this->tail = node;
        return;
    }

    this->head->insertBefore(node);
    this->head = node;
}

template <typename T>
void LinkedList<T>::insertLast(T value) { return this->insertLast(new LinkedListNode<T>(value)); }

template <typename T>
void LinkedList<T>::insertLast(LinkedListNode<T> node) { return this->insertLast(new LinkedListNode<T>(node.getValue())); }

template <typename T>
void LinkedList<T>::insertLast(LinkedListNode<T> *node)
{
    this->size += 1;

    if (this->head == nullptr)
    {
        this->head = node;
        this->tail = node;
        return;
    }

    this->tail->insertAfter(node);
    this->tail = node;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::find(T value)
{
    if (this->head->getValue() == value)
        return this->head;

    if (this->tail->getValue() == value)
        return this->head;

    LinkedListNode<T> *node = this->head->getNext();

    while (node != nullptr and node != this->tail)
    {
        if (node->getValue() == value)
            return node;

        node = node->getNext();
    }

    return nullptr;
}

template <typename T>
bool LinkedList<T>::isEmpty() { return this->head == nullptr; }

template <typename T>
bool LinkedList<T>::isNotEmpty() { return this->head != nullptr; }

template <typename T>
bool LinkedList<T>::contains(T value) { return this->find(value) != nullptr; }

template <typename T>
std::string LinkedList<T>::toString()
{
    std::string output = "[";

    LinkedListNode<T> *node = this->head;

    while (node != nullptr)
    {
        if (node->getPrevious() == nullptr)
            output += " ";

        output += std::to_string(node->getValue());

        if (node->getNext() != nullptr)
            output += ", ";
        else
            output += " ";

        node = node->getNext();
    }

    output += "]";

    return output;
}

template <typename T>
void LinkedList<T>::clear()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::begin() { return LinkedListIterator<T>(this->head); }

template <typename T>
LinkedListIterator<T> LinkedList<T>::end() { return LinkedListIterator<T>(nullptr); }