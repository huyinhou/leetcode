package lcode547

import "testing"

func findCircleNum(M [][]int) int {
	size := len(M)
	retv := 0
	for i := 0; i < size; i++ {
		if M[i][i] == 0 {
			continue
		}
		M[i][i] = 0
		circle := []int{i}
		for j := 0; j < len(circle); j++ {
			cur := circle[j]
			for k := 0; k < size; k++ {
				if M[cur][k] == 1 && M[k][k] == 1 {
					M[k][k] = 0
					circle = append(circle, k)
				}
			}
		}
		retv++
	}
	return retv
}

func Test1(t *testing.T) {
	M := [][]int{
		[]int{1, 1, 1},
		[]int{1, 1, 0},
		[]int{1, 0, 1},
	}
	if findCircleNum(M) != 1 {
		t.Error(findCircleNum(M))
	}
	M = [][]int{
		[]int{1, 0, 1},
		[]int{0, 1, 0},
		[]int{1, 0, 1},
	}
	if findCircleNum(M) != 2 {
		t.Error(findCircleNum(M))
	}
	M = [][]int{
		[]int{1, 0, 0},
		[]int{0, 1, 0},
		[]int{0, 0, 1},
	}
	if findCircleNum(M) != 3 {
		t.Error(findCircleNum(M))
	}
	M = [][]int{
		[]int{1, 0, 0, 1},
		[]int{0, 1, 1, 0},
		[]int{0, 1, 1, 1},
		[]int{1, 0, 1, 1},
	}
	if findCircleNum(M) != 1 {
		t.Error(findCircleNum(M))
	}
}
