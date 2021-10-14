// 任务最多26种
// 因为同种任务必须间隔n，因此要先排数量最多的任务
// 然后将其看成桶，即有x个桶，往里面插入任务
// 插满后，剩余的任务显然不需要排队了，直接运行即可
func leastInterval(tasks []byte, n int) int {
	nums := [26]int{}
	for _, v := range tasks {
		nums[v - 'A'] += 1
	}
	maxTaskCnt := 0			// 同一种任务任务数最大值
	cnt := 0				// 同为最大值的任务种类
	sum := 0				// 总任务数
	for _, v := range nums {
		if maxTaskCnt < v {
			maxTaskCnt = v
			cnt = 1
		} else if maxTaskCnt == v {
			cnt += 1
		}
		sum += v
	}
	if sum >= maxTaskCnt*(n+1) {
		return sum
	}
	return (maxTaskCnt - 1)*(n+1) + cnt + int(math.Max(float64((sum - (cnt*maxTaskCnt)) - (n+1-cnt)*(maxTaskCnt-1)), 0.0))
}