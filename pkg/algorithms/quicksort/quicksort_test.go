package quicksort_test

import (
	"testing"

	"github.com/DouglasSerena/my-code/pkg/algorithms/quicksort"
	"github.com/stretchr/testify/assert"
)

func TestBinarySearch(t *testing.T) {
	t.Run("Should search value in Array<int>", func(t *testing.T) {
		list := []int{5, 3, 2, 6, 8, 1, 4, 9, 7}

		quicksort.Sort(list)

		assert.Equal(t, []int{1, 2, 3, 4, 5, 6, 7, 8, 9}, list)
	})

	t.Run("Should search value in Array<int>", func(t *testing.T) {
		list := []int{5, 3, 2, 6, 8, 1, 4, 9, 7, 10, 19, 14, 15, 12, 5, 11}

		quicksort.Sort(list)

		assert.Equal(t, []int{1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 19}, list)
	})
}
