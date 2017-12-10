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

    def findPivotPos(self, nums):
        first = 0
        last = len(nums)
        half = (first + last) / 2
        while first < last:
            if half == 0:
                half = 1
            if nums[half] < nums[half - 1]:
                return half
            if nums[half] < nums[last - 1]:
                last = half
            elif nums[half] > nums[first]:
                first = half
            half = (first + last) / 2
        return -1

    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        size = len(nums)
        if size <= 0:
            return -1
        if nums[size - 1] >= nums[0] :
            return self.binarySearch(nums, target)
        idx = self.findPivotPos(nums)
        if target == nums[0]:
            return 0
        print nums, idx
        if target > nums[0]:
            return self.binarySearch(nums[0:idx], target)
        index = self.binarySearch(nums[idx:], target)
        if index == -1:
            return -1
        return index + idx

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(0, s.binarySearch([1,], 1))
        self.assertEqual(-1, s.binarySearch([1,], 2))
        self.assertEqual(1, s.binarySearch([1, 2], 2))
        self.assertEqual(2, s.binarySearch([1, 2, 3, 4, 5], 3))
        
    def test_2(self):
        s = Solution()
        self.assertEqual(1, s.findPivotPos([2, 1]))
        self.assertEqual(1, s.findPivotPos([10, 1, 2, 3]))
        self.assertEqual(1, s.findPivotPos([10, 1, 2]))
        self.assertEqual(3, s.findPivotPos([7, 8, 9, 6]))
        self.assertEqual(4, s.findPivotPos([7, 8, 9, 10, 6]))

    def test_3(self):
        s = Solution()
        self.assertEqual(s.search([4, 5, 6, 7, 0, 1, 2], 6), 2)
        self.assertEqual(s.search([4, 5, 6, 7, 0, 1, 2], 1), 5)
        self.assertEqual(s.search([], 1), -1)
        self.assertEqual(s.search([10], 1), -1)
        self.assertEqual(s.search([1], 1), 0)
        self.assertEqual(s.search([3, 1], 0), -1)

def main():
    unittest.main()

if __name__ == '__main__':
    main()