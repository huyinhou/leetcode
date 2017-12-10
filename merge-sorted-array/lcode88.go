package lcode88

// https://leetcode.com/problems/merge-sorted-array/description/

func merge(nums1 []int, m int, nums2 []int, n int) {
	for i := 0; i < n; i++ {
		nums1[m+i] = nums2[i]
	}
	if m == 0 || n == 0 {
		return
	}
	i, j := m-1, n-1
	last := m + n - 1
	for i >= 0 && j >= 0 {
		if nums1[i] > nums2[j] {
			nums1[last] = nums1[i]
			i--
		} else {
			nums1[last] = nums2[j]
			j--
		}
		last--
	}

	for j >= 0 {
		nums1[last] = nums2[j]
		last--
		j--
	}
}
