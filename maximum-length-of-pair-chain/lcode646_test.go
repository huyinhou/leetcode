package lcode646

import "testing"
import "sort"

type Pairs [][]int

func (pairs Pairs) Len() int {
	return len(pairs)
}

func (pairs Pairs) Less(i, j int) bool {
	if pairs[i][0] < pairs[j][0] {
		return true
	} else if pairs[i][0] == pairs[j][0] {
		return pairs[i][1] < pairs[j][1]
	}
	return false
}

func (pairs Pairs) Swap(i, j int) {
	pairs[i][0], pairs[j][0] = pairs[j][0], pairs[i][0]
	pairs[i][1], pairs[j][1] = pairs[j][1], pairs[i][1]
}

func findLongestChain(pairs [][]int) int {
	sort.Sort(Pairs(pairs))
	size := len(pairs)
	if size == 0 {
		return 0
	}
	temp := make([]int, size)
	temp[size-1] = 1

	for i := size - 2; i >= 0; i-- {
		p := pairs[i]
		// 包含这个pair
		tmplen := 1
		for j := i + 1; j < size; j++ {
			if p[1] < pairs[j][0] { // 可以组成pair chain
				tmplen += temp[j]
				break
			}
		}
		// 不包含这个pair temp[i+1]
		if tmplen < temp[i+1] {
			tmplen = temp[i+1]
		}
		temp[i] = tmplen
	}

	return temp[0]
}

func Test1(t *testing.T) {
	pairs := [][]int{
		[]int{1, 2},
		[]int{5, 7},
		[]int{6, 8},
		[]int{3, 4},
		[]int{3, 3},
		[]int{2, 3},
		[]int{10, 11},
	}
	findLongestChain(pairs)
}
