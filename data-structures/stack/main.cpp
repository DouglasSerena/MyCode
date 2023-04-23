#include <stdio.h>

#include "./stack.h"

int main()
{
    Stack *stack = new Stack(5);

    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->push(6);
    stack->push(7);

    printf("V: %d\n", stack->peek());

    printf("List values from stack: \n");
    while (!stack->is_empty())
    {
        printf("%d", stack->pop());

        if (stack->get_size() > 0)
            printf(" - ");
    }

    return 0;
}