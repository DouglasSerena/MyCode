package linkedlist_test

import (
	"testing"

	"github.com/DouglasSerena/my-code/pkg/data/linkedlist"
	"github.com/stretchr/testify/assert"
)

func TestLinkedList(t *testing.T) {
	t.Run("Should add a new value in list when call `Push`", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		list.Push(0)

		assert.Nil(t, list.Tail)
		assert.NotNil(t, list.Head)
		assert.Equal(t, 0, list.Head.Value)
	})

	t.Run("Should add a new values to the list and link the values between them when call `Push`", func(t *testing.T) {

		list := linkedlist.LinkedList[int]{}

		list.Push(0)
		list.Push(1)
		list.Push(2)

		assert.NotNil(t, list.Tail)
		assert.NotNil(t, list.Head)

		assert.Equal(t, 0, list.Head.Value)
		assert.Equal(t, 1, list.Head.Next.Value)
		assert.Equal(t, 2, list.Head.Next.Next.Value)

		assert.Equal(t, 2, list.Tail.Value)
		assert.Equal(t, 1, list.Tail.Previous.Value)
		assert.Equal(t, 0, list.Tail.Previous.Previous.Value)
	})

	t.Run("Should add a new value as first element in a list when call `Unshift`", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		list.Push(1)
		list.Push(2)

		assert.Equal(t, 1, list.Head.Value)
		assert.Equal(t, 2, list.Head.Next.Value)

		list.Unshift(0)

		assert.Equal(t, 0, list.Head.Value)
		assert.Equal(t, 1, list.Head.Next.Value)
		assert.Equal(t, 2, list.Head.Next.Next.Value)
	})

	t.Run("Should return first element of list when call `First`", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		list.Push(0)
		list.Push(1)
		list.Push(2)

		assert.Equal(t, 0, list.First())
	})

	t.Run("Should return last element of list when call `Last`", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		list.Push(0)
		list.Push(1)
		list.Push(2)

		assert.Equal(t, 2, list.Last())
	})

	t.Run("Should return an error when trying to get a value from an index that overflows the list", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		list.Push(0)
		list.Push(1)

		value, err := list.At(2)
		if err != nil {
			assert.ErrorIs(t, err, linkedlist.ErrItemNotFound)
		}

		assert.Equal(t, list.Default(), value)
	})

	t.Run("Should return element from index passed", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		list.Push(1)
		list.Push(2)
		list.Push(3)

		value, err := list.At(0)

		assert.Nil(t, err)
		assert.Equal(t, 1, value)

		value, err = list.At(1)

		assert.Nil(t, err)
		assert.Equal(t, 2, value)
	})

	t.Run("Should return element from index passed, but if the index is negative, the search starts from the tail of the list to the head", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		list.Push(1)
		list.Push(2)
		list.Push(3)

		value, err := list.At(-1)

		assert.Nil(t, err)
		assert.Equal(t, 3, value)

		value, err = list.At(-2)

		assert.Nil(t, err)
		assert.Equal(t, 2, value)
	})

	t.Run("Should remove last element of list when call `Pop`", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		list.Push(0)
		list.Push(1)
		list.Push(2)

		value, err := list.Pop()
		if err != nil {
			assert.Error(t, err)
		}

		assert.Equal(t, 2, value)
		assert.Equal(t, 2, list.Size)
		assert.Nil(t, list.Tail.Next)
	})

	t.Run("Should return error if try remove last element of list when call `Pop`", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		value, err := list.Pop()
		if err != nil {
			assert.ErrorIs(t, err, linkedlist.ErrListIsEmpty)
		}

		assert.Equal(t, list.Default(), value)
	})

	t.Run("Should remove first element of list when call `Shift`", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		list.Push(0)
		list.Push(1)
		list.Push(2)

		value, err := list.Shift()
		if err != nil {
			assert.Error(t, err)
		}

		assert.Equal(t, 0, value)
		assert.Equal(t, 2, list.Size)
		assert.Nil(t, list.Head.Previous)
	})

	t.Run("Should return error if try remove first element of list when call `Shift`", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		value, err := list.Shift()
		if err != nil {
			assert.ErrorIs(t, err, linkedlist.ErrListIsEmpty)
		}

		assert.Equal(t, list.Default(), value)
	})

	t.Run("Should return true when call `IsEmpty` if list is empty", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		assert.True(t, list.IsEmpty())

		list.Push(0)

		assert.False(t, list.IsEmpty())
	})

	t.Run("Should return false when call `IsNotEmpty` if list is not empty", func(t *testing.T) {
		list := linkedlist.LinkedList[int]{}

		assert.False(t, list.IsNotEmpty())

		list.Push(0)

		assert.True(t, list.IsNotEmpty())
	})
}
