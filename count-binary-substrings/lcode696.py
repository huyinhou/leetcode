import unittest

class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        total = 0
        size = len(s)
        prevcnt = 0
        currcnt = 0
        i = 0
        while i < size:
            j = i
            while j < size:
                if s[i] != s[j]:
                    break
                j += 1
            currcnt = j - i
            total += min([prevcnt, currcnt])
            prevcnt = currcnt
            i = j
        return total

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(6, s.countBinarySubstrings("00110011"))
        self.assertEqual(4, s.countBinarySubstrings("10101"))
        self.assertEqual(0, s.countBinarySubstrings("1"))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()