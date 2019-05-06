/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
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
#include <numeric>
using namespace std;
#endif

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        if (B.empty()) {
            return true;
        }
        size_t start = 0;
        size_t index = 0;
        while ((index = A.find(B[0], start)) != string::npos) {
            // cout<<index<<" "<<A.data() + index<<" "<<B.data() + index<<std::endl;
            if ((strncmp(A.data() + index, B.data(), A.size() - index) == 0)
                && (strncmp(A.data(), B.data() + B.size() - index, index) == 0)) {
                return true;
            }

            start = index + 1;
        }
        return false;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.rotateString("abcde", "cdeab"));
    assert(!s.rotateString("abcde", "abced"));
    return 0;
}
#endif

