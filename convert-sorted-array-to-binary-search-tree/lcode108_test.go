package lcode108

import (
	"testing"
)

func isBalance(root *TreeNode) bool {
	if root == nil {
		return false
	}
	if root.Left == nil {
		if root.Right == nil {
			return true
		}
		return (root.Right.Left == nil) && (root.Right.Right == nil)
	}
	if root.Right == nil {
		return (root.Left.Left == nil) && (root.Left.Right == nil)
	}
	return isBalance(root.Left) && isBalance(root.Right)
}

func inorderVisit(root *TreeNode, vals *[]int) {
	if root.Left != nil {
		inorderVisit(root.Left, vals)
	}
	*vals = append(*vals, root.Val)
	if root.Right != nil {
		inorderVisit(root.Right, vals)
	}
}

func isEqual(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func TestCase1(t *testing.T) {
	ret := sortedArrayToBST(nil)
	if ret != nil {
		t.Error(ret)
	}
	ret = sortedArrayToBST([]int{1})
	if !isBalance(ret) {
		t.Error("not balance")
	}
	vals := &[]int{}
	inorderVisit(ret, vals)
	if !isEqual(*vals, []int{1}) {
		t.Error(vals)
	}
	ret = sortedArrayToBST([]int{1, 2})
	if !isBalance(ret) {
		t.Error("not balance")
	}
	vals = &[]int{}
	inorderVisit(ret, vals)
	if !isEqual(*vals, []int{1, 2}) {
		t.Error(vals)
	}
}
