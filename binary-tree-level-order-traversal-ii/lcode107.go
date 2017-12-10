package lcode107

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrderBottom(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	result := [][]int{}
	parent := []*TreeNode{root}
	child := []*TreeNode{}
	size := 1
	for size > 0 {
		vals := []int{}
		fmt.Println(size)
		for i := 0; i < size; i++ {
			node := parent[i]
			fmt.Println(node)
			vals = append(vals, node.Val)
			if node.Left != nil {
				child = append(child, node.Left)
			}
			if node.Right != nil {
				child = append(child, node.Right)
			}
		}
		fmt.Println(vals)
		result = append(result, vals)
		parent = child
		size = len(parent)
		child = []*TreeNode{}
	}
	reverse := [][]int{}
	for i := len(result) - 1; i >= 0; i-- {
		reverse = append(reverse, result[i])
	}
	return reverse
}
