import unittest

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        ret = ""
        if numRows <= 1:
            return s
        step = 2 * numRows - 2
        half = step / 2
        size = len(s)
        for i in range(0, half + 1):
            start = 0
            while start < size:
                j = step - i
                if j >= step or j == i:
                    j = 0
                idx1 = i + start
                if idx1 >= size:
                    break
                ret += s[idx1]
                if j != 0:
                    idx2 = j + start
                    if idx2 < size:
                        ret += s[idx2]
                start += step
            # print ret
        return ret

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR")
        self.assertEqual(s.convert("PAYPALISHIRING", 1), "PAYPALISHIRING")
        self.assertEqual(s.convert("PAYPALISHIRING", 2), "PAYPALISHIRING")
def main():
    unittest.main()

if __name__ == '__main__':
    main()