import unittest

class Solution(object):
    def twoSum(self, nums, sum):
        i = 0
        j = len(nums) - 1
        ret = []
        while i < j:
            temp = nums[i] + nums[j]
            if temp < sum:
                i += 1
            elif temp > sum:
                j -= 1
            else:
                ret.append([nums[i], nums[j]])
                i += 1
                j -= 1
        # print nums, sum, ret
        return ret

    def uniqueNums(self, nums):
        i = 0
        while i < len(nums):
            j = i + 3
            while j < len(nums):
                if nums[i] != nums[j]:
                    break
                del nums[j]
            i += 1

    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        self.uniqueNums(nums)
        size = len(nums)
        idx = size - 1
        ret = []
        while idx >= 2:
            temp = self.twoSum(nums[0:idx], -nums[idx])
            for val in temp:
                val.append(nums[idx])
            ret.extend(temp)
            idx -= 1
            
        # unique
        i = 0
        while i < len(ret):
            j = i + 1
            while j < len(ret):
                vi = ret[i]
                vj = ret[j]
                if vi[2] != vj[2]:
                    break
                if vi[1] == vj[1] and vi[0] == vj[0]:
                    # del j
                    del ret[j]
                    continue
                j += 1
            i += 1
        return ret

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        print s.threeSum([-2, -1, -1, 0, 1, 2, 2])
        print s.threeSum([-1, 0, 1, 2, -1, -4])
        print s.threeSum([0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0])

def main():
    unittest.main()

if __name__ == '__main__':
    main()