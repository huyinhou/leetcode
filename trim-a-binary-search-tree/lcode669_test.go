package lcode669

import "testing"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func trimBST(root *TreeNode, L int, R int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val < L {
		return trimBST(root.Right, L, R)
	}
	if root.Val > R {
		return trimBST(root.Left, L, R)
	}
	root.Left = trimBST(root.Left, L, R)
	root.Right = trimBST(root.Right, L, R)
	return root
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

func compTree(l, r *TreeNode) bool {
	if l == nil {
		if r == nil {
			return true
		}
		return false
	} else if r == nil {
		return false
	}
	if l.Val != r.Val {
		return false
	}
	return compTree(l.Left, r.Left) && compTree(l.Right, r.Right)
}

func Test1(t *testing.T) {
	tree := makeTree([]int{3, 1, 5, -4, 2})
	tree = trimBST(tree, 4, 6)
	t2 := makeTree([]int{5})
	if !compTree(tree, t2) {
		t.Error(1)
	}

}
