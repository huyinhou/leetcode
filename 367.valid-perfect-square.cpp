/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (39.44%)
 * Total Accepted:    101.9K
 * Total Submissions: 258.3K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 14
 * Output: false
 * 
 * 
 * 
 */
// #define LEETCODE
#ifdef LEETCODE
#include <cstddef>
#endif

#include <cmath>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) {
            return false;
        }
        if (num < 2) {
            return true;
        }
        double x = 1, fx = x * x - num;
        while (fx > 1e-9 || fx < -1e-9) {
            x -= fx / 2 / x;
            fx = x * x - num;
        }
        int a = (int)x;
        return a * a == num;
    }
};

#ifdef LEETCODE
#include <cassert>
#include <cstdio>

int main(int argc, char *argv[]) {
    Solution s;
    assert(!s.isPerfectSquare(-1));
    for (int i = 0; i < 10000; i ++) {
        assert(s.isPerfectSquare(i * i));
    }
    return 0;
}
#endif