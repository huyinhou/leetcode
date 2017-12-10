package lcode102

import (
	"fmt"
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	ret := [][]int{}
	l1 := []*TreeNode{root}
	l2 := []*TreeNode{}
	for len(l1) > 0 {
		row := make([]int, len(l1))
		for i, n := range l1 {
			row[i] = n.Val
			if n.Left != nil {
				l2 = append(l2, n.Left)
			}
			if n.Right != nil {
				l2 = append(l2, n.Right)
			}
		}
		l1 = l2
		l2 = []*TreeNode{}
		ret = append(ret, row)
	}
	return ret
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
		if n == nil {
			continue
		}
		l := 2*i + 1
		r := 2 * (i + 1)
		if l < len(vals) {
			n.Left = nodes[l]
		}
		if r < len(vals) {
			n.Right = nodes[r]
		}
	}
	return nodes[0]
}

func TestCase(t *testing.T) {
	tree := makeTree([]int{1, 2, 3})
	fmt.Println(levelOrder(tree))
	tree = makeTree([]int{1, 2, 3, 7, 0, 5, 6})
	fmt.Println(levelOrder(tree))
}
