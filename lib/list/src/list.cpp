#include <malloc.h>
#include <math.h>

#include "./list.h"

template class List<int>;

template <typename T>
List<T>::List()
{
    this->size = 0;
    this->values = (T *)malloc(sizeof(T) * this->size);
}

template <typename T>
List<T>::List(T *values, int size)
{
    this->size = size;
    this->values = (T *)malloc(sizeof(T) * this->size);

    for (int i = 0; i < this->size; i++)
        this->values[i] = values[i];
}

template <typename T>
List<T>::~List() { free(this->values); }

template <typename T>
int List<T>::getSize() { return this->size; }

template <typename T>
bool List<T>::isEmpty() { return this->getSize() == 0; }

template <typename T>
bool List<T>::isNotEmpty() { return this->getSize() != 0; }

template <typename T>
ListError List<T>::push(T value) { return this->insert(this->size, value); }

template <typename T>
ListError List<T>::unshift(T value) { return this->insert(0, value); }

template <typename T>
ListError List<T>::insert(int index, T value)
{
    T *values = (T *)malloc(sizeof(T) * ++this->size);

    if (this->size == 1)
        values[0] = value;
    else
        for (int i = 0; i < this->size; i++)
        {
            if (i == index)
                values[i++] = value;

            if (i >= index)
                values[i] = this->values[i - 1];
            else
                values[i] = this->values[i];
        }

    free(this->values);

    this->values = values;

    return ListError::None;
}

template <typename T>
T List<T>::pop()
{
    T value = this->at(-1);
    this->removeAt(this->size - 1, 1);

    return value;
}

template <typename T>
T List<T>::shift()
{
    T value = this->at(0);
    this->removeAt(0, 1);

    return value;
}

template <typename T>
ListError List<T>::remove(T index, int count) { return this->removeAt(this->indexOf(index), count); }

template <typename T>
ListError List<T>::removeAt(int index, int count)
{
    if (count > this->size)
        return ListError::DeleteOverflow;

    if (count == 0)
        return ListError::None;

    if (this->size == 1)
    {
        this->size = 0;
        free(this->values);

        return ListError::None;
    }

    T *values = (T *)malloc(sizeof(T) * (this->size - count));

    int i2 = 0;
    for (int i = 0; i < this->size; i++)
    {
        if (i >= index and i <= index + count - 1)
            continue;

        values[i2++] = this->values[i];
    }

    free(this->values);

    this->size -= count;
    this->values = values;

    return ListError::None;
}

template <typename T>
List<T> List<T>::slice() { return this->slice(0, this->size); }

template <typename T>
List<T> List<T>::slice(int start) { return this->slice(start, this->size); }

template <typename T>
List<T> List<T>::slice(int start, int end)
{
    if (start > end)
        return List<T>();

    int size = end - start;
    T *values = (T *)malloc(sizeof(T) * size);

    int index = 0;
    for (int i = start; i < end; i++)
        values[index] = this->values[i];

    return List<T>(values, size);
}

template <typename T>
T List<T>::at(int index)
{
    index = trunc(index);

    if (index < 0)
        index += this->size;

    if (index < 0 or index >= this->size)
        return ListError::NotFound;

    return this->values[index];
}

template <typename T>
int List<T>::indexOf(T value)
{
    for (int i = 0; i < this->size; i++)
        if (this->values[i] == value)
            return i;

    return ListError::NotFound;
}

template <typename T>
bool List<T>::contains(T value)
{
    if (this->isEmpty())
        return false;

    for (int i = 0; i < this->getSize(); i++)
        if (this->values[i] == value)
            return true;

    return false;
}

template <typename T>
std::string List<T>::toString()
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
void List<T>::clear()
{
    free(this->values);

    this->size = 0;
    this->values = (T *)malloc(sizeof(T) * this->size);
}
