import unittest

class Solution(object):
    def combinationSumSorted(self, numlist, numlens, target):
        # print numlist, numlens, target
        retval = []
        for k in range(len(numlist)): 
            total = 0
            prefix = []
            currval = numlist[k]
            if currval > target:
                break
            for i in range(0, numlens[k]):  # first val
                total += currval
                if total > target:
                    break
                prefix.append(currval)
                if total == target:
                    retval.append(prefix[:])
                    break
                subret = self.combinationSumSorted(numlist[k+1:], numlens[k+1:], target-total)
                for v in subret:
                    temp = prefix[:]
                    temp.extend(v)
                    retval.append(temp)
                    
        return retval

    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        if len(candidates) == 0:
            return []

        numlist = [candidates[0],]
        numlens = [1,]
        for i in range(1, len(candidates)):
            if candidates[i] == numlist[-1]:
                numlens[-1] = numlens[-1] + 1
            else:
                numlist.append(candidates[i])
                numlens.append(1)
        # print numlist, numlens
        return self.combinationSumSorted(numlist, numlens, target)

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        print s.combinationSum2([10, 1, 2, 7, 6, 1, 5], 8)
        self.assertEqual([], s.combinationSum2([10], 8))
        self.assertEqual([], s.combinationSum2([], 8))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()