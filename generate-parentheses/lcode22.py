import unittest

class Solution(object):
    def __init__(self):
        self.result = []

    def generate(self, base, left, right):
        if left > 0:
            self.generate(base + '(', left - 1, right)
        if right > left:
            self.generate(base + ')', left, right-1)
        if right == 0:
            self.result.append(base)
    
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.result = []
        self.generate("", n, n)
        return self.result

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        ret = s.generateParenthesis(1)
        print ret

        ret = s.generateParenthesis(2)
        print ret

        ret = s.generateParenthesis(3)
        print ret

def main():
    unittest.main()

if __name__ == '__main__':
    main()