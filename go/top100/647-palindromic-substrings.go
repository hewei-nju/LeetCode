// 直觉：动态规划，从小往大计算，不过似乎我没想清楚！
// 又是抄题解的一天
func countSubstrings(s string) int {
	n := len(s)
	ans := 0
	for i := 0; i < 2*n - 1; i++ {
		l, r := i/2, i/2 + i%2
		for l >=0 && r < n && s[l] == s[r] {
			l--
			r++
			ans++
		}
	}
	return ans
}