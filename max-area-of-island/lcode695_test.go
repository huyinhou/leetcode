package lcode695

import (
	"testing"
)

type Pos struct {
	Row int
	Col int
}

func NewPoint(x, y int) Pos {
	return Pos{
		Row: x,
		Col: y,
	}
}

func maxAreaOfIsland(grid [][]int) int {
	max := 0
	rows, cols := len(grid), len(grid[0])
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if grid[i][j] == 0 {
				continue
			}
			area := make([]Pos, 0)
			area = append(area, NewPoint(i, j))
			grid[i][j] = 0
			for idx := 0; idx < len(area); idx++ {
				p := area[idx]

				// top
				x, y := p.Row-1, p.Col
				if x >= 0 && grid[x][y] == 1 {
					area = append(area, NewPoint(x, y))
					grid[x][y] = 0
				}

				// bottom
				x, y = p.Row+1, p.Col
				if x < rows && grid[x][y] == 1 {
					area = append(area, NewPoint(x, y))
					grid[x][y] = 0
				}

				// left
				x, y = p.Row, p.Col-1
				if y >= 0 && grid[x][y] == 1 {
					area = append(area, NewPoint(x, y))
					grid[x][y] = 0
				}

				// right
				x, y = p.Row, p.Col+1
				if y < cols && grid[x][y] == 1 {
					area = append(area, NewPoint(x, y))
					grid[x][y] = 0
				}
			}
			if max < len(area) {
				// fmt.Println(area)
				max = len(area)
			}
		}
	}
	return max
}

func Test1(t *testing.T) {
	grid := [][]int{
		[]int{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		[]int{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		[]int{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		[]int{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		[]int{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		[]int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		[]int{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		[]int{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
	}
	if 6 != maxAreaOfIsland(grid) {
		t.Error(1)
	}
}
