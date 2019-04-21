/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (30.80%)
 * Total Accepted:    337.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
#include <cstdint>
#include <cassert>

/* 
 * 参见：https://blog.csdn.net/zhaixh_89/article/details/78157597
 */

class Solution {
public:
    int mySqrt(int x) {
        int64_t a = x;
        while (a * a > x) {
            a = (a + x / a) >> 1;
        }
        return a;
    }
};

// int main(int argc, char *argv[]) {
//     Solution s;
//     for (int i = 0; i < 2000; i++) {
//         int r = s.mySqrt(i);
//         assert(r * r <= i);
//         assert((r+1) * (r+1) > i);
//     }
// } 
