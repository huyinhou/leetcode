
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
    Solution() {
        maxans[0] = 0;
        maxans[1] = 0;
        maxans[2] = 1;
        maxans[3] = 2;
        for (int i = 4; i < 59; i++) {
            maxans[i] = 0;
        }
    }

    int integerBreak(int n) {
        if (maxans[n] != 0) {
            return maxans[n];
        }
        for (int i = 4; i <= n; i++) {
            int ret = 2 * (i - 2);
            ret = std::max(3 * (i - 3), ret);
            ret = std::max(2 * maxans[i - 2], ret);
            ret = std::max(3 * maxans[i - 3], ret);
            maxans[i] = ret;
        }
        return maxans[n];
    }

private:
    int maxans[59];
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    cout<<s.integerBreak(4)<<std::endl;
    cout<<s.integerBreak(5)<<std::endl;
    cout<<s.integerBreak(6)<<std::endl;
    cout<<s.integerBreak(7)<<std::endl;
    cout<<s.integerBreak(8)<<std::endl;
    cout<<s.integerBreak(9)<<std::endl;
    return 0;
}
#endif
