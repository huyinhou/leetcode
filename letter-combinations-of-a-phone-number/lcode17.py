import unittest

class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        numlist = ["0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        ndigits = len(digits)
        if ndigits == 0:
            return []

        maplist = [""] * ndigits
        maplen = [0] * ndigits
        total = 1
        for i in range(0, ndigits):
            maplist[i] = numlist[ord(digits[i]) - ord('0')]
            maplen[i] = len(maplist[i])
            total *= maplen[i]
        retval = [""] * total
        idxlist = [0] * ndigits
        index = 0
        # print total
        while True:
            # print index
            for i in range(0, ndigits):
                retval[index] += maplist[i][idxlist[i]]
            index += 1
            carry = 0
            for i in range(ndigits - 1, -1, -1):
                idxlist[i] += 1
                if idxlist[i] == maplen[i]:
                    idxlist[i] = 0
                    carry = 1
                else:
                    carry = 0
                if carry == 0:
                    break
            if carry == 1:
                break
        return retval

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        print s.letterCombinations("111")
        print s.letterCombinations("235")
        print s.letterCombinations("23")
        print s.letterCombinations("1906")
        print s.letterCombinations("3")
def main():
    unittest.main()

if __name__ == '__main__':
    main()