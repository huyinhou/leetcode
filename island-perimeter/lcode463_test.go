package lcode463

import (
	"testing"
)

func islandPerimeter(grid [][]int) int {
	rows := len(grid)
	cols := len(grid[0])
	total, neighbor := 0, 0
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if grid[i][j] == 0 {
				continue
			}
			total++
			if i > 0 {
				if grid[i-1][j] == 1 {
					neighbor++
				}
			}
			if j > 0 {
				if grid[i][j-1] == 1 {
					neighbor++
				}
			}
			if i < rows-1 {
				if grid[i+1][j] == 1 {
					neighbor++
				}
			}
			if j < cols-1 {
				if grid[i][j+1] == 1 {
					neighbor++
				}
			}
		}
	}
	return total*4 - neighbor
}

func Test1(t *testing.T) {
	island := [][]int{
		[]int{0, 1, 0, 0},
		[]int{1, 1, 1, 0},
		[]int{0, 1, 0, 0},
		[]int{1, 1, 0, 0},
	}
	if 16 != islandPerimeter(island) {
		t.Error(1)
	}
}
