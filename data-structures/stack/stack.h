#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    int *values;
    int maxSize;
    int index;
    int size;

    int get_index();

public:
    Stack(int maxSize);
    ~Stack();

    void push(int value);
    int pop();
    int peek();

    int get_size();

    bool is_full();
    bool is_empty();
};

#endif