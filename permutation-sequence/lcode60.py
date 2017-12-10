import unittest

class Solution(object):
    def __init__(self):
        self.factorial = [1] * 10
        for i in range(1, 10):
            self.factorial[i] = i * self.factorial[i - 1]
        self.digits = []

    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        k -= 1
        self.digits = []
        for i in range(1, n + 1):
            self.digits.append(chr(ord('0') + i))
        
        ret = ""
        for i in range(n, 0, -1):
            idx = k / self.factorial[i - 1]
            k -= idx * self.factorial[i - 1]
            # idx -= 1
                
            print k, self.factorial[i - 1], idx, self.digits
            ret += self.digits[idx]
            del self.digits[idx]
            
        return ret


class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        print s.getPermutation(4, 5)
        print s.getPermutation(3, 2)
        print s.getPermutation(9, 1)
        print s.getPermutation(2, 1)
        print s.getPermutation(2, 2)
        print s.getPermutation(3, 2)
        print s.getPermutation(3, 3)
        
def main():
    unittest.main()

if __name__ == '__main__':
    main()