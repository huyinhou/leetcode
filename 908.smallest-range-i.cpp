/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 *
 * https://leetcode.com/problems/smallest-range-i/description/
 *
 * algorithms
 * Easy (64.44%)
 * Total Accepted:    21.2K
 * Total Submissions: 32.8K
 * Testcase Example:  '[1]\n0'
 *
 * Given an array A of integers, for each integer A[i] we may choose any x with
 * -K <= x <= K, and add x to A[i].
 * 
 * After this process, we have some array B.
 * 
 * Return the smallest possible difference between the maximum value of B and
 * the minimum value of B.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1], K = 0
 * Output: 0
 * Explanation: B = [1]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [0,10], K = 2
 * Output: 6
 * Explanation: B = [2,8]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = [1,3,6], K = 3
 * Output: 0
 * Explanation: B = [3,3,3] or B = [4,4,4]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * 0 <= A[i] <= 10000
 * 0 <= K <= 10000
 * 
 * 
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <stack>
#include <ostream>
#include <iterator>
#include <iostream>
#include <sstream>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxi = INT_MIN, mini = INT_MAX;
        for (size_t i = 0; i < A.size(); i++) {
            if (A[i] > maxi) {
                maxi = A[i];
            }
            if (A[i] < mini) {
                mini = A[i];
            }
        }
        if (maxi - mini > 2 * K) {
            return maxi - mini - 2 * K;
        }
        return 0;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> a1{1};
    assert(0 == s.smallestRangeI(a1, 0));
    vector<int> a2{0,10};
    assert(6 == s.smallestRangeI(a2, 2));
    vector<int> a3{1,3,6};
    assert(0 == s.smallestRangeI(a3, 3));
    
    return 0;
}
#endif

