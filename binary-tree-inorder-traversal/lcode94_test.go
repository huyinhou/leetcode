package lcode94

import "testing"
import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
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

func inorderTraversal(root *TreeNode) []int {
	var stack []*TreeNode
	var retval []int
	for {
		if root != nil {
			stack = append(stack, root)
			// fmt.Println(root.Val)
			root = root.Left
			continue
		}
		nlen := len(stack)
		if nlen == 0 {
			break
		}
		root = stack[nlen-1]
		stack = stack[:nlen-1]
		retval = append(retval, root.Val)
		root = root.Right
	}
	return retval
}

func TestCase1(t *testing.T) {
	tree := makeTree([]int{1, 2, 3, 0, 5})
	ret := inorderTraversal(tree)
	fmt.Println(ret)

	tree = makeTree([]int{1, 0, 3, 0, 0, 4, 5})
	ret = inorderTraversal(tree)
	fmt.Println(ret)

	tree = makeTree([]int{1, 2, 3, 0, 4, 5, 0})
	ret = inorderTraversal(tree)
	fmt.Println(ret)

	// tree = makeTree(nil)
	ret = inorderTraversal(nil)
	fmt.Println(ret)
}
