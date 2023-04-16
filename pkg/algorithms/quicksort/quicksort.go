package quicksort

func partition(list []int, left, right int) int {
	pivot := list[right]
	index := left

	for i := left; i < right; i++ {
        v := list[i]
		if v <= pivot {
			if i != index {
				list[i], list[index] = list[index], list[i]
			}

			index++
		}
	}

	list[right], list[index] = list[index], list[right]

	return index
}

func quicksort(list []int, left, right int) {
	if left < right {
		pivot := partition(list, left, right)

		quicksort(list, pivot+1, right)
		quicksort(list, left, pivot-1)
	}
}

func Quicksort(list []int) {
	quicksort(list, 0, len(list)-1)
}
