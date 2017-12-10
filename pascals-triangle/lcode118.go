package lcode118

func generate(numRows int) [][]int {
	ret := make([][]int, numRows)
	if numRows == 0 {
		return ret
	}
	prev := make([]int, 0)
	for i := 0; i < numRows; i++ {
		cols := i + 1
		curr := make([]int, cols)
		for j := 0; j < cols; j++ {
			if j == 0 {
				curr[j] = 1
			} else if j == i {
				curr[j] = 1
			} else {
				curr[j] = prev[j-1] + prev[j]
			}
		}
		ret[i] = curr
		prev = curr
	}
	return ret
}
