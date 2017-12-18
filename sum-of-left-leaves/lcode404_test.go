package lcode404

import "testing"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isLeaf(node *TreeNode) bool {
	return node.Left == nil && node.Right == nil
}

func sumOfLeftLeaves(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if isLeaf(root) {
		return 0
	}
	sum := 0
	if root.Left != nil {
		if isLeaf(root.Left) {
			sum += root.Left.Val
		} else {
			sum += sumOfLeftLeaves(root.Left)
		}
	}
	if root.Right != nil {
		if !isLeaf(root.Right) {
			sum += sumOfLeftLeaves(root.Right)
		}
	}
	return sum
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
	if sumOfLeftLeaves(tree) != 24 {
		t.Error(1)
	}
	tree = makeTree([]int{3, 0, 20, 0, 0, 15, 0})
	if sumOfLeftLeaves(tree) != 15 {
		t.Error(2)
	}
}
