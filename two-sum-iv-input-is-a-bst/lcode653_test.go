package lcode653

import (
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorder(root *TreeNode, vals *[]int) {
	if root.Left != nil {
		inorder(root.Left, vals)
	}
	*vals = append(*vals, root.Val)
	if root.Right != nil {
		inorder(root.Right, vals)
	}
}

func findTarget(root *TreeNode, k int) bool {
	if root == nil {
		return false
	}
	var vals []int
	inorder(root, &vals)
	// fmt.Println(vals)
	i, j := 0, len(vals)-1
	for i < j {
		sum := vals[i] + vals[j]
		if sum == k {
			return true
		}
		if sum > k {
			j--
		} else {
			i++
		}
	}
	return false
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
	tree := makeTree([]int{5, 3, 6, 2, 4, 0, 7})
	if !findTarget(tree, 9) {
		t.Error(1)
	}
	if findTarget(tree, 14) {
		t.Error(2)
	}
}
