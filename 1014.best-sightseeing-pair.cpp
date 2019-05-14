
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
#include <numeric>
using namespace std;
#endif

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int maxj = a[a.size() - 1] - (a.size() - 1);
        int maxs = INT_MIN;
        for (int i = a.size() - 2; i >= 0; i--) {
            maxj = std::max(maxj, a[i + 1] - (i + 1));
            maxs = std::max(maxs, a[i] + i + maxj);
        }
        return maxs;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {8,1,5,2,6};
    assert(s.maxScoreSightseeingPair(v1) == 11);
    return 0;
}
#endif
