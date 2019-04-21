/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (46.90%)
 * Total Accepted:    182.5K
 * Total Submissions: 389.1K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
using std::string;
using std::vector;
#endif

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect2(nums1, nums2);
        }
        return intersect2(nums2, nums1);
    }

    vector<int> intersect2(vector<int>& nums1, vector<int> &nums2) {
        vector<int> result;
        for (size_t i = 0; i < nums1.size() && !nums2.empty(); i++) {
            auto it = nums2.begin();
            while (it != nums2.end()) {
                if (nums1[i] == *it) {
                    result.push_back(nums1[i]);
                    nums2.erase(it);
                    break;
                }
                it++;
            }
        }
        return result;
    }
};

#ifdef LEETCODE
#include <iostream>
#include <iterator>
#include <algorithm>
using std::cout;
using std::ostream_iterator;

int main(int argc, char *argv[]) {
    Solution s;

    vector<int> num1 = {1,2,2,1};
    vector<int> num2 = {2,2};
    vector<int> v1 = s.intersect(num1, num2);
    std::copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    vector<int> num3 = {4,9,5};
    vector<int> num4 = {9,4,9,8,4};
    vector<int> v2 = s.intersect(num3, num4);
    std::copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
#endif

