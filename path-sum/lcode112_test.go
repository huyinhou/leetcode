package lcode112

import (
	"testing"
)

func makeTree(vals []int, idx int) *TreeNode {
	size := len(vals)
	if vals[idx] == 0 {
		return nil
	}
	node := &TreeNode{
		Val: vals[idx],
	}
	child := 2*idx + 1
	if child < size {
		node.Left = makeTree(vals, child)
	}
	child++
	if child < size {
		node.Right = makeTree(vals, child)
	}
	return node
}
func TestCase1(t *testing.T) {
	if hasPathSum(nil, 0) != false {
		t.Error(1)
	}
	tree := makeTree([]int{1}, 0)
	if !hasPathSum(tree, 1) {
		t.Error(2)
	}
	tree = makeTree([]int{1, 0, 3}, 0)
	if hasPathSum(tree, 2) {
		t.Error(3)
	}
	if !hasPathSum(tree, 4) {
		t.Error(4)
	}

	tree = makeTree([]int{1, 2, 3, 4, 0, 7}, 0)
	if !hasPathSum(tree, 7) {
		t.Error(5)
	}
	if !hasPathSum(tree, 11) {
		t.Error(5)
	}

	tree = makeTree([]int{1, 2}, 0)
	if hasPathSum(tree, 1) {
		t.Error(7)
	}
	tree = makeTree([]int{-2, 0, -3}, 0)
	if !hasPathSum(tree, -5) {
		t.Error(8)
	}
	tree = makeTree([]int{1, -2, -3, 1, 3, -2, 0, -1}, 0)
	if !hasPathSum(tree, -1) {
		t.Error(9)
	}
}
