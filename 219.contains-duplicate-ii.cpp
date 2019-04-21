/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (34.79%)
 * Total Accepted:    185.9K
 * Total Submissions: 534.5K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * 
 * 
 */

#include <vector>
#include <map>
#include <cmath>
using std::vector;
using std::map;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> nmap;
        for (size_t i = 0; i < nums.size(); i++) {
            map<int, int>::iterator it = nmap.find(nums[i]);
            if (it != nmap.end()) {
                if (i - it->second <= k) {
                    return true;
                }
            }
            nmap[nums[i]] = i;
        }
        return false;
    }
};

// #define LEETEST
#ifdef LEETEST
#include <cassert>

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> a = {1, 2, 3, 1};
    assert(s.containsNearbyDuplicate(a, 3));

    vector<int> b = {1,2,3,1,2,3};
    assert(!s.containsNearbyDuplicate(b, 2));
    return 0;
}
#endif

