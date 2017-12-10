package lcode575

import (
	"testing"
)

func distributeCandies(candies []int) int {
	tmp := make(map[int]int)
	for _, v := range candies {
		tmp[v] = 1
	}
	size := len(candies) / 2
	if size > len(tmp) {
		return len(tmp)
	}
	return size
}

func Test1(t *testing.T) {
	ret := distributeCandies([]int{1, 1, 1, 1, 3, 3})
	if ret != 2 {
		t.Error(1)
	}
	ret = distributeCandies([]int{1, 1, 2, 1, 3, 3})
	if ret != 3 {
		t.Error(1)
	}
}
