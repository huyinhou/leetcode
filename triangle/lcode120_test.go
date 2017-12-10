package lcode120

import (
	"fmt"
	"testing"
)

func minimumTotal(triangle [][]int) int {
	size := len(triangle)
	temp := make([]int, size+1)
	copy(temp, triangle[size-1])
	fmt.Println(temp)
	for i := size - 2; i >= 0; i-- {
		row := triangle[i]
		for j := 0; j < len(row); j++ {
			if temp[j] < temp[j+1] {
				temp[j] += row[j]
			} else {
				temp[j] = temp[j+1] + row[j]
			}
		}
	}
	return temp[0]
}

func TestCase1(t *testing.T) {
	tmp := [][]int{
		[]int{2},
		[]int{3, 4},
		[]int{6, 5, 7},
		[]int{4, 1, 8, 3},
	}
	ret := minimumTotal(tmp)
	if ret != 11 {
		t.Error(1)
	}

	tmp = [][]int{
		[]int{-1},
		[]int{2, 3},
		[]int{1, -1, -3},
	}
	ret = minimumTotal(tmp)
	if ret != -1 {
		t.Error(-2)
	}
}
