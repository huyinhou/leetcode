/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 *
 * https://leetcode.com/problems/transpose-matrix/description/
 *
 * algorithms
 * Easy (63.75%)
 * Total Accepted:    42.1K
 * Total Submissions: 66K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix A, return the transpose of A.
 * 
 * The transpose of a matrix is the matrix flipped over it's main diagonal,
 * switching the row and column indices of the matrix.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
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
#include <map>
#include <set>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
using std::map;
using std::set;
#endif

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> ret;
        if (A.empty()) {
            return ret;
        }
        ret.resize(A[0].size());
        for (size_t i = 0; i < ret.size(); i++) {
            ret[i].reserve(A.size());
        }
        for (size_t i = 0; i < A.size(); i++) {
            vector<int> &row = A[i];
            for (size_t j = 0; j < row.size(); j++) {
                ret[j].push_back(row[j]);
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v1 = {
        {1,2,3},{4,5,6},{7,8,9}
    };
    auto ret = s.transpose(v1);
    std::for_each(ret.begin(), ret.end(), [](vector<int> &row){
        std::copy(row.begin(), row.end(), std::ostream_iterator<int>(cout, ", "));
        cout<<std::endl;
    });
    
    vector<vector<int>> v2 = {
        {1,2,3},{4,5,6}
    };
    ret = s.transpose(v2);
    std::for_each(ret.begin(), ret.end(), [](vector<int> &row){
        std::copy(row.begin(), row.end(), std::ostream_iterator<int>(cout, ", "));
        cout<<std::endl;
    });
    return 0;
}
#endif

