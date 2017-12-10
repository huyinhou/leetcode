package lcode155

type MinStack struct {
	Values []int
	MinVal int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(x int) {
	size := len(this.Values)
	if size == 0 {
		this.Values = append(this.Values, x)
		this.MinVal = x
	} else {
		this.Values = append(this.Values, x-this.MinVal)
		if x < this.MinVal {
			this.MinVal = x
		}
	}
}

func (this *MinStack) Pop() {
	size := len(this.Values)
	if size == 0 {
		return
	}
	last := this.Values[size-1]
	this.Values = this.Values[0 : size-1]
	if last < 0 {
		this.MinVal = this.MinVal - last
	}
}

func (this *MinStack) Top() int {
	size := len(this.Values)
	if size == 0 {
		return 0
	}
	// fmt.Println(this)
	if size == 1 {
		return this.Values[0]
	}
	last := this.Values[size-1]
	if last < 0 {
		return this.MinVal
	}
	return this.MinVal + last
}

func (this *MinStack) GetMin() int {
	return this.MinVal
}
