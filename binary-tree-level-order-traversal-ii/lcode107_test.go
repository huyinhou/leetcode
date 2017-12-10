package lcode107

import "testing"
import "fmt"

func newTreeNode(val int, left, right *TreeNode) *TreeNode {
	return &TreeNode{
		Val:   val,
		Left:  left,
		Right: right,
	}
}

func isEqualArr(a, b []int) bool {
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

func isEqual(p, q [][]int) bool {
	if len(p) != len(q) {
		return false
	}
	for i := 0; i < len(p); i++ {
		if !isEqualArr(p[i], q[i]) {
			return false
		}
	}
	return true
}

func TestCase1(t *testing.T) {
	p := newTreeNode(1, nil, nil)
	q := newTreeNode(2, p, nil)
	p = newTreeNode(3, nil, q)
	fmt.Print(p)
	ret := levelOrderBottom(p)
	if !isEqual(ret, [][]int{{1}, {2}, {3}}) {
		t.Error(ret)
	}
}

func TestCase2(t *testing.T) {
	ret := levelOrderBottom(nil)
	if !isEqual(ret, [][]int{}) {
		t.Error(ret)
	}
	p := newTreeNode(15, nil, nil)
	q := newTreeNode(7, nil, nil)
	q = newTreeNode(20, p, q)
	p = newTreeNode(9, nil, nil)
	p = newTreeNode(3, p, q)
	ret = levelOrderBottom(p)
	if !isEqual(ret, [][]int{{15, 7}, {9, 20}, {3}}) {
		t.Error(ret)
	}
}
