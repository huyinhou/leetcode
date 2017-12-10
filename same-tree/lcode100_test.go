package lcode100

import (
	"testing"
)

func TestCase1(t *testing.T) {
	node := &TreeNode{
		Val: 1,
	}
	ret := isSameTree(nil, nil)
	if !ret {
		t.Error("error")
	}
	ret = isSameTree(node, nil)
	if ret {
		t.Error("2")
	}
	ret = isSameTree(nil, node)
	if ret {
		t.Error("3")
	}
}

func TestCase2(t *testing.T) {

}
