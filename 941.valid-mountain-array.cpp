
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#endif

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool up = true;
        int top = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1]) {
                if (up) {
                    top++;
                } else {
                    return false;
                }
            } else if (A[i] == A[i - 1]) {
                return false;
            } else {
                if (up) {
                    up = false;
                }
            }
        }
        return top > 0 && top < A.size() - 1;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {2,1};
    assert(!s.validMountainArray(v1));
    vector<int> v2 = {1,2,3};
    assert(!s.validMountainArray(v2));
    vector<int> v3 = {3,5,5};
    assert(!s.validMountainArray(v3));
    vector<int> v4 = {0,3,2,1};
    assert(s.validMountainArray(v4));
    return 0;
}
#endif


