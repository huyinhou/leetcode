import unittest

class Solution(object):
    def __init__(self):
        self.counts = None

    def numTreesDP(self, n):
        if self.counts[n] != 0:
            return self.counts[n]
        left = 0
        right = n - 1
        sum = 0
        for i in range(1, n + 1):
            sum += self.numTreesDP(left) * self.numTreesDP(right)
            left += 1
            right -= 1
        self.counts[n] = sum
        return sum

    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        # if self.counts is None:
        self.counts = [0] * (n + 1)
        self.counts[0] = 1
        # print n, self.counts
        return self.numTreesDP(n)

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(1, s.numTrees(0))
        print s.counts
        self.assertEqual(1, s.numTrees(1))
        print s.counts
        self.assertEqual(2, s.numTrees(2))
        print s.counts
        self.assertEqual(5, s.numTrees(3))
        print s.counts
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()