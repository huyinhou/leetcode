package lcode553

import (
	"bytes"
	"fmt"
	"strconv"
	"testing"
)

func optimalDivision(nums []int) string {
	size := len(nums)
	if size == 1 {
		return strconv.Itoa(nums[0])
	}
	if size == 2 {
		return fmt.Sprintf("%d/%d", nums[0], nums[1])
	}
	buffer := new(bytes.Buffer)
	buffer.WriteString(strconv.Itoa(nums[0]))
	buffer.WriteString("/(")
	for i := 1; i < size; i++ {
		buffer.WriteString(strconv.Itoa(nums[i]))
		if i < size-1 {
			buffer.WriteString("/")
		}
	}
	buffer.WriteString(")")
	return buffer.String()
}

func Test1(t *testing.T) {
	fmt.Println(optimalDivision([]int{1000, 100, 10, 2}))
	fmt.Println(optimalDivision([]int{1000, 10}))
}
