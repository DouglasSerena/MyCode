#include <stdio.h>
#include <assert.h>

#include "./linked_list.h"
#include "./linked_list_node.h"

int main()
{
    LinkedList<int> *list = new LinkedList<int>();

    list->insertFirst(2);
    list->insertFirst(new LinkedListNode<int>(1));

    LinkedListNode<int> *two = list->getLast();

    list->insertLast(3);
    list->insertLast(new LinkedListNode<int>(4));

    two->insertAfter(11);
    two->insertBefore(10);

    LinkedListNode<int> *node = list->getFirst();

    list->forEach([](int value, int index)
                  { printf("V: %d\n", value); });

    list->clear();

    list->forEach([](int value, int index)
                  { printf("V: %d\n", value); });

    return 0;
}