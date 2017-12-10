package lcode18

import "testing"
import "sort"

func delSame(nums []int, step int) []int {
	size := len(nums)
	for i := 0; i < size; i++ {
		j := i + step
		for j < size {
			if nums[i] == nums[j] {
				nums = append(nums[0:j], nums[j+1:]...)
				size--
			} else {
				break
			}
		}
	}
	return nums
}

func twoSum(nums []int, target int) [][]int {
	// fmt.Println("twosum", nums, target)
	i := 0
	j := len(nums) - 1
	retval := [][]int{}
	for i < j {
		sum := nums[i] + nums[j]
		if sum > target {
			j--
		} else if sum < target {
			i++
		} else {
			retval = append(retval, []int{nums[i], nums[j]})
			i++
			j--
			for i <= j && nums[i] == nums[i-1] {
				i++
			}
			for i <= j && nums[j] == nums[j+1] {
				j--
			}
			if i >= j {
				break
			}
		}
	}
	return retval
}

func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	// fmt.Println(nums)
	nums = delSame(nums, 4)
	// fmt.Println(nums)

	size := len(nums)
	retval := [][]int{}
	for i := 0; i < size-3; i++ {
		if i > 0 &&
			nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < size-2; j++ {
			if j > i+1 &&
				nums[j] == nums[j-1] {
				continue
			}
			sum := nums[i] + nums[j]
			two := twoSum(nums[j+1:], target-sum)
			if len(two) > 0 {
				for k := 0; k < len(two); k++ {
					temp := append([]int{nums[i], nums[j]}, two[k]...)
					retval = append(retval, temp)
				}
			}
		}
	}
	return retval
}

func TestCase2(t *testing.T) {
	ret := delSame([]int{1, 1, 1, 1, 1, 1, 1}, 1)
	t.Log(ret)
	if len(ret) != 1 {
		t.Error(4)
	}
	ret = delSame([]int{1, 1, 1, 1, 1, 2, 2, 2, 2, 2}, 3)
	t.Log(ret)
	if len(ret) != 6 {
		t.Error(5)
	}
}

func TestCase3(t *testing.T) {
	ret := twoSum([]int{1, 2, 3, 4, 5, 6, 7, 8}, 8)
	t.Log(ret)
	if len(ret) != 3 {
		t.Error(6)
	}

	ret = twoSum([]int{1, 2, 2, 3, 4, 5, 6, 6, 6, 7, 8}, 8)
	t.Log(ret)
	if len(ret) != 3 {
		t.Error(6)
	}
}

func TestCase4(t *testing.T) {
	ret := fourSum([]int{1, 0, -1, 0, -2, 2}, 0)
	t.Log(ret)
	if len(ret) != 3 {
		t.Error(ret)
	}
	ret = fourSum([]int{-3, -2, -1, 0, 0, 1, 2, 3}, 0)
	t.Log(ret)
	if len(ret) != 8 {
		t.Error(ret)
	}
	ret = fourSum([]int{-5, -4, -3, -2, -1, 0, 0, 1, 2, 3, 4, 5}, 0)
	t.Log(ret)
	if len(ret) != 29 {
		t.Error(10)
	}
	ret = fourSum([]int{-5, -5, -5, -5, -4, -3, -2, -1, 0, 0, 1, 2, 3, 4, 5}, 0)
	t.Log(ret)
	if len(ret) != 29 {
		t.Error(11)
	}
}
