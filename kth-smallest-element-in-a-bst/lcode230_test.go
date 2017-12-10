package lcode230

import (
	"testing"
)

func NewNode(val int, left, right *TreeNode) *TreeNode {
	return &TreeNode {
		Val : val,
		Left : left,
		Right : right,
	}
}

func TestCase1(t *testing.T) {
	l := NewNode(2, nil, nil)
	r := NewNode(5, nil, nil)
	root := NewNode(3, l, r)
	ret := kthSmallest(root, 1)
	if ret != 2 {
		t.Errorf("1th ret=%d", ret)
	}
	ret = kthSmallest(root, 2)
	if ret != 3 {
		t.Errorf("2th ret=%d", ret)
	}
	ret = kthSmallest(root, 3)
	if ret != 5 {
		t.Errorf("3th ret=%d", ret)
	}
}

func TestCase2(t *testing.T) {
	// r := NewNode(5, nil, nil)
	l := NewNode(2, nil, nil)
	r := NewNode(3, l, nil)
	root := NewNode(1, nil, r)
	ret := kthSmallest(root, 1)
	if ret != 1 {
		t.Errorf("1th ret=%d", ret)
	}
	ret = kthSmallest(root, 2)
	if ret != 2 {
		t.Errorf("2th ret=%d", ret)
	}
	ret = kthSmallest(root, 3)
	if ret != 3 {
		t.Errorf("3th ret=%d", ret)
	}
}