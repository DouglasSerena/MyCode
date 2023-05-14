#include <malloc.h>

#include "./stack.h"

template class Stack<int>;

template <typename T>
Stack<T>::Stack(int maxSize)
{
    this->index = -1;
    this->maxSize = maxSize;
    this->values = (T *)malloc(sizeof(T) * maxSize);
}

template <typename T>
Stack<T>::~Stack() { free(this->values); }

template <typename T>
int Stack<T>::getSize() { return this->index + 1; }

template <typename T>
int Stack<T>::getMaxSize() { return this->maxSize; }

template <typename T>
bool Stack<T>::isEmpty() { return this->index == -1; }

template <typename T>
bool Stack<T>::isFull() { return this->getSize() == this->maxSize; }

template <typename T>
StackError Stack<T>::push(T value)
{
    if (this->isFull())
        return StackError::IsFull;

    values[++this->index] = value;

    return StackError::None;
}

template <typename T>
T Stack<T>::pop()
{
    if (this->isEmpty())
        return StackError::IsEmpty;

    return values[this->index--];
}

template <typename T>
T Stack<T>::peek()
{
    if (this->isEmpty())
        return StackError::IsEmpty;

    return values[this->index];
}

template <typename T>
bool Stack<T>::contains(T value)
{
    if (this->isEmpty())
        return false;

    for (int i = 0; i < this->getSize(); i++)
        if (this->values[i] == value)
            return true;

    return false;
}

template <typename T>
std::string Stack<T>::toString()
{
    std::string output = "[";

    for (int i = 0; i < this->getSize(); i++)
    {
        if (i == 0)
            output += " ";

        output += std::to_string(this->values[i]);

        if (i != this->getSize() - 1)
            output += ", ";
        else
            output += " ";
    }

    output += "]";

    return output;
}

template <typename T>
void Stack<T>::clear() { this->index = -1; }
