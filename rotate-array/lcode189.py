# -*- coding: utf-8 -*-

import unittest

# 最优结法：
# 1.将整个数组对调
# 2.将前k个元素对调
# 3.将k...n个元素对调
# 证明：
# 总共n个元素，将第i个元素右移k步
# 整个数组反序后变成第n-i个元素
# if n - i < k
#   反序前k个元素后变成： k - (n - i) = k + i - n
# else
#   反序剩余元素后变成：k + (n - k) - (n - i - k) = k + i

class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n
        if k == 0:
            return
        
        start = 0
        temp = nums[start]
        curr = start
        for i in range(0, n):
            next = (curr + k) % n
            temp, nums[next] = nums[next], temp
            curr = next
            if curr == start:
                start += 1
                temp = nums[start]
                curr = start

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        a = [1, 2, 3, 4, 5]
        s.rotate(a, 1)
        self.assertEqual(a, [5, 1, 2, 3, 4])
        a = [1, 2, 3, 4, 5]
        s.rotate(a, 2)
        self.assertEqual(a, [4, 5, 1, 2, 3])
        a = [1, 2, 3, 4, 5]
        s.rotate(a, 5)
        self.assertEqual(a, [1, 2, 3, 4, 5])
        a = [1, 2, 3, 4, 5, 6]
        s.rotate(a, 2)
        self.assertEqual(a, [5, 6, 1, 2, 3, 4])

def main():
    unittest.main()

if __name__ == '__main__':
    main()