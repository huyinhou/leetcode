import unittest

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = 0
        pos = -1
        size = len(nums)
        for i in range(size):
            if pos < 0 or nums[i] == nums[pos]:
                if cnt == 2:
                    continue
                cnt += 1
            else:
                cnt = 1

            pos += 1
            if i > pos:
                nums[pos] = nums[i]
        return pos + 1

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        nums = [1, 1, 1, 1, 2, 2, 2, 3, 3, 4]
        tlen = s.removeDuplicates(nums)
        print nums[0:tlen]

        nums = [1, 2, 2, 2, 2, 3, 3, 4]
        tlen = s.removeDuplicates(nums)
        print nums[0:tlen]

        nums = [2, 3, 4, 5]
        tlen = s.removeDuplicates(nums)
        print nums[0:tlen]

        nums = [1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4]
        tlen = s.removeDuplicates(nums)
        print nums[0:tlen]
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()