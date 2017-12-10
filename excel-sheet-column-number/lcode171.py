import unittest

class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        num = 0
        for c in s:
            n = ord(c) - 64
            num = num * 26 + n
        return num

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(1, s.titleToNumber("A"))
        self.assertEqual(26, s.titleToNumber("Z"))
        self.assertEqual(27, s.titleToNumber("AA"))


def main():
    unittest.main()

if __name__ == '__main__':
    main()