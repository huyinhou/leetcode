package lcode513

import (
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findBottomLeftValue(root *TreeNode) int {
	stack := make([]*TreeNode, 1)
	stack[0] = root
	for len(stack) > 0 {
		temp := make([]*TreeNode, 0)
		for _, n := range stack {
			if n.Left != nil {
				temp = append(temp, n.Left)
			}
			if n.Right != nil {
				temp = append(temp, n.Right)
			}
		}
		if len(temp) == 0 {
			return stack[0].Val
		}
		stack = temp
	}
	return 0
}

func makeTree(vals []int) *TreeNode {
	nlen := len(vals)
	nodes := make([]*TreeNode, nlen)
	for i := 0; i < nlen; i++ {
		if vals[i] != 0 {
			nodes[i] = &TreeNode{
				Val: vals[i],
			}
		}
	}
	for i := 0; i < nlen; i++ {
		if nodes[i] == nil {
			continue
		}
		lidx := 2*i + 1
		ridx := 2 * (i + 1)
		if lidx < nlen {
			nodes[i].Left = nodes[lidx]
		}
		if ridx < nlen {
			nodes[i].Right = nodes[ridx]
		}
	}
	return nodes[0]
}

func Test1(t *testing.T) {
	root := makeTree([]int{1, 2, 3, 4, 0, 5, 7})
	if findBottomLeftValue(root) != 4 {
		t.Error(1)
	}
	root = makeTree([]int{1, 2, 3, 0, 0, 4})
	if findBottomLeftValue(root) != 4 {
		t.Error(2)
	}
}
