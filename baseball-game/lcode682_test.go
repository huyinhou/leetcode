package lcode682

import (
	"strconv"
	"testing"
)

func calPoints(ops []string) int {
	var scores []int
	total, size, s := 0, 0, 0
	for _, v := range ops {
		size = len(scores)
		switch v {
		case "+":
			s = scores[size-1] + scores[size-2]
			total += s
		case "D":
			s = 2 * scores[size-1]
			total += s
		case "C":
			s = scores[size-1]
			total -= s
			scores = scores[:size-1]
			continue
		default:
			s, _ = strconv.Atoi(v)
			total += s
		}
		scores = append(scores, s)
	}
	return total
}

func Test1(t *testing.T) {
	ret := calPoints([]string{"5", "2", "C", "D", "+"})

	if ret != 30 {
		t.Error(1)
	}
	ret = calPoints([]string{"5", "-2", "4", "C", "D", "9", "+", "+"})
	if ret != 27 {
		t.Error(2)
	}
}
