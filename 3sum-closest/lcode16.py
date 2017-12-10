
import unittest

class Solution(object):
    def twoSumClosest(self, nums, target):
        size = len(nums)
        i = 0
        j = size - 1
        retval = [nums[i], nums[j]]
        closest = abs(sum(retval) - target)
        if closest == 0:
            return retval, closest

        while i < j:
            tmpv = [nums[i], nums[j]]
            tmps = sum(tmpv)
            tmpc = abs(tmps - target)
            if tmpc == 0:
                return tmpv, tmpc
            if tmpc < closest:
                closest = tmpc
                retval = tmpv
            if tmps < target:
                i += 1
            elif tmps > target:
                j -= 1
        return retval, closest

    def uniqueNumbers(self, nums):
        i = 0
        while i < len(nums):
            j = i + 3
            if j >= len(nums):
                break
            while j < len(nums):
                if nums[i] == nums[j]:
                    del nums[j]
                else:
                    break
            i += 1

    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        self.uniqueNumbers(nums)
        # print(nums)
        i = 0
        retval = [nums[0], nums[1], nums[2]]
        closest = abs(sum(retval) - target)
        if closest == 0:
            return sum(retval)

        size = len(nums)
        while i < size - 2:
            # print i
            tmpv, tmpc = self.twoSumClosest(nums[i + 1:], target - nums[i])
            print tmpc, closest
            if tmpc > closest:
                i += 1
                continue
            
            retval = [nums[i],]
            retval.extend(tmpv)
            if tmpc == 0:
                return sum(retval)
            if tmpc < closest:
                closest = tmpc
            i += 1
        return sum(retval)

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        self.assertEqual(s.threeSumClosest([-1, 2, 1, -4], 1), 2)
        self.assertEqual(s.threeSumClosest([0, 0, 0], 1), 0)
        self.assertEqual(s.threeSumClosest([1, 1, 1, 0], -100), 2)
        self.assertEqual(s.threeSumClosest([1, 1, -1, -1, 3], 1), 1)
def main():
    unittest.main()

if __name__ == '__main__':
    main()