/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 * https://leetcode.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (57.75%)
 * Total Accepted:    14.5K
 * Total Submissions: 24.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a square array of integers A, we want the minimum sum of a falling
 * path through A.
 * 
 * A falling path starts at any element in the first row, and chooses one
 * element from each row.  The next row's choice must be in a column that is
 * different from the previous row's column by at most one.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: 12
 * Explanation: 
 * The possible falling paths are:
 * 
 * 
 * 
 * [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
 * [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
 * [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
 * 
 * 
 * The falling path with the smallest sum is [1,4,7], so the answer is 12.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length == A[0].length <= 100
 * -100 <= A[i][j] <= 100
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

#include <algorithm>
class Solution {
public:
    int minFallingPathSum(vector<vector<int> >& A) {
        vector<vector<int> >::reverse_iterator it = A.rbegin();
        vector<int> line(it->begin(), it->end());
        vector<int> tmpl(A.size());
        it++;
        // std::copy(line.begin(), line.end(), std::ostream_iterator<int>(cout, ", "));
        // cout<<std::endl;
        while (it != A.rend()) {
            for (size_t i = 0; i < it->size(); i++) {
                int v = line.at(i);
                if (i >= 1) {
                    if (v > line.at(i - 1)) {
                        v = line.at(i - 1);
                    }
                }
                if (i + 1 < line.size()) {
                    if (v > line.at(i + 1)) {
                        v = line.at(i + 1);
                    }
                }
                tmpl[i] = v + it->at(i);
            }
            line.swap(tmpl);
            it++;
            // std::copy(line.begin(), line.end(), std::ostream_iterator<int>(cout, ", "));
            // cout<<std::endl;
        }
        return *std::min_element(line.begin(), line.end());
    }
};

#ifdef LEETCODE
vector<vector<int> > test_case1() {
    vector<vector<int> > ret;
    vector<int> l1{1, 2, 3};
    vector<int> l2{4, 5, 6};
    vector<int> l3{7, 8, 9};
    ret.push_back(l1);
    ret.push_back(l2);
    ret.push_back(l3);
    return ret;
}

vector<vector<int> > test_case2() {
    vector<vector<int> > ret;
    vector<int> l1{-80, -13, 22};
    vector<int> l2{83, 94, -5};
    vector<int> l3{73, -48, 61};
    ret.push_back(l1);
    ret.push_back(l2);
    ret.push_back(l3);
    return ret;
}

int main(int argc, char *argv[]) {
    Solution s;
    auto t1 = test_case1();
    assert(s.minFallingPathSum(t1) == 12);
    t1 = test_case2();
    assert(s.minFallingPathSum(t1) == -66);
    return 0;
}
#endif
