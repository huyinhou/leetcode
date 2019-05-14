
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
    int minFlipsMonoIncr(string S) {
        int dp0 = 0, dp1 = 0;
        for (auto c : S) {
            if (c == '0') {
                dp1 = std::min(dp0, dp1) + 1;
            } else {
                dp1 = std::min(dp0, dp1);
                dp0 = dp0 + 1;
            }
        }
        return std::min(dp0, dp1);
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.minFlipsMonoIncr("00110") == 1);
    assert(s.minFlipsMonoIncr("010110") == 2);
    assert(s.minFlipsMonoIncr("00011000") == 2);
    return 0;
}
#endif
