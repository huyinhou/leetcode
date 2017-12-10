package lcode104

import (
	"testing"
)

func newTreeNode(val int, left, right *TreeNode) *TreeNode {
	return &TreeNode{
		Val:   val,
		Left:  left,
		Right: right,
	}
}

func TestCase1(t *testing.T) {
	ret := maxDepth(nil)
	if ret != 0 {
		t.Error("1")
	}
	ret = maxDepth(newTreeNode(1, nil, nil))
	if ret != 1 {
		t.Error("2")
	}
	node := newTreeNode(1,
		newTreeNode(2,
			nil,
			newTreeNode(3, nil, nil)),
		nil)
	ret = maxDepth(node)
	if ret != 3 {
		t.Error(3)
	}
}

func TestCase2(t *testing.T) {

}
