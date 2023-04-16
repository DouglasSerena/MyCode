package binarysearch

func binarySearch(list []int, search int, left int, right int) int {
	if left > right {
		return -1
	}

	middle := (left + right) / 2

	if list[middle] == search {
		return middle
	}

	if list[middle] < search {
		return binarySearch(list, search, middle+1, right)
	}

	return binarySearch(list, search, left, middle-1)
}

func Binarysearch(list []int, search int) int {
	return binarySearch(list, search, 0, len(list))
}
