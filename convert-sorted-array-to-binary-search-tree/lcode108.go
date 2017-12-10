package lcode108

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sortedArrayToBST(nums []int) *TreeNode {
	size := len(nums)
	if size == 0 {
		return nil
	}
	half := size / 2
	node := &TreeNode{
		Val: nums[half],
	}
	if half > 0 {
		node.Left = sortedArrayToBST(nums[0:half])
	}
	half++
	if half < size {
		node.Right = sortedArrayToBST(nums[half:])
	}
	return node
}
