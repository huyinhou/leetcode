package lcode671

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
	l := NewNode(5, nil, nil)
	r := NewNode(7, nil, nil)
	r = NewNode(5, l, r)
	l = NewNode(2, nil, nil)
	root := NewNode(2, l, r)
	ret := findSecondMinimumValue(root)
	if ret != 5 {
		t.Errorf("ret = %d", ret)
	}
}

func TestCase2(t *testing.T) {
	l := NewNode(2, nil, nil)
	r := NewNode(2, nil, nil)
	root := NewNode(2, l, r)
	ret := findSecondMinimumValue(root)
	if ret != -1 {
		t.Errorf("ret = %d", ret)
	}
}

func TestCase3(t *testing.T) {
	l := NewNode(4, nil, nil)
	r := NewNode(7, nil, nil)
	l = NewNode(3, l, r)
	r = NewNode(2, nil, nil)
	root := NewNode(2, l, r)
	ret := findSecondMinimumValue(root)
	if ret != 3 {
		t.Errorf("ret = %d", ret)
	}
}

func TestCase4(t *testing.T) {
	l := NewNode(3, nil, nil)
	r := NewNode(7, nil, nil)
	l1 := NewNode(3, l, r)
	l = NewNode(4, nil, nil)
	r = NewNode(5, nil, nil)
	r1 := NewNode(4, l, r)
	root := NewNode(2, l1, r1)
	ret := findSecondMinimumValue(root)
	if ret != 3 {
		t.Errorf("ret = %d", ret)
	}
}

func TestCase5(t *testing.T) {
	l := NewNode(3, nil, nil)
	r := NewNode(7, nil, nil)
	r1 := NewNode(3, l, r)
	l = NewNode(4, nil, nil)
	r = NewNode(5, nil, nil)
	l1 := NewNode(4, l, r)
	root := NewNode(2, l1, r1)
	ret := findSecondMinimumValue(root)
	if ret != 3 {
		t.Errorf("ret = %d", ret)
	}
}