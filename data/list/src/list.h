#ifndef LIST_H
#define LIST_H

enum ListError
{
    None = 0,
    DeleteOverflow = -1,
    NotFound = -2,
    RangeInvalid = -3
};

template <typename T>
using Predicate = void (*)(T value, int index);

template <typename T>
class List
{
private:
    /**
     * Pointer that references the list  head
     */
    T *values;

    /**
     * List  size
     */
    int size;

public:
    List();
    List(T *values, int size);
    ~List();

    /**
     * Returns the list  size
     */
    int getSize();

    ListError push(T value);
    ListError unshift(T value);
    ListError insert(int index, T value);

    T pop();
    T shift();
    ListError remove(int index, int count);

    List<T> *slice();
    List<T> *slice(int start);
    List<T> *slice(int start, int end);

    T at(int index);
    int indexOf(T value);

    void forEach(Predicate<T> predicate);

    /**
     * Determines whether the queue is empty
     */
    bool isEmpty();

    /**
     * Determines whether the queue is not empty
     */
    bool isNotEmpty();

    /**
     * Determines whether an element is in the List .
     */
    bool contains(T value);

    /**
     * 	Removes all objects from the List .
     */
    void clear();
};

#endif