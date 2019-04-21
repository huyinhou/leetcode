/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (30.16%)
 * Total Accepted:    45.8K
 * Total Submissions: 151.8K
 * Testcase Example:  '3'
 *
 * Find the n^th digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ... 
 * 
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 2^31).
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 3
 * 
 * Output:
 * 3
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 11
 * 
 * Output:
 * 0
 * 
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cstddef>
#include <cstdio>
#include <string>
using std::string;
#endif

class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }
        int min = 1;    // 最小范围
        int max = 10;   // 最大范围
        int digits = 1; // 位数
        while ((n + digits - 1) / digits > (max - min)) {
            n -= (max - min) * digits;
            min *= 10;
            max *= 10;
            digits++;
        }
        // printf("max=%d, min=%d, digits=%d, n=%d\n", max, min, digits, n);
        int num = min + ((n - 1) / digits);
        for (int i = 0; i < (n + digits - 1) % digits; i++) {
            max /= 10;
            min /= 10;
        }
        // printf("max=%d, min=%d, n=%d, num=%d\n", max, min, n, num);
        return (num % max) / min;
    }
};


#ifdef LEETCODE
#include <cassert>
int main(int argc, char *argv[]) {
    Solution s;
    for (int i = 1; i < 10; i++) {
        assert(s.findNthDigit(i) == i);
    }
    assert(s.findNthDigit(12) == 1);
    assert(s.findNthDigit(15) == 2);
    assert(s.findNthDigit(189) == 9);
    assert(s.findNthDigit(190) == 1);
    return 0;
}
#endif

