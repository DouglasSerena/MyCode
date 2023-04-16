package binarysearch_test

import (
	"testing"

	search "github.com/DouglasSerena/my-code/pkg/algorithms/binarysearch"
	"github.com/stretchr/testify/assert"
)

func TestBinarySearch(t *testing.T) {
	t.Run("Should search value in Array<int>", func(t *testing.T) {
		list := []int{10, 11, 12, 13, 14, 15, 16, 17, 18, 19}

		index := search.Binarysearch(list, 16)

		assert.Equal(t, 6, index)
	})
}
