import unittest

class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        bits = [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4]
        total = 0
        while n > 0:
            total += bits[n & 15]
            n >>= 4
        return total

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(0, s.hammingWeight(0))
        self.assertEqual(1, s.hammingWeight(2))
        self.assertEqual(4, s.hammingWeight(15))
        self.assertEqual(3, s.hammingWeight(11))

def main():
    unittest.main()

if __name__ == '__main__':
    main()