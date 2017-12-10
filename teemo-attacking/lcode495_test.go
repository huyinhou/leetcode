package lcode495

import (
	"testing"
)

func findPoisonedDuration(timeSeries []int, duration int) int {
	if len(timeSeries) == 0 || duration == 0 {
		return 0
	}
	ret, first, last := 0, timeSeries[0], timeSeries[0]+duration
	for i := 1; i < len(timeSeries); i++ {
		if timeSeries[i] > last {
			ret += last - first
			first = timeSeries[i]
		}
		last = timeSeries[i] + duration
	}
	ret += last - first
	return ret
}

func Test1(t *testing.T) {
	if 4 != findPoisonedDuration([]int{1, 4}, 2) {
		t.Error(1)
	}
	if 3 != findPoisonedDuration([]int{1, 2}, 2) {
		t.Error(2)
	}
}
