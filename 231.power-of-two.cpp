/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (41.68%)
 * Total Accepted:    215.7K
 * Total Submissions: 517.4K
 * Testcase Example:  '1'
 *
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: true 
 * Explanation: 2^0 = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 16
 * Output: true
 * Explanation: 2^4 = 16
 * 
 * Example 3:
 * 
 * 
 * Input: 218
 * Output: false
 * 
 */
// #include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        bool gotone = false;
        unsigned int mask = 1;
        while (mask != 0) {
            if ((n & mask) != 0) {
                if (gotone) {
                    return false;
                }
                gotone = true;
            }
            // std::cout << mask << ", " << gotone << std::endl;
            mask = mask << 1;
        }
        return true;
    }
};

// #define LEETEST
#ifdef LEETEST
#include <cassert>

int main(int argc, char *argv[]) {
    Solution s;
    assert(s.isPowerOfTwo(2));
    assert(!s.isPowerOfTwo(3));
    assert(!s.isPowerOfTwo(-10));    
    assert(!s.isPowerOfTwo(0));    
    return 0;
}
#endif