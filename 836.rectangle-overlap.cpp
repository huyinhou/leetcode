
#define LEETCODE
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
#include <algorithm>
#include <map>
using namespace std;
#endif

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return isRangeOverlay(rec1[0], rec1[2], rec2[0], rec2[2]) &&
            isRangeOverlay(rec1[1], rec1[3], rec2[1], rec2[3]);
    }

    bool isRangeOverlay(int x0, int x1, int x2, int x3) {
        if (x1 <= x2 || x3 <= x0) {
            return false;
        }
        return true;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> rec1 = {0,0,2,2};
    vector<int> rec2 = {1,1,3,3};
    assert(s.isRectangleOverlap(rec1, rec2));

    vector<int> rec3 = {0,0,1,1};
    vector<int> rec4 = {1,0,2,1};
    assert(!s.isRectangleOverlap(rec3, rec4));
    return 0;
}
#endif
