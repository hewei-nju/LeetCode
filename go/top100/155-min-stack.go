type MinStack struct {
	vals []int
	top int
	minVal int

}


func Constructor() MinStack {
	stk := MinStack{}
	stk.vals =  []int{1}
	stk.top = -1
	stk.minVal = math.MaxInt32
	return stk
}


func (this *MinStack) Push(val int)  {
	this.top += 1
	this.vals[this.top] = val
}


func (this *MinStack) Pop()  {
	if this.top > 0 {
		this.top -= 1
	}
}


func (this *MinStack) Top() int {
	if this.top >= 0 {
		return this.vals[this.top]
	}
	return 0
}


func (this *MinStack) GetMin() int {
	if this.top < 0 {
		return 0
	}
	return this.minVal
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */