package lcode413

import "testing"

func numberOfArithmeticSlices(A []int) int {
	size := len(A)
	same, total := 0, 0
	for i := 2; i < size; i++ {
		if A[i-1]-A[i-2] == A[i]-A[i-1] {
			same++
		} else {
			if same > 0 {
				total += same * (same + 1) / 2
			}
			same = 0
		}
	}
	if same > 0 {
		total += same * (same + 1) / 2
	}
	return total
}

func Test1(t *testing.T) {
	if 3 != numberOfArithmeticSlices([]int{1, 2, 3, 4}) {
		t.Error(1)
	}
}
