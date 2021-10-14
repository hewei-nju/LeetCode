package main

import "fmt"

// 思路：先统计两个数组的长度，n1，n2，如果n1 + n2为奇数，则中位数即为(n1+n2)/2 + 1个
// 如果为偶数则为(n1 + n2)/2， (n1 + n2)/2 + 1两个位置
// 从1开始计数的
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	n1 := len(nums1)
	n2 := len(nums2)
	mid1 := 0
	mid2 := 0
	tmpVal := 0.0
	ret := 0.0
	if (n1+n2)%2 == 0 {
		mid1 = (n1 + n2) / 2
		mid2 = (n1 + n2)/2 + 1
	} else {
		mid1 = (n1 + n2)/2 + 1
	}
	for i, j := 0, 0; i < n1 || j < n2; {
		if mid1 == 0 && mid2 == 0 {
			if (n1 + n2) % 2 == 0 {
				return ret /2
			}
			return ret
		}
		if i < n1 && j < n2 {
			if nums1[i] < nums2[j] {
				tmpVal = float64(nums1[i])
				i += 1
			} else {
				tmpVal = float64(nums2[j])
				j += 1
			}
		} else if i < n1 {
			tmpVal = float64(nums1[i])
			i += 1
		} else {
			tmpVal = float64(nums2[j])
			j += 1
		}
		if mid1 > 0 {
			mid1 -= 1
		}
		if mid2 > 0 {
			mid2 -= 1
		}
		if mid1 == 0 && mid2 != 0 {
			ret += tmpVal
		}
		if mid1 == 0 && mid2 == 0 {
			ret += tmpVal
		}
	}
	if (n1 + n2) % 2 == 0 {
		return ret /2
	}
	return ret
}

func main() {
	fmt.Println(findMedianSortedArrays([]int{1, 2}, []int{3}))
}
