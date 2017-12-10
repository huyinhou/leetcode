import unittest

class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        # print num1, num2
        digitsmap = "0123456789"
        result = 0
        len1 = len(num1)
        len2 = len(num2)
        digits = [0] * (len1 + len2 + 2)
        for i in range(len1 - 1, -1, -1):
            d1 = ord(num1[i]) - ord('0')
            if d1 == 0:
                continue
            for j in range(len2 - 1, -1, -1):
                d2 = ord(num2[j]) - ord('0')
                if d2 == 0:
                    continue
                offset = len1 + len2 - i - j - 2
                d = d1 * d2
                tmp = [d % 10, d / 10]
                # print tmp
                flag = 0
                for k in range(2):
                    d = digits[offset] + tmp[k] + flag
                    if d >= 10:
                        digits[offset] = d-10
                        flag = 1
                    else:
                        digits[offset] = d
                        flag = 0
                    offset += 1
                
                while flag != 0:
                    d = digits[offset] + flag
                    if d >= 10:
                        digits[offset] = d - 10
                        flag = 1
                    else:
                        digits[offset] = d
                        flag = 0
                    offset += 1
        i = len(digits) - 1
        while i > 0 and digits[i] == 0:
            i -= 1

        result = ""
        while i >= 0:
            result += digitsmap[digits[i]]
            i -= 1
        return result

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        for a in range(1110):
            for b in range(111):
                self.assertEqual("%d" % (a * b), s.multiply("%d" % a, "%d" % b))
            #for b in range(111):
                
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()