package linkedlist_test

import (
	"testing"

	"github.com/DouglasSerena/my-code/pkg/data/linkedlist"
	"github.com/stretchr/testify/assert"
)

func TestIterator(t *testing.T) {
	t.Run("Should create new `Iterator` with value", func(t *testing.T) {
		iterator := linkedlist.Iterator[int]{Value: 1}

		assert.Equal(t, 1, iterator.Value)
		assert.Nil(t, iterator.Next)
		assert.Nil(t, iterator.Previous)
	})

	t.Run("Should create new `Iterator` and add Next `Iterator`", func(t *testing.T) {
		next := &linkedlist.Iterator[int]{Value: 2}
		iterator := &linkedlist.Iterator[int]{Value: 1, Next: next}

		assert.Equal(t, iterator.Next, next)
		assert.Equal(t, iterator.Next.Value, 2)
	})

	t.Run("Should create new `Iterator` and add Previous `Iterator`", func(t *testing.T) {
		previous := &linkedlist.Iterator[int]{Value: 2}
		iterator := &linkedlist.Iterator[int]{Value: 1, Previous: previous}

		assert.Equal(t, iterator.Previous, previous)
		assert.Equal(t, iterator.Previous.Value, 2)
	})
}
