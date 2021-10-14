// 25 19 20 26 27 18 30
// 3  1  1  1  2  1  0

// 思路：最开始肯定是双重循环
/*
func dailyTemperatures(temperatures []int) []int {
	ret := make([]int, len(temperatures))
	ret[len(temperatures) - 1] = 0
	for i:=0; i < len(temperatures) - 1; i++ {
		ret[i] = 0
		for j := i+1; j < len(temperatures); j++ {
			if temperatures[i] < temperatures[j] {
				ret[i] = j - i
				break
			}
		}	
	}
	return ret
}
*/
// 单调栈解法：抄的题解，熟悉golang语法
func dailyTemperatures(temperatures []int) []int {
	length := len(temperatures)
	ans := make([]int, length)
	stack := []int{}
	for i:=0; i < length; i++ {
		temperature:= temperatures[i]
		for len(stack) > 0 && temperature > temperatures[stack[len(stack) - 1]] {
			prevIndex := stack[len(stack) - 1]
			stack = stack[:len(stack) - 1]
			ans[prevIndex] = i - prevIndex
		}
		stack = append(stack, i)
	}
	return ans
}