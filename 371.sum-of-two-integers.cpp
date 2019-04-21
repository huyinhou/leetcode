/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (51.14%)
 * Total Accepted:    126.8K
 * Total Submissions: 248K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cstddef>
#endif

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ua = static_cast<unsigned int>(a);
        unsigned int ub = static_cast<unsigned int>(b);
        while (ub) {
            int carry = (ua & ub) << 1;
            ua = ua ^ ub;
            ub = carry;
        }
        return static_cast<int>(ua);
    }
};

#ifdef LEETCODE
#include <cassert>
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.getSum(1, 1) == 2);
    assert(s.getSum(-1, 1) == 0);
    assert(s.getSum(-3, 1) == -2);
    assert(s.getSum(-3, -1) == -4);
    return 0;
}
#endif

