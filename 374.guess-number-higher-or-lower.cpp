/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (38.83%)
 * Total Accepted:    102.4K
 * Total Submissions: 262.4K
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows:
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I'll tell you whether the number is higher or
 * lower.
 * 
 * You call a pre-defined API guess(int num) which returns 3 possible results
 * (-1, 1, or 0):
 * 
 * 
 * -1 : My number is lower
 * ⁠1 : My number is higher
 * ⁠0 : Congrats! You got it!
 * 
 * 
 * Example :
 * 
 * 
 * 
 * Input: n = 10, pick = 6
 * Output: 6
 * 
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cstddef>
#include <cstdio>
#endif

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return guessRange(1, n);
    }

    int guessRange(int l, int r) {
        int m = l / 2 + r / 2;
        if (l == r) {
            m = l;
        }
        int a = guess(m);
        // printf("l=%d, r=%d, m=%d, a=%d\n", l, r, m, a);
        if (a < 0) {
            return guessRange(l, m - 1);
        } else if (a == 0) {
            return m;
        }
        return guessRange(m + 1, r);
    }
};


#ifdef LEETCODE
#include <cassert>
static int s_num = 0;

int guess(int num) {
    return s_num - num;
}

int main(int argc, char *argv[]) {
    Solution s;
    for (int i = 1; i <= 10000; i++) {
        s_num = i;
        printf("%d\n", i);
        assert(i == s.guessNumber(10000));
    }
    return 0;
}
#endif

