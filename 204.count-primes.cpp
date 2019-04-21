/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (28.38%)
 * Total Accepted:    217.9K
 * Total Submissions: 767.7K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 */
#include <vector>
using std::vector;

class Solution {
public:
    int countPrimes(int n) {
        int total = 0;
        vector<bool> bits(n);
        for (int i = 2; i < n; i++) {
            if (bits[i]) {  // 为true，非质数
                continue;
            }
            total += 1;
            int tmp = n / i; 
            for (int j = i; j <= tmp; j++) {
                bits[i * j] = true;
            }
        }
        return total;
    }
};

// #define LEETEST
#ifdef LEETEST
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.countPrimes(10) == 4);
    return 0;
}
#endif
