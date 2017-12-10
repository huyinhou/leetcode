package lcode717

import "testing"

func isOneBitCharacter(bits []int) bool {
	total := len(bits)
	ones := 0
	for i := total - 2; i >= 0 && bits[i] != 0; i-- {
		ones++
	}
	if ones%2 != 0 {
		return false
	}
	return true
}

func Test1(t *testing.T) {
	if !isOneBitCharacter([]int{0}) {
		t.Error(1)
	}
	if !isOneBitCharacter([]int{1, 0, 0}) {
		t.Error(2)
	}
	if isOneBitCharacter([]int{0, 1, 0}) {
		t.Error(3)
	}
	if !isOneBitCharacter([]int{1, 0, 1, 1, 0}) {
		t.Error(4)
	}
	if isOneBitCharacter([]int{1, 1, 1, 0}) {
		t.Error(5)
	}
}
