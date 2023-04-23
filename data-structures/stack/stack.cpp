#include <malloc.h>

#include "./stack.h"

Stack::Stack(int maxSize)
{
    this->index = -1;
    this->maxSize = maxSize;
    this->values = (int *)malloc(sizeof(int) * this->maxSize);
}

Stack::~Stack() { free(values); }

int Stack::get_index() { return this->index % this->maxSize; }

void Stack::push(int value)
{
    this->index += 1;
    this->values[this->get_index()] = value;

    if (this->size < this->maxSize)
        this->size++;
}

int Stack::pop()
{
    if (this->is_empty())
        return -1;

    int value = this->values[this->get_index()];

    this->size -= 1;
    this->index -= 1;

    return value;
}

int Stack::peek()
{

    if (this->is_empty())
        return -1;

    return this->values[this->get_index()];
}

int Stack::get_size() { return this->size; }

bool Stack::is_full() { return this->size == this->maxSize; }
bool Stack::is_empty() { return this->size == 0; }