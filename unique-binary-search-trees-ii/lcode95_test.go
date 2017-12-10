package lcode95

import (
	"fmt"
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func generateTreesByArray(arr []int) []*TreeNode {
	var retval []*TreeNode
	// fmt.Println(arr)
	for i, v := range arr {
		left := generateTreesByArray(arr[0:i])
		right := generateTreesByArray(arr[i+1:])
		// fmt.Println(v, len(left), len(right))
		for _, l := range left {
			for _, r := range right {
				root := &TreeNode{
					Val:   v,
					Left:  l,
					Right: r,
				}
				retval = append(retval, root)
			}
		}
	}
	if len(retval) == 0 {
		retval = append(retval, nil)
	}
	return retval
}

func generateTrees(n int) []*TreeNode {
	if n <= 0 {
		return []*TreeNode{}
	}
	arr := make([]int, n)
	for i := 1; i <= n; i++ {
		arr[i-1] = i
	}

	return generateTreesByArray(arr)
}

func inorder(root *TreeNode, arr *[]int) {
	if root.Left != nil {
		inorder(root.Left, arr)
	}
	*arr = append(*arr, root.Val)
	if root.Right != nil {
		inorder(root.Right, arr)
	}
}
func dlr(root *TreeNode, arr *[]int) {
	*arr = append(*arr, root.Val)
	if root.Left != nil {
		dlr(root.Left, arr)
	}
	if root.Right != nil {
		dlr(root.Right, arr)
	}
}

func TestCase1(t *testing.T) {
	ret := generateTrees(3)
	for _, v := range ret {
		arr := make([]int, 0, 3)
		dlr(v, &arr)
		fmt.Println(arr)
	}
	ret = generateTrees(0)
	fmt.Println(ret)
}
