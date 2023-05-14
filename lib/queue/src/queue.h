#ifndef QUEUE_H
#define QUEUE_H

enum QueueError
{
    None = 0,
    IsFull = -1,
    IsEmpty = -2,
};

template <typename T>
class Queue
{
private:
    /**
     * Pointer that references the queue head
     */
    T *values;

    /**
     * Index of the first element of the queue
     */
    int first;

    /**
     * Index of the last element of the queue
     */
    int last;

    /**
     * Queue size
     */
    int size;

    /**
     * Maximum value that queues support
     */
    int maxSize;

public:
    Queue(int maxSize);
    ~Queue();

    /**
     * Returns the queue size
     */
    int getSize();

    /**
     * Returns the maximum queue size
     */
    int getMaxSize();

    /**
     * 	Adds an object to the end of the Queue.
     */
    QueueError enqueue(T value);

    /**
     * 	Removes and returns the object at the beginning of the Queue.
     */
    T dequeue();

    /**
     * Returns the object at the top of the Queue without removing it.
     */
    T peek();

    /**
     * Determines whether the queue is empty
     */
    bool isEmpty();

    /**
     * Determines whether the queue is full
     */
    bool isFull();

    /**
     * Determines whether an element is in the Queue.
     */
    bool contains(T value);

    /**
     * 	Removes all objects from the Queue.
     */
    void clear();
};

#endif