package lcode101

import (
	"fmt"
	"testing"
)

func makeTree(vals []int) *TreeNode {
	fmt.Printf("%v\n", vals)
	size := len(vals)
	if size == 0 {
		return nil
	}
	half := size / 2
	if vals[half] == 0 {
		return nil
	}
	node := &TreeNode{
		Val: vals[half],
	}
	if half < 1 {
		node.Left = nil
	} else {
		node.Left = makeTree(vals[0:half])
	}
	half++
	if half >= size {
		node.Right = nil
	} else {
		node.Right = makeTree(vals[half:])
	}
	return node
}

func dumpTree(tree *TreeNode) {
	if tree == nil {
		return
	}
	fmt.Printf("%d\n", tree.Val)
	dumpTree(tree.Left)
	dumpTree(tree.Right)
}
func TestCase1(t *testing.T) {
	tree := makeTree([]int{3, 2, 4, 1, 4, 2, 3})
	ret := isSymmetric(nil)
	if !ret {
		t.Error("error")
	}
	ret = isSymmetric(tree)
	// dumpTree(tree)
	if !ret {
		t.Error("2")
	}
	tree = makeTree([]int{0, 2, 3, 1, 2, 3, 0})
	if !ret {
		t.Error("3")
	}
}
