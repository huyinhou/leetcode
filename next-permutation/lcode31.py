import unittest

class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        i = size - 2
        while i >= 0:
            if nums[i] < nums[i+1]:
                break
            i -= 1

        j = i + 1
        if i >= 0:
            while j < size:
                if nums[j] > nums[i]:
                    j += 1
                else:
                    break
            j -= 1
            nums[i], nums[j] = nums[j], nums[i]
            
        i += 1
        j = size - 1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        vals = [1, 2, 3]
        s.nextPermutation(vals)
        print vals
        vals = [1, 3, 2]
        s.nextPermutation(vals)
        print vals
        vals = [1, 1, 5]
        s.nextPermutation(vals)
        print vals
        vals = [3, 2, 1]
        s.nextPermutation(vals)
        print vals
def main():
    unittest.main()

if __name__ == '__main__':
    main()