// 思路：用一个映射来记录前面子串中存在哪些字符了，如果此时遇到字符已经存在，则从前一个已经存在的字符的index向后移动一位
// 不过需要注意：后面的index和start的关系
func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	start := 0
	end := 0
	ret := 1
	keyMap := map[byte]int{}
	for idx, ch := range s {
		val, ok := keyMap[byte(ch)]
		keyMap[byte(ch)] = idx
		end = idx
		if ok {
			// 注意这个start和val的关系，start不可能后退！
			if val >= start {
				start = val + 1
			}
		}
		if end-start+1 > ret {
			ret = end - start + 1
		}
	}
	return ret
}