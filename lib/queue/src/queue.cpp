#include <malloc.h>

#include "./queue.h"

template class Queue<int>;

template <typename T>
Queue<T>::Queue(int maxSize)
{
    this->last = -1;
    this->first = -1;

    this->size = 0;
    this->maxSize = maxSize;
    this->values = (T *)malloc(sizeof(T) * maxSize);
}

template <typename T>
Queue<T>::~Queue() { free(this->values); }

template <typename T>
int Queue<T>::getSize() { return this->size; }

template <typename T>
int Queue<T>::getMaxSize() { return this->maxSize; }

template <typename T>
bool Queue<T>::isEmpty() { return this->getSize() == 0; }

template <typename T>
bool Queue<T>::isFull() { return this->getSize() == this->maxSize; }

template <typename T>
QueueError Queue<T>::enqueue(T value)
{
    if (this->isFull())
        return QueueError::IsFull;

    this->last = ++this->last % this->maxSize;

    values[this->last] = value;

    if (this->first == -1)
        this->first = 0;

    this->size += 1;

    return QueueError::None;
}

template <typename T>
T Queue<T>::dequeue()
{
    if (this->isEmpty())
        return QueueError::IsEmpty;

    T value = this->values[this->first];

    this->first = ++this->first % this->maxSize;
    this->size -= 1;

    return value;
}

template <typename T>
T Queue<T>::peek()
{
    if (this->isEmpty())
        return QueueError::IsEmpty;

    return values[this->first];
}

template <typename T>
bool Queue<T>::contains(T value)
{
    if (this->isEmpty())
        return false;

    for (int i = 0; i < this->getSize(); i++)
        if (this->values[i] == value)
            return true;

    return false;
}

template <typename T>
void Queue<T>::clear()
{
    this->first = -1;
    this->last = -1;
    this->size = 0;
}
