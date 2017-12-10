import unittest

class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        reverse = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
        num = 0
        for i in range(1, 9):
            num = (num << 4) + reverse[n & 15]
            n >>= 4
        return num

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(964176192, s.reverseBits(43261596))

def main():
    unittest.main()

if __name__ == '__main__':
    main()