
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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int total = 0;
        int max_statisfy = 0;
        int satisfy = 0;
        // vector<int> temp;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 1) {   // 最后X minute
                satisfy += customers[i];
            } else {
                total += customers[i];
            }
            if (i - X >= 0) {
                if (grumpy[i - X]) {
                    satisfy -= customers[i - X];
                }
            }
            max_statisfy = std::max(max_statisfy, satisfy);
        }
        return total + max_statisfy;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> c1 = {1,0,1,2,1,1,7,5};
    vector<int> g1 = {0,1,0,1,0,1,0,1};
    assert(s.maxSatisfied(c1, g1, 3) == 16);
    return 0;
}
#endif
