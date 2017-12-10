import unittest

class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        v = 0
        h = 0
        for c in moves:
            if c == 'U':
                v += 1
            elif c == 'D':
                v -= 1
            elif c == 'L':
                h -= 1
            elif c == 'R':
                h += 1
        return h == 0 and v == 0

class TestSolution(unittest.TestCase):
    def test1(self):
        s = Solution()
        self.assertTrue(s.judgeCircle("UD"))
        self.assertTrue(s.judgeCircle("LR"))
        self.assertTrue(s.judgeCircle("ULDR"))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()
