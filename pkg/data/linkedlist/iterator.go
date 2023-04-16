package linkedlist

type Iterator[T interface{}] struct {
	Value    T
	Next     *Iterator[T]
	Previous *Iterator[T]
}
