/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
#endif

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right = std::accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            right -= nums[i];
            if (i > 0) {
                left += nums[i-1];
            }
            if (left == right) {
                return i;
            }
        }
        return -1;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> n1{1, 7, 3, 6, 5, 6};
    assert(s.pivotIndex(n1) == 3);
    vector<int> n2{1, 2, 3};
    assert(s.pivotIndex(n2) == -1);
    return 0;
}
#endif


