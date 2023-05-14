#include <stdio.h>
#include <assert.h>

#include "./linked_list.h"
#include "./linked_list_node.h"

int main()
{
    LinkedList<int> list = LinkedList<int>();

    list.insertFirst(2);
    list.insertFirst(LinkedListNode<int>(1));

    LinkedListNode<int> *two = list.getLast();

    list.insertLast(3);
    list.insertLast(LinkedListNode<int>(4));

    two->insertAfter(11);
    two->insertBefore(10);

    LinkedListNode<int> node = *list.getFirst();

    assert(list.toString() == "[ 1, 10, 2, 11, 3, 4 ]");

    list.clear();

    return 0;
}