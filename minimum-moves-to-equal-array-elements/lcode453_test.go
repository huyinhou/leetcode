package lcode453

import "testing"

// n-1个元素都加1，相当于只给一个元素减1，最少减多少步让所有都元素相等？所有元素等于最小值是最优解。
func minMoves(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	total, minval := 0, nums[0]
	for _, v := range nums {
		total += v
		if v < minval {
			minval = v
		}
	}
	return total - len(nums)*minval
}

func Test1(t *testing.T) {
	if 3 != minMoves([]int{1, 2, 3}) {
		t.Error(1)
	}
	if 4 != minMoves([]int{1, 2, 3, 2}) {
		t.Error(2)
	}
}
