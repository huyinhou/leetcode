/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (72.85%)
 * Total Accepted:    52.6K
 * Total Submissions: 72.7K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an array of integers A sorted in non-decreasing order, return an array
 * of the squares of each number, also in sorted non-decreasing order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A is sorted in non-decreasing order.
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

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        std::transform(A.begin(), A.end(), A.begin(), pow2);
        std::sort(A.begin(), A.end());
        return A;
    }

    static int pow2(int a) {
        return a * a;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{-4,-1,0,3,10};
    s.sortedSquares(v1);
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(cout, ", "));
    cout<<std::endl;

    vector<int> v2{-7,-3,2,3,11};
    s.sortedSquares(v2);
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(cout, ", "));

    return 0;
}
#endif

