package lcode566

import "testing"
import "fmt"

func matrixReshape(nums [][]int, r int, c int) [][]int {
	rows := len(nums)
	cols := len(nums[0])
	total := rows * cols
	if total != r*c {
		return nums
	}
	ret := make([][]int, 0)
	for i := 0; i < total; i += c {
		ridx := i / cols
		cidx := i % cols
		tmp := make([]int, c)
		for j := 0; j < c; j++ {
			tmp[j] = nums[ridx][cidx]
			cidx++
			if cidx == cols {
				ridx++
				cidx = 0
			}
		}
		ret = append(ret, tmp)
	}
	return ret
}

func Test1(t *testing.T) {
	arr := [][]int{
		[]int{1, 2},
		[]int{3, 4},
		[]int{5, 6},
	}
	fmt.Println(matrixReshape(arr, 2, 3))
	fmt.Println(matrixReshape(arr, 2, 4))
}
