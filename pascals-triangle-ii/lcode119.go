package lcode119

func getRow(rowIndex int) []int {
	row := make([]int, rowIndex+1)
	for i := 1; i <= rowIndex+1; i++ {
		count := i
		for j := count - 1; j >= 0; j-- {
			if j == 0 {
				row[j] = 1
			} else if j == count-1 {
				row[j] = 1
			} else {
				row[j] = row[j] + row[j-1]
			}
		}
	}
	return row
}
