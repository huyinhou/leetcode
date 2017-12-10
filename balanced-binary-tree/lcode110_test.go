package lcode110

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
	tree := makeTree([]int{1, 2, 3}, 0)
	if !isBalanced(tree) {
		t.Error("error")
	}
	tree = makeTree([]int{1, 0, 2, 0, 0, 1, 2}, 0)
	if isBalanced(tree) {
		t.Error("error")
	}
	tree = makeTree([]int{1, 2, 3, 4, 5, 7, 0, 6}, 0)
	if !isBalanced(tree) {
		t.Error("error")
	}
}

func TestCase2(t *testing.T) {
	if !isBalanced(nil) {
		t.Error("error")
	}
}
