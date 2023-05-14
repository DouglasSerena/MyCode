#include <stdio.h>
#include <assert.h>

#include "./queue.h"

int main()
{
    int order[] = {3, 2, 4, 6, 0};
    int size = sizeof(order) / sizeof(int);

    Queue<int> queue = Queue<int>(size);

    // Checksqueue initialization
    assert(queue.getSize() == 0);
    assert(queue.isEmpty() == true);
    assert(queue.getMaxSize() == 5);

    // Checks if the value is pushed onto the queue
    for (int i = 0; i < size; i++)
        queue.enqueue(order[i]);

    assert(queue.getSize() == size);

    // Checks if the queue is stuck full
    assert(queue.isFull() == true);
    assert(queue.isEmpty() == false);

    // Checks that the returned value is not popped from the queue
    assert(queue.peek() == order[0]);
    assert(queue.getSize() == size);

    // Checks if it contains value inside the queue
    assert(queue.contains(4) == true);
    assert(queue.contains(10) == false);

    // Checksif the queue overflows
    assert(queue.enqueue(13) == QueueError::IsFull);
    assert(queue.getSize() == size);

    // Checksif the string representing the queue is correct
    assert(queue.toString() == "[ 3, 2, 4, 6, 0 ]");

    // Checksif the values ​​are unquenched in order
    for (int i = 0; i < size; i++)
        assert(order[i] == queue.dequeue());

    // Checks if the queue is being emptied
    queue.clear();

    assert(queue.getSize() == 0);
    assert(queue.isFull() == false);
    assert(queue.isEmpty() == true);

    // Checks if the queue is validating if it is empty
    assert(queue.dequeue() == QueueError::IsEmpty);

    return 0;
}