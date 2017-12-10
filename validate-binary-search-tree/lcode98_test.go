package lcode98

import (
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isValidBSTInRange(root *TreeNode, min, max *int) bool {
	if min != nil {
		if root.Val <= *min {
			return false
		}
	}
	if max != nil {
		if root.Val >= *max {
			return false
		}
	}
	if root.Left != nil {
		if !isValidBSTInRange(root.Left, min, &root.Val) {
			return false
		}
	}
	if root.Right != nil {
		if !isValidBSTInRange(root.Right, &root.Val, max) {
			return false
		}
	}
	return true
}

func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isValidBSTInRange(root, nil, nil)
}

func makeTree(vals []int) *TreeNode {
	nodes := make([]*TreeNode, len(vals))
	for i, v := range vals {
		if v != 0 {
			nodes[i] = &TreeNode{
				Val: v,
			}
		}
	}
	for i, n := range nodes {
		if nodes[i] == nil {
			continue
		}
		l := 2*i + 1
		if l < len(nodes) {
			n.Left = nodes[l]
		}
		r := 2 * (i + 1)
		if r < len(nodes) {
			n.Right = nodes[r]
		}
	}
	return nodes[0]
}

func TestCase1(t *testing.T) {
	tree := makeTree([]int{2, 1, 3})
	if !isValidBST(tree) {
		t.Error(1)
	}
	tree = makeTree([]int{5, 0, 7, 0, 0, 6})
	if !isValidBST(tree) {
		t.Error(2)
	}
	if !isValidBST(nil) {
		t.Error(3)
	}
	tree = makeTree([]int{1, 1})
	if isValidBST(tree) {
		t.Error(4)
	}
}
