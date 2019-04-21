/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 *
 * https://leetcode.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (66.70%)
 * Total Accepted:    36.3K
 * Total Submissions: 54.3K
 * Testcase Example:  '[4,2,5,7]'
 *
 * Given an array A of non-negative integers, half of the integers in A are
 * odd, and half of the integers are even.
 * 
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is
 * even, i is even.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been
 * accepted.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
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

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        int m = 1;
        int i = 0, j = 1;
        while (i < a.size() && j < a.size()) {
            while((i < a.size()) && !(a[i] & m)) {
                i += 2;
            }
            while (j < a.size() && (a[j] & m)) {
                j += 2;
            }
            // cout<<i<<", "<<j<<std::endl;
            if (i < a.size() && j < a.size()) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                i += 2;
                j += 2;
            }
        }
        return a;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{4,2,5,7};
    auto ret = s.sortArrayByParityII(v1);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif

