/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
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
#include <map>
#include <vector>
using namespace std;
#endif

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int flag = 0;
        for (size_t i = 1; i < A.size(); i++) {
            int tmp = A[i] - A[i - 1];
            if (tmp > 0) {
                if (flag < 0) {
                    return false;
                }
                flag = tmp;
            } else if (tmp < 0) {
                if (flag > 0) {
                    return false;
                }
                flag = tmp;
            }
        }
        return true;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{1,2,2,3};
    assert(s.isMonotonic(v1));
    vector<int> v2{6,5,4,4};
    assert(s.isMonotonic(v2));
    vector<int> v3{1,3,2};
    assert(!s.isMonotonic(v3));
    return 0;
}
#endif
