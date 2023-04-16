package binary_search

import "errors"

func binary(list []int, search int, left int, right int) (int, error) {
	if left > right {
		return -1, errors.New("not found")
	}

	middle := (left + right) / 2

	if list[middle] == search {
		return list[middle], nil
	}

	if list[middle] < search {
		return binary(list, search, middle+1, right)
	}

	return binary(list, search, left, middle-1)
}

func Binary(list []int, search int) (int, error) {
	return binary(list, search, 0, len(list))
}
