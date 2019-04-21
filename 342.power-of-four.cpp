/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (40.01%)
 * Total Accepted:    107.3K
 * Total Submissions: 268.3K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example 1:
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
 * Input: 5
 * Output: false
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */
// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#endif

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        }
        int pos = -1;
        int off = 0;
        unsigned int mask = 1;
        while (mask != 0) {
            if ((mask & num) != 0) {
                if (pos >= 0) {
                    return false;   // 多于一个1 bit
                }
                pos = off;
            }
            mask <<= 1;
            off++;
        }
        return pos % 2 == 0;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.isPowerOfFour(4));
    assert(s.isPowerOfFour(16));
    assert(!s.isPowerOfFour(15));
    assert(s.isPowerOfFour(1));
    assert(!s.isPowerOfFour(0));
}
#endif
