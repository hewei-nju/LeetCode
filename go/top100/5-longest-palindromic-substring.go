package main

import "fmt"

// 动态规划: dp[i][j]表示i-j范围是否是回文串
// 1. i == j -> dp[i][j] = true
// 2. i == j - 1 -> dp[i][j] = s[i] == s[j]
// 3. dp[i][j] = dp[i+1][j-1] & s[i] == s[j]

func longestPalindrome(s string) string {
	dp := make([][]bool, len(s))
	beg, maxLen := 0, 1
	for i := 0; i < len(s); i++ {
		dp[i] = make([]bool, len(s))
		dp[i][i] = true
	}
	for l := 2; l <= len(s); l++ {
		for i := 0; i < len(s); i++ {
			j := l + i - 1
			if j >= len(s) {
				break
			}
			if s[i] != s[j] {
				dp[i][j] = false
			} else {
				if j-i < 3 {
					dp[i][j] = true
				} else {
					dp[i][j] = dp[i+1][j-1]
				}
			}
			if dp[i][j] && j-i+1 > maxLen {
				beg = i
				maxLen = j - i + 1
			}
		}
	}
	return s[beg : beg+maxLen]
}
func main() {
	fmt.Println(longestPalindrome("babab"))
}
