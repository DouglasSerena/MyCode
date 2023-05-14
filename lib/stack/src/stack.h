#ifndef STACK_H
#define STACK_H

#include <string>

enum StackError
{
    None = 0,
    IsFull = -1,
    IsEmpty = -2,
};

template <typename T>
class Stack
{
private:
    /**
     * Pointer that references the stack head
     */
    T *values;

    /**
     * Position of the last inserted value on the stack
     */
    int index;

    /**
     * Maximum value that stacks support
     */
    int maxSize;

public:
    Stack(int maxSize);
    ~Stack();

    /**
     * Returns the stack size
     */
    int getSize();

    /**
     * Returns the maximum stack size
     */
    int getMaxSize();

    /**
     * Inserts an object at the top of the Stack.
     */
    StackError push(T value);

    /**
     * Removes and returns the object at the top of the Stack.
     */
    T pop();

    /**
     * Returns the object at the top of the Stack without removing it.
     */
    T peek();

    /**
     * Determines whether the stack is empty
     */
    bool isEmpty();

    /**
     * Determines whether the stack is full
     */
    bool isFull();

    /**
     * Determines whether an element is in the Stack.
     */
    bool contains(T value);

    /**
     * Returns a string that represents the current object.
     */
    std::string toString();

    /**
     * 	Removes all objects from the Stack.
     */
    void clear();
};

#endif