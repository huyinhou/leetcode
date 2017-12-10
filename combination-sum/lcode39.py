import unittest

class Solution(object):
    def combinationSumSorted(self, candidates, target):
        retval = []
        # print candidates, target
        for i in range(len(candidates)):
            val = candidates[i]
            if val > target:
                break
            if target == val:
                retval.append([val, ])
                break
            # repeat
            subret = self.combinationSumSorted(candidates[i:], target - val)
            for temp in subret:
                temp.insert(0, val)
            retval.extend(subret)
        return retval

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        return self.combinationSumSorted(candidates, target)

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        ret = s.combinationSum([2, 3, 6, 7], 7)
        print ret
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()