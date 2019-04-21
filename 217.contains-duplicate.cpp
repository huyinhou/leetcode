/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (51.00%)
 * Total Accepted:    307.9K
 * Total Submissions: 603.8K
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an array of integers, find if the array contains any duplicates.
 * 
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 */
#include <vector>
#include <map>
using std::vector;
using std::map;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> nmap;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nmap.find(nums[i]) != nmap.end()) {
                return true;
            }
            nmap[nums[i]] = 1;
        }
        return false;
    }
};

// #define LEETEST
#ifdef LEETEST
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> a = {1, 2, 3, 4, 1};
    assert(s.containsDuplicate(a));
    a.pop_back();
    assert(!s.containsDuplicate(a));
    return 0;
}
#endif
