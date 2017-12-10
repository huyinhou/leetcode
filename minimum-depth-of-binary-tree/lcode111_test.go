package lcode111

import "testing"

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
	root := makeTree([]int{1}, 0)
	if minDepth(root) != 1 {
		t.Error(1)
	}
	if minDepth(nil) != 0 {
		t.Error(2)
	}
}

func TestCase2(t *testing.T) {
	root := makeTree([]int{1, 2, 0}, 0)
	if minDepth(root) != 2 {
		t.Error(3)
	}
	root = makeTree([]int{1, 2, 3, 0, 0, 5}, 0)
	if minDepth(root) != 2 {
		t.Error(4)
	}
	root = makeTree([]int{1, 2, 3, 4, 5}, 0)
	if minDepth(root) != 2 {
		t.Error(5)
	}
}
