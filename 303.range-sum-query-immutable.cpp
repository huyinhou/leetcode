/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (36.86%)
 * Total Accepted:    129.3K
 * Total Submissions: 350.7K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
#include <vector>
using std::vector;

class NumArray {
public:
    NumArray(vector<int> nums) {
        m_cnt = nums.size();
        m_sum.resize(m_cnt * (m_cnt + 1) / 2);
        calcSums(nums);
    }
    
    int sumRange(int i, int j) {
        if (i > j) {
            return 0;
        }
        return m_sum[sumIndex(i, j)];
    }

    int sumIndex(int i, int j) {
        return i * m_cnt + j - i * (i + 1) / 2;
    }

    void calcSums(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); i ++) {
            for (size_t j = i; j < nums.size(); j++) {
                if (i == j) {
                    m_sum[sumIndex(i, j)] = nums[j];
                } else {
                    m_sum[sumIndex(i, j)] = m_sum[sumIndex(i, j - 1)] + nums[j];
                }
            }
        }
    }

public:
    size_t m_cnt;
    vector<int> m_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
// #define LEETCODE
#ifdef LEETCODE
#include <iostream>
#include <algorithm>
#include <cassert>
using std::for_each;
using std::cout;

int main(int argc, char *argv[]) {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray na(nums);
    for_each(na.m_sum.begin(), na.m_sum.end(), [](int s) {
        cout << s << " ";
    });
    assert(na.sumRange(0, 2) == 1);
    assert(na.sumRange(0, 0) == -2);
    assert(na.sumRange(2, 5) == -1);
    assert(na.sumRange(0, 5) == -3);
    return 0;
}
#endif
