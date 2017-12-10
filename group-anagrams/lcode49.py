import unittest

class Solution(object):
    def hashKey(self, val):
        count = [0] * 26
        a = ord('a')
        for c in val:
            count[ord(c) - a] += 1
        key = ""
        for i in range(26):
            key += "/%d" % count[i]
        return key

    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        valhash = {}
        for s in strs:
            key = self.hashKey(s)
            if key not in valhash:
                valhash[key] = [s,]
            else:
                valhash[key].append(s)
        return valhash.values()


class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        print s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])

def main():
    unittest.main()

if __name__ == '__main__':
    main()