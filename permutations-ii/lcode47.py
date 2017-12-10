import unittest


class Solution(object):
    def __init__(self):
        self.result = []

    def permuteRange(self, nums, first, last):
        if first == last:
            self.result.append(nums[:])
            return
        # print first, last
        numdict = {}
        for idx in range(first, last):
            numdict[nums[idx]] = 1
        for idx in range(first, last):
            if idx == first or nums[idx] in numdict:
                nums[first], nums[idx] = nums[idx], nums[first]
                self.permuteRange(nums, first + 1, last)
                nums[first], nums[idx] = nums[idx], nums[first]
                del numdict[nums[idx]]

    def permuteUnique(self, nums):
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
        print s.permuteUnique([1, 1, 1, 2, 2])
        print s.permuteUnique([1, 1, 2])
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()