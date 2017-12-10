package lcode637

import (
	"fmt"
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func averageOfLevels(root *TreeNode) []float64 {
	if root == nil {
		return []float64{}
	}
	level := []*TreeNode{root}
	retval := []float64{}
	for len(level) > 0 {
		temp := []*TreeNode{}
		var total float64
		for _, n := range level {
			total += float64(n.Val)
			if n.Left != nil {
				temp = append(temp, n.Left)
			}
			if n.Right != nil {
				temp = append(temp, n.Right)
			}
		}
		retval = append(retval, total/float64(len(level)))
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
	tree := makeTree([]int{3, 9, 20, 0, 0, 15, 7})
	fmt.Println(averageOfLevels(tree))
}
