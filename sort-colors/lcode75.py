import unittest

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        if size <= 1:
            return
        idx0 = 0
        idx2 = size - 1
        i = 0
        while i < size:
            # print i, idx0, idx2, nums[i]
            if nums[i] == 0 and i > idx0:
                nums[i], nums[idx0] = nums[idx0], nums[i]
                idx0 += 1
                continue
            if nums[i] == 2 and i < idx2:
                nums[i], nums[idx2] = nums[idx2], nums[i]
                idx2 -= 1
                continue
            i += 1

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        nums = [1, 2, 0, 0, 1, 2, 0]
        s.sortColors(nums)
        print nums
        nums = [1]
        s.sortColors(nums)
        print nums

        nums = []
        s.sortColors(nums)
        print nums

        nums = [1, 1, 1, 1, 1]
        s.sortColors(nums)
        print nums

        nums = [0, 0, 0, 2, 2]
        s.sortColors(nums)
        print nums

def main():
    unittest.main()

if __name__ == '__main__':
    main()