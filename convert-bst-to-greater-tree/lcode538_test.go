package lcode538

import "testing"
import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func backOrder(root *TreeNode, sum *int) {
	if root.Right != nil {
		backOrder(root.Right, sum)
	}
	tmp := root.Val + *sum
	root.Val, *sum = tmp, tmp
	if root.Left != nil {
		backOrder(root.Left, sum)
	}
}

func convertBST(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	sum := 0
	backOrder(root, &sum)
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

func inorder(root *TreeNode, vals *[]int) {
	if root.Left != nil {
		inorder(root.Left, vals)
	}
	*vals = append(*vals, root.Val)
	if root.Right != nil {
		inorder(root.Right, vals)
	}
}
func Test1(t *testing.T) {
	tree := makeTree([]int{5, 2, 8})
	convertBST(tree)
	var vals []int
	inorder(tree, &vals)
	fmt.Println(vals)

	tree = makeTree([]int{5, 3, 8, 0, 4, 7, 9})
	convertBST(tree)
	vals = nil
	inorder(tree, &vals)
	fmt.Println(vals)
}
