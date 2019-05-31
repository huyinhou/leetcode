
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
#include <queue>
using namespace std;
#endif

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp(heights);
        std::sort(tmp.begin(), tmp.end());
        int count = 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (heights[i] != tmp[i]) {
                count++;
            }
        }
        return count;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,1,4,2,1,3};
    assert(s.heightChecker(v1) == 3);
    return 0;
}
#endif
