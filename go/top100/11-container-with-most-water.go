import "math"


func maxArea(height []int) int {
	ret := 0
	i, j := 0, len(height) - 1
	for i < j {
		ret = int(math.Max(float64(ret), float64(j - i) * math.Min(float64(height[i]), float64(height[j]))))
		if height[i] < height[j] {
			i += 1
		} else {
			j -= 1
		}
	}
	return ret
}