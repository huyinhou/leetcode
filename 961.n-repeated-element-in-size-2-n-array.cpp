/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 *
 * https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/
 *
 * algorithms
 * Easy (73.21%)
 * Total Accepted:    44.6K
 * Total Submissions: 61.2K
 * Testcase Example:  '[1,2,3,3]'
 *
 * In a array A of size 2N, there are N+1 unique elements, and exactly one of
 * these elements is repeated N times.
 * 
 * Return the element repeated N times.
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
 * Input: [1,2,3,3]
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [2,1,2,5,3,2]
 * Output: 2
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [5,1,5,2,5,3,5,4]
 * Output: 5
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 4 <= A.length <= 10000
 * 0 <= A[i] < 10000
 * A.length is even
 * 
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
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif
#include <set>

class Solution {
public:
    int repeatedNTimes(vector<int>& v) {
        int a = v[0], b = v[1], c = 0;
        if (a == b) {
            return a;
        }
        for (size_t i = 2; i < v.size(); i++) {
            c = v[i];
            if (c == a || c == b) {
                break;
            }
            a = b;
            b = c;
        }
        return c;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{2,1,2,5,3,2};
    assert(s.repeatedNTimes(v1) == 2);
    return 0;
}
#endif
