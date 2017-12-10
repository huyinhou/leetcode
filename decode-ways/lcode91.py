
import unittest

class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        size = len(s)
        count = [0] * (size + 1)
        count[size] = 1
        if size == 0:
            return 0
        c = s[size - 1]
        if c == '0':
            count[size - 1] = 0
        else:
            count[size - 1] = 1
        

        for idx in range(size - 2, -1, -1):
            c = s[idx]
            if c >= '3':
                count[idx] = count[idx + 1]
            elif c == '2':
                c2 = s[idx + 1]
                if c2 > '6':
                    count[idx] = count[idx + 1]
                else:
                    count[idx] = count[idx + 1] + count[idx + 2]
            elif c == '1':
                count[idx] = count[idx + 1] + count[idx + 2]
            else:
                count[idx] = 0
                # return 0

        return count[0]


class TestSolution(unittest.TestCase):
    def test1(self):
        s = Solution()
        ret = s.numDecodings("12")
        self.assertEqual(2, ret)
        ret = s.numDecodings("1")
        self.assertEqual(1, ret)
        ret = s.numDecodings("123")
        self.assertEqual(3, ret)
        ret = s.numDecodings("")
        self.assertEqual(0, ret)
        ret = s.numDecodings("120")
        self.assertEqual(1, ret)
        ret = s.numDecodings("211200")
        self.assertEqual(0, ret)
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()