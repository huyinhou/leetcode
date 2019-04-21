/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 *
 * https://leetcode.com/problems/flipping-an-image/description/
 *
 * algorithms
 * Easy (71.71%)
 * Total Accepted:    85.9K
 * Total Submissions: 119.2K
 * Testcase Example:  '[[1,1,0],[1,0,1],[0,0,0]]'
 *
 * Given a binary matrix A, we want to flip the image horizontally, then invert
 * it, and return the resulting image.
 * 
 * To flip an image horizontally means that each row of the image is reversed.
 * For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
 * 
 * To invert an image means that each 0 is replaced by 1, and each 1 is
 * replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1,0],[1,0,1],[0,0,0]]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 * Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 * Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * Explanation: First reverse each row:
 * [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
 * Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 
 * 
 * Notes:
 * 
 * 
 * 1 <= A.length = A[0].length <= 20
 * 0 <= A[i][j] <= 1
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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& a) {
        unsigned mask = 1;
        for (size_t i = 0; i < a.size(); i++) {
            vector<int> &line = a[i];
            size_t m = 0, n = line.size() - 1;
            for (; m < n; m++, n--) {
                int tmp = line[m];
                line[m] = line[n] ^ mask;
                line[n] = tmp ^ mask;
            }
            if (m == n) {
                line[m] = line[m] ^ mask;
            }
        }
        return a;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> l1{1,1,0};
    vector<int> l2{1,0,1};
    vector<int> l3{0,0,0};
    vector<vector<int> > a;
    a.push_back(l1);
    a.push_back(l2);
    a.push_back(l3);
    s.flipAndInvertImage(a);
    for (size_t i = 0; i < a.size(); i++) {
        vector<int> &line = a[i];
        std::copy(line.begin(), line.end(), std::ostream_iterator<int>(cout, ", "));
        cout<<std::endl;
    }
    return 0;
}
#endif
