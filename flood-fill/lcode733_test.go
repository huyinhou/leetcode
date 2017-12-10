package lcode733

import "testing"
import "fmt"

type Pos struct {
	Row int
	Col int
}

func bfs(image [][]int, sr, sc int, rows, cols int, newColor, orgColor int) {
	temp := []Pos{}
	tr := sr - 1
	if tr >= 0 && image[tr][sc] == orgColor {
		image[tr][sc] = newColor
		temp = append(temp, Pos{Row: tr, Col: sc})
	}
	tr = sr + 1
	if tr < rows && image[tr][sc] == orgColor {
		image[tr][sc] = newColor
		temp = append(temp, Pos{Row: tr, Col: sc})
	}

	tc := sc - 1
	if tc >= 0 && image[sr][tc] == orgColor {
		image[sr][tc] = newColor
		temp = append(temp, Pos{Row: sr, Col: tc})
	}
	tc = sc + 1
	if tc < cols && image[sr][tc] == orgColor {
		image[sr][tc] = newColor
		temp = append(temp, Pos{Row: sr, Col: tc})
	}

	for _, p := range temp {
		bfs(image, p.Row, p.Col, rows, cols, newColor, orgColor)
	}
}

func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
	orgColor := image[sr][sc]
	if orgColor == newColor {
		return image
	}
	image[sr][sc] = newColor
	rows, cols := len(image), len(image[0])
	bfs(image, sr, sc, rows, cols, newColor, orgColor)
	return image
}

func dumpImage(image [][]int) {
	for _, row := range image {
		fmt.Println(row)
	}
}
func Test1(t *testing.T) {
	image := [][]int{
		[]int{1, 1, 1},
		[]int{1, 1, 0},
		[]int{1, 0, 1},
	}
	ret := floodFill(image, 1, 1, 2)
	dumpImage(ret)
}
