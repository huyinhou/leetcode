/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 *
 * https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/
 *
 * algorithms
 * Easy (58.10%)
 * Total Accepted:    26.5K
 * Total Submissions: 45.4K
 * Testcase Example:  '842\n888'
 *
 * 
 * Given two integers L and R, find the count of numbers in the range [L, R]
 * (inclusive) having a prime number of set bits in their binary
 * representation.
 * 
 * (Recall that the number of set bits an integer has is the number of 1s
 * present when written in binary.  For example, 21 written in binary is 10101
 * which has 3 set bits.  Also, 1 is not a prime.)
 * 
 * 
 * Example 1:
 * Input: L = 6, R = 10
 * Output: 4
 * Explanation:
 * 6 -> 110 (2 set bits, 2 is prime)
 * 7 -> 111 (3 set bits, 3 is prime)
 * 9 -> 1001 (2 set bits , 2 is prime)
 * 10->1010 (2 set bits , 2 is prime)
 * 
 * 
 * Example 2:
 * Input: L = 10, R = 15
 * Output: 5
 * Explanation:
 * 10 -> 1010 (2 set bits, 2 is prime)
 * 11 -> 1011 (3 set bits, 3 is prime)
 * 12 -> 1100 (2 set bits, 2 is prime)
 * 13 -> 1101 (3 set bits, 3 is prime)
 * 14 -> 1110 (3 set bits, 3 is prime)
 * 15 -> 1111 (4 set bits, 4 is not prime)
 * 
 * 
 * Note:
 * L, R will be integers L  in the range [1, 10^6].
 * R - L will be at most 10000.
 * 
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
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int ret = 0;
        for (int i = L; i <= R; i++) {
            int b = countBits(i);
            if (primes[b] > 0) {
                ret ++;
            }
        }
        return ret;
    }

    int countBits(int num) {
        int ret = 0;
        unsigned mask = 1;
        for (size_t i = 0; i < 20; i++) {
            if (mask & num) {
                ret ++;
            }
            mask <<= 1;
        }
        return ret;
    }

    // 20以内的质数
    static int primes[21];
};

int Solution::primes[21] = {
    0,           // 0
    0, 2, 3, 0, 5,  // 1 - 5
    0, 7, 0, 0, 0,  // 6 - 10
    11, 0, 13, 0, 0,    // 11 - 15
    0, 17, 0, 19, 0     // 16 - 20
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.countBits(1000000) == 7);
    assert(s.countPrimeSetBits(6, 10) == 4);
    assert(s.countPrimeSetBits(10, 15) == 5);
    return 0;
}
#endif

