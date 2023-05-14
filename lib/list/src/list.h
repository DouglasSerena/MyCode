#ifndef LIST_H
#define LIST_H

#include <string>

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

    /**
     * New elements to add to the list.
     */
    ListError push(T value);

    /**
     * Inserts new elements at the start of an list.
     */
    ListError unshift(T value);

    /**
     * Inserts the elements of a collection into the list at the specified index.
     */
    ListError insert(int index, T value);

    /**
     * Removes the last element from an list and returns it.
     */
    T pop();

    /**
     * Removes the first element from an list and returns it.
     */
    T shift();

    /**
     * Removes the element at the specified index of the list.
     */
    ListError remove(T value, int count = 1);

    /**
     * Removes the element at the specified index of the list.
     */
    ListError removeAt(int index, int count = 1);

    /**
     * Returns a copy of a section of an list, specified by a range of indices.
     */
    List<T> slice();
    List<T> slice(int start);
    List<T> slice(int start, int end);

    /**
     * Returns the element at the specified index in the list.
     */
    T at(int index);

    /**
     * Returns the index of the first occurrence of a value in an list.
     */
    int indexOf(T value);

    /**
     * Performs the specified action for each element in an list.
     */
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
     * Returns a string representation of the List.
     */
    std::string toString();

    /**
     * 	Removes all objects from the List .
     */
    void clear();
};

#endif