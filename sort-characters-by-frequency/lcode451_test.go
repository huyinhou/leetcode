package lcode451

import (
	"bytes"
	"testing"
)

type SortInfo struct {
	Char  byte
	Count int
}

func frequencySort(s string) string {
	stack := []*SortInfo{}
	for i := 0; i < len(s); i++ {
		j := 0
		for ; j < len(stack); j++ {
			if stack[j].Char == s[i] {
				stack[j].Count += 1
				break
			}
		}
		if j == len(stack) {
			stack = append(stack, &SortInfo{s[i], 1})
		}
		for j > 0 {
			if stack[j].Count > stack[j-1].Count {
				stack[j-1], stack[j] = stack[j], stack[j-1]
				j--
			} else {
				break
			}
		}
	}
	temp := new(bytes.Buffer)
	for j := 0; j < len(stack); j++ {
		// fmt.Println(stack[j])
		for i := 0; i < stack[j].Count; i++ {
			temp.WriteByte(stack[j].Char)
		}
	}
	return temp.String()
}

func Test1(t *testing.T) {
	if "eetr" != frequencySort("tree") {
		t.Error(1)
	}
	if "cccaaa" != frequencySort("cacaca") {
		t.Error(2)
	}
}
