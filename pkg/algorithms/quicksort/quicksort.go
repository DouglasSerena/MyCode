package quicksort

func sort(list []int, begin int, end int) {
	pivot := list[(begin+end)/2]

	left := begin
	right := end
	for left < right {
		if list[left] < pivot {
			left += 1
		}

		if list[right] > pivot {
			right -= 1
		}

		if left < right {
			aux := list[left]
			list[left] = list[right]
			list[right] = aux
		}
	}

	if left < end {
		sort(list, left+1, end)
	}

	if right > begin {
		sort(list, begin, right)
	}
}

func Sort(list []int) {
	sort(list, 0, len(list)-1)
}
