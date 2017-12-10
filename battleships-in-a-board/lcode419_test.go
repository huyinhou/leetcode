package lcode419

import "testing"

func countBattleships(board [][]byte) int {
	rows := len(board)
	if rows == 0 {
		return 0
	}
	cols := len(board[0])
	sum := 0
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if board[i][j] == 'X' {
				if i > 0 && board[i-1][j] == 'X' {
					continue
				}
				if j > 0 && board[i][j-1] == 'X' {
					continue
				}
				sum += 1
			}
		}
	}
	return sum
}

func Test1(t *testing.T) {
	board := [][]byte{
		[]byte{'X', '.', '.'},
		[]byte{'.', '.', 'X'},
		[]byte{'.', '.', 'X'},
	}
	c := countBattleships(board)
	if c != 2 {
		t.Error(1)
	}
}
