package lcode226

import (
	"fmt"
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
	if root != nil {
		root.Left, root.Right = root.Right, root.Left
		if root.Left != nil {
			invertTree(root.Left)
		}
		if root.Right != nil {
			invertTree(root.Right)
		}
	}
	return root
}

func makeTree(vals []int) *TreeNode {
	vlen := len(vals)
	nodes := make([]*TreeNode, vlen)
	for i := vlen - 1; i >= 0; i-- {
		n := &TreeNode{
			Val: vals[i],
		}
		l, r := 2*i+1, 2*(i+1)
		if l < vlen {
			n.Left = nodes[l]
		}
		if r < vlen {
			n.Right = nodes[r]
		}
		nodes[i] = n
	}
	return nodes[0]
}

func dumpTree(root *TreeNode) []int {
	nodes := make([]*TreeNode, 1)
	nodes[0] = root
	for i := 0; i < len(nodes); i++ {
		n := nodes[i]
		if n.Left != nil {
			nodes = append(nodes, n.Left)
		}
		if n.Right != nil {
			nodes = append(nodes, n.Right)
		}
	}
	vals := make([]int, len(nodes))
	for i := 0; i < len(nodes); i++ {
		vals[i] = nodes[i].Val
	}
	return vals
}

func Test1(t *testing.T) {
	tree := makeTree([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13})
	fmt.Println(dumpTree(tree))
	invertTree(tree)
	fmt.Println(dumpTree(tree))
}
