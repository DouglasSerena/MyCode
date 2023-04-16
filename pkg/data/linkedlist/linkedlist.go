package linkedlist

import (
	"errors"
	"math"

	"github.com/DouglasSerena/my-code/pkg/internal/helpers"
)

var (
	ErrListIsEmpty  = errors.New("list is empty")
	ErrItemNotFound = errors.New("item not found in list")
)

type LinkedList[T interface{}] struct {
	Head *Iterator[T]
	Tail *Iterator[T]
	Size int
}

func (l *LinkedList[T]) First() T {
	return l.Head.Value
}

func (l *LinkedList[T]) Last() T {
	return l.Tail.Value
}

func (l *LinkedList[T]) At(index int) (T, error) {
	indexFloat := float64(index)
	if math.Abs(indexFloat) >= float64(l.Size) {
		return l.Default(), ErrItemNotFound
	}

	var candidate *Iterator[T]
	if math.Signbit(indexFloat) {
		size := l.Size * -1
		candidate = l.Tail

		for i := -1; i > size; i-- {
			if i == index {
				return candidate.Value, nil
			}

			candidate = candidate.Previous
		}
	} else {
		candidate = l.Head

		for i := 0; i < l.Size; i++ {
			if i == index {
				return candidate.Value, nil
			}

			candidate = candidate.Next
		}
	}

	return l.Default(), ErrItemNotFound
}

func (l *LinkedList[T]) Pop() (T, error) {
	if l.IsEmpty() {
		return l.Default(), ErrListIsEmpty
	}

	tail := l.Tail

	l.Size -= 1

	l.Tail = tail.Previous
	l.Tail.Next = nil

	tail.Previous = nil

	return tail.Value, nil
}

func (l *LinkedList[T]) Shift() (T, error) {
	if l.IsEmpty() {
		return l.Default(), ErrListIsEmpty
	}

	head := l.Head

	l.Size -= 1

	l.Head = head.Next
	l.Head.Previous = nil

	head.Next = nil

	return head.Value, nil
}

func (l *LinkedList[T]) Push(value T) {
	iterator := &Iterator[T]{Value: value}

	l.Size += 1

	if helpers.IsNull(l.Head) {
		l.Head = iterator
		return
	}

	if helpers.IsNull(l.Tail) {
		l.Tail = iterator
		l.Head.Next = l.Tail
		l.Tail.Previous = l.Head
		return
	}

	iterator.Previous = l.Tail
	l.Tail.Next = iterator
	l.Tail = iterator
}

func (l *LinkedList[T]) Unshift(value T) {
	l.Head = &Iterator[T]{
		Value: value,
		Next:  l.Head,
	}
}

func (l *LinkedList[T]) Default() T {
	return *new(T)
}

func (l *LinkedList[T]) IsEmpty() bool {
	return l.Size == 0
}

func (l *LinkedList[T]) IsNotEmpty() bool {
	return l.Size > 0
}
