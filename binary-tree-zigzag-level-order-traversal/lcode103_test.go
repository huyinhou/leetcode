package lcode103

import (
	"fmt"
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	ltor := true
	ret := [][]int{}
	l1 := []*TreeNode{root}
	l2 := []*TreeNode{}
	for len(l1) > 0 {
		row := make([]int, len(l1))
		for i := len(l1) - 1; i >= 0; i-- {
			n := l1[i]
			row[i] = n.Val
			if ltor {
				if n.Right != nil {
					l2 = append(l2, n.Right)
				}
				if n.Left != nil {
					l2 = append(l2, n.Left)
				}
			} else {
				if n.Left != nil {
					l2 = append(l2, n.Left)
				}
				if n.Right != nil {
					l2 = append(l2, n.Right)
				}
			}
		}
		ret = append(ret, row)
		l1 = l2
		l2 = []*TreeNode{}
		ltor = !ltor
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

func TestCase1(t *testing.T) {
	tree := makeTree([]int{1, 2, 3})
	fmt.Println(zigzagLevelOrder(tree))
	tree = makeTree([]int{1, 2, 3, 4, 0, 5, 6})
	fmt.Println(zigzagLevelOrder(tree))
	tree = makeTree([]int{1, 2, 3, 4, 5, 0, 6, 7, 9, 6, 0, 7})
	fmt.Println(zigzagLevelOrder(tree))
}
