// // 思路：直接将0~(len-1)的数字贴到最后即可按照正常动态规划进行计算
// func maxSubarraySumCircular(nums []int) int {
// 	arr := append(nums, nums[: len(nums) - 1]...)
// }


package main

import "fmt"

func main() {
	var arr1 = []int{1,2,3, 4, 5}
	s1 := append(arr1, arr1[: 4]...)
	// var arr2 = []int{4,5,6}
    // var arr3 = []int{7,8,9}
    // var s1 = append(append(arr1, arr2...), arr3...)
    fmt.Printf("s1: %v\n", s1)
}