func peakIndexInMountainArray(arr []int) int {
	// O(n)
	/*
	maxVal := arr[0]
	index := 0
	for i := 1; i < len(arr); i++ {
		if maxVal < arr[i] {
			maxVal = arr[i]
			index = i
		}
	}*/


	// O(logn)--->二分搜索
	// result in range[1, n-2]
	left := 1
	right := len(arr) - 2
	for left < right {
		mid := (left + right) / 2
		if arr[mid] < arr[mid + 1] {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}