package binary_search_test

import (
	"testing"

	"github.com/DouglasSerena/my-code/pkg/algorithms/binary_search"
	"github.com/stretchr/testify/assert"
)

func TestBinarySearch(t *testing.T) {
	t.Run("Should search value in Array<int>", func(t *testing.T) {
		list := []int{10, 11, 12, 13, 14, 15, 16, 17, 18, 19}

		value, err := binary_search.Binary(list, 16)
		if err != nil {
			assert.Error(t, err)
		}

		assert.Equal(t, 16, value)
	})
}
