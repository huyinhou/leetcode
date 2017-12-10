import unittest

class Solution(object):
    def binarySearch(self, nums, target):
        first = 0
        last = len(nums)
        half = (first + last) / 2
        while first < last:
            if target == nums[half]:
                return half
            if target < nums[half]:
                last = half
            else:
                first = half + 1
            half = (first + last) / 2
        return -1

    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        index = self.binarySearch(nums, target)
        if index == -1:
            return [-1, -1]
        left = index
        while True:
            temp = self.binarySearch(nums[0:left], target)
            if temp != -1:
                left = temp
            else:
                break
        right = index
        while True:
            temp = self.binarySearch(nums[right + 1:], target)
            if temp != -1:
                right = right + 1 + temp
            else:
                break
        return [left, right]

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual([0, 0], s.searchRange([1, 2, 3], 1))
        self.assertEqual([2, 2], s.searchRange([1, 2, 3], 3))
        self.assertEqual([-1, -1], s.searchRange([1], 0))
        self.assertEqual([-1, -1], s.searchRange([1, 2, 4], 3))
        self.assertEqual([2, 5], s.searchRange([0, 1, 2, 2, 2, 2, 4], 2))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()