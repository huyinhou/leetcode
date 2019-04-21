/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 *
 * https://leetcode.com/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (57.05%)
 * Total Accepted:    12.9K
 * Total Submissions: 22.7K
 * Testcase Example:  '[2,1,2]'
 *
 * Given an array A of positive lengths, return the largest perimeter of a
 * triangle with non-zero area, formed from 3 of these lengths.
 * 
 * If it is impossible to form any triangle of non-zero area, return 0.
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
 * Input: [2,1,2]
 * Output: 5
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,1]
 * Output: 0
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [3,2,3,4]
 * Output: 10
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [3,6,2,3]
 * Output: 8
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 10000
 * 1 <= A[i] <= 10^6
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
#include <sstream>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        std::sort(A.begin(), A.end());
        for (int i = A.size() - 1; i >= 2; i--) {
            int s = A[i - 1] + A[i - 2];
            if (s > A[i]) {
                s += A[i];
                return s;
            }
        }
        return 0;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> a1{1, 2, 1};
    assert(s.largestPerimeter(a1) == 0);
    vector<int> a2{3, 2, 3, 4};
    assert(s.largestPerimeter(a2) == 10);
    vector<int> a3{3, 6, 2, 3};
    assert(s.largestPerimeter(a3) == 8);
    vector<int> a4{1, 2, 4, 7, 12};
    assert(s.largestPerimeter(a4) == 0);
    return 0;
}
#endif
