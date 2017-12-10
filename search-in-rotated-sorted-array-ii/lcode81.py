
import unittest

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        size = len(nums)
        idx0 = 0
        idxn = size - 1
        while idx0 <= idxn:
            mid = (idx0 + idxn) / 2
            # print idx0, idxn, mid
            if nums[mid] == target:
                return True
            if nums[idx0] == nums[mid] and \
                nums[idx0] == nums[idxn]:
                idx0 += 1
                idxn -= 1
                # print "a", idx0, idxn
                continue
            if nums[idx0] <= nums[mid]:
                if target >= nums[idx0] and target < nums[mid]:
                    idxn = mid - 1
                else:
                    idx0 = mid + 1
            else:
                if target > nums[mid] and target <= nums[idxn]:
                    idx0 = mid + 1
                else:
                    idxn = mid - 1

        return False

class TestSolution(unittest.TestCase):
    def test_1(self):
        s = Solution()
        # nums = [5, 5, 6, 7, 8, 8, 2, 2, 2, 3, 3, 4, 4, 5, 5]
        # self.assertTrue(s.search(nums, 5))
        # self.assertTrue(s.search(nums, 6))
        # self.assertTrue(s.search(nums, 7))
        # self.assertTrue(s.search(nums, 8))
        # self.assertTrue(s.search(nums, 2))
        # self.assertTrue(s.search(nums, 3))
        # self.assertTrue(s.search(nums, 4))

        nums = [1, 3, 1, 1, 1]
        self.assertTrue(s.search(nums, 1))
        self.assertTrue(s.search(nums, 3))

        self.assertFalse(s.search([], 1))
        pass

def main():
    unittest.main()

if __name__ == '__main__':
    main()