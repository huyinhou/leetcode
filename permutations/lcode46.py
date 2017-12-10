import unittest

class Solution(object):
    def __init__(self):
        self.result = []

    def permuteRange(self, nums, first, last):
        if first == last:
            self.result.append(nums[:])
            return
        print first, last
        for idx in range(first, len(nums)):
            if idx > first:
                nums[first], nums[idx] = nums[idx], nums[first]
            self.permuteRange(nums, first + 1, last)
            if idx > first:
                nums[first], nums[idx] = nums[idx], nums[first]

    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.result = []
        self.permuteRange(nums, 0, len(nums))
        return self.result

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        print s.permute([1, 2, 3])
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()