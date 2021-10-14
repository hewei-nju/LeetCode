func threeSum(nums []int) [][]int {
	n := len(nums)
	sort.Ints(nums)
	ans := make([][]int, 0)
	// 枚举a
	for first:= 0; first < n; first++ {
		if first > 0 && nums[first] == nums[first-1] {
			continue
		}
		// 此时c对应的指针初始指向数组的最右端
		third := n - 1
		target := -1 * nums[first]
		// 枚举b
		for second := first + 1; second < n; second++ {
			// 同上次枚举的数不同
			if second > first + 1 && nums[second] == nums[second - 1] {
				continue
			}
			// 保证b的指针在c的指针的左侧
			for second < third && nums[second] + nums[third] > target {
				third--
			}
			if second == third {
				break
			}
			if nums[second] + nums[third] == target {
				ans = append(ans, []int{nums[first], nums[second], nums[third]})
			}
		}
	}
	return ans
}