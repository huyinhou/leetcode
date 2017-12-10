import unittest

class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        size = len(numbers)
        i = 0
        j = size - 1
        while i < j:
            sum = numbers[i] + numbers[j]
            if sum == target:
                return [i + 1, j + 1]
            if sum > target:
                j -= 1
                continue
            i += 1
        return [0, 0]


class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        ret = s.twoSum([1, 3, 7, 8, 12, 17, 22], 24)
        self.assertEqual(ret[0], 3)
        self.assertEqual(ret[1], 6)

if __name__ == '__main__':
    unittest.main()