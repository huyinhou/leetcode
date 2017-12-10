package lcode508

import (
	"fmt"
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func calcSubTreeSum(root *TreeNode, sum map[int]int) int {
	if root == nil {
		return 0
	}
	l := 0
	if root.Left != nil {
		l = calcSubTreeSum(root.Left, sum)
	}
	r := 0
	if root.Right != nil {
		r = calcSubTreeSum(root.Right, sum)
	}
	tmp := l + r + root.Val
	// fmt.Println(tmp)
	sum[tmp] += 1
	return tmp
}

func findFrequentTreeSum(root *TreeNode) []int {
	summap := make(map[int]int)
	calcSubTreeSum(root, summap)
	max, data := 0, make([]int, 0)
	for k, v := range summap {
		if v > max {
			data = make([]int, 1)
			data[0] = k
			max = v
		} else if v == max {
			data = append(data, k)
		}
	}
	// fmt.Println(summap)
	return data
}

func makeTree(vals []int) *TreeNode {
	nodes := make([]*TreeNode, len(vals))
	for i := len(vals) - 1; i >= 0; i-- {
		n := &TreeNode{
			Val: vals[i],
		}
		l := 2*i + 1
		if l < len(vals) {
			n.Left = nodes[l]
		}
		r := 2 * (i + 1)
		if r < len(vals) {
			n.Right = nodes[r]
		}
		nodes[i] = n
	}
	return nodes[0]
}

func Test1(t *testing.T) {
	tree := makeTree([]int{5, 2, -5})
	fmt.Println(findFrequentTreeSum(tree))
	tree = makeTree([]int{5, 2, -3})
	fmt.Println(findFrequentTreeSum(tree))
}
