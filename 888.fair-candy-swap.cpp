/*
 * @lc app=leetcode id=888 lang=cpp
 *
 * [888] Fair Candy Swap
 *
 * https://leetcode.com/problems/fair-candy-swap/description/
 *
 * algorithms
 * Easy (56.39%)
 * Total Accepted:    23.9K
 * Total Submissions: 42.4K
 * Testcase Example:  '[1,1]\n[2,2]'
 *
 * Alice and Bob have candy bars of different sizes: A[i] is the size of the
 * i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of
 * candy that Bob has.
 * 
 * Since they are friends, they would like to exchange one candy bar each so
 * that after the exchange, they both have the same total amount of candy.
 * (The total amount of candy a person has is the sum of the sizes of candy
 * bars they have.)
 * 
 * Return an integer array ans where ans[0] is the size of the candy bar that
 * Alice must exchange, and ans[1] is the size of the candy bar that Bob must
 * exchange.
 * 
 * If there are multiple answers, you may return any one of them.  It is
 * guaranteed an answer exists.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,1], B = [2,2]
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [1,2], B = [2,3]
 * Output: [1,2]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = [2], B = [1,3]
 * Output: [2,3]
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = [1,2,5], B = [2,4]
 * Output: [5,4]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * 1 <= B.length <= 10000
 * 1 <= A[i] <= 100000
 * 1 <= B[i] <= 100000
 * It is guaranteed that Alice and Bob have different total amounts of
 * candy.
 * It is guaranteed there exists an answer.
 * 
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
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sa = 0, sb = 0;
        for (auto it = A.begin(); it != A.end(); it++) {
            sa += *it;
        }
        for (auto it = B.begin(); it != B.end(); it++) {
            sb += *it;
        }
        std::sort(B.begin(), B.end());
        int delta = (sb - sa) / 2;
        // cout<<sa<<", "<<sb<<", "<<delta<<std::endl;
        vector<int>::iterator ita, itb;
        for (ita = A.begin(); ita != A.end(); ita++) {
            // cout<<(*ita) + delta<<std::endl;
            itb = std::lower_bound(B.begin(), B.end(), (*ita) + delta);
            if (itb != B.end() && (*itb == (*ita) + delta)) {
                break;
            }
        }
        return vector<int>{*ita, *itb};
    }
};

#ifdef LEETCODE
void dumpVector(vector<int> &v) {
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> va1{1, 1};
    vector<int> vb1{2, 2};
    vector<int> ret = s.fairCandySwap(va1, vb1);
    dumpVector(ret);

    vector<int> va2{2};
    vector<int> vb2{1, 3};
    ret = s.fairCandySwap(va2, vb2);
    dumpVector(ret);

    vector<int> va3{1, 2};
    vector<int> vb3{2, 3};
    ret = s.fairCandySwap(va3, vb3);
    dumpVector(ret);

    vector<int> va4{1, 2, 5};
    vector<int> vb4{2, 4};
    ret = s.fairCandySwap(va4, vb4);
    dumpVector(ret);
    return 0;
}
#endif
