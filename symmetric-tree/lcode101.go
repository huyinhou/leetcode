package lcode101

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	parent := []*TreeNode{root}
	child := []*TreeNode{}
	size := 1
	for size > 0 {
		for i, j := 0, size-1; i <= size/2; i, j = i+1, j-1 {
			if parent[i] == parent[j] {
				continue
			}
			if parent[i] == nil || parent[j] == nil {
				// fmt.Printf("%v %v \n", parent[i], parent[j])
				return false
			}
			if parent[i].Val != parent[j].Val {
				// fmt.Printf("left=%d, right=%d", parent[i].Val, parent[j].Val)
				return false
			}
		}

		for i := 0; i < size; i++ {
			node := parent[i]
			if node != nil {
				child = append(child, node.Left, node.Right)
			}
		}
		parent = child
		child = []*TreeNode{}
		size = len(parent)
	}
	return true
}
