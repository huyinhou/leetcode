package lcode515

import (
	"fmt"
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func largestValues(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	level := []*TreeNode{root}
	retval := []int{}
	for len(level) > 0 {
		temp := []*TreeNode{}
		maxv := level[0].Val
		for _, n := range level {
			if n.Val > maxv {
				maxv = n.Val
			}
			if n.Left != nil {
				temp = append(temp, n.Left)
			}
			if n.Right != nil {
				temp = append(temp, n.Right)
			}
		}
		retval = append(retval, maxv)
		level = temp
	}
	return retval
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
	tree := makeTree([]int{1, 3, 2, 5, 3, 0, 9})
	fmt.Println(largestValues(tree))
}
