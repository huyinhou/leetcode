/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (47.66%)
 * Total Accepted:    252.4K
 * Total Submissions: 529.5K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
#include <vector>
#include <algorithm>
using std::vector;
using std::for_each;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int remain = n * (n + 1) / 2;
        for_each(nums.begin(), nums.end(), [&remain](int n) {
            remain -= n;
        });
        return remain;
    }
};

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 3};
    assert(s.missingNumber(nums) == 0);
    nums[0] = 0;
    assert(s.missingNumber(nums) == 1);
    return 0;
}
#endif
