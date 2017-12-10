package lcode598

import "testing"

func maxCount(m int, n int, ops [][]int) int {
	row, col := m, n
	for i := 0; i < len(ops); i++ {
		if row > ops[i][0] {
			row = ops[i][0]
		}
		if col > ops[i][1] {
			col = ops[i][1]
		}
	}
	return row * col
}

func Test1(t *testing.T) {
	ops := [][]int{
		[]int{2, 2},
		[]int{3, 3},
	}
	if 4 != maxCount(3, 3, ops) {
		t.Error(1)
	}
}
