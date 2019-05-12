
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
#include <cmath>
using namespace std;
#endif

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (auto n : nums) {
            n = std::abs(n);
            if (nums[n] > 0) {
                nums[n] = -nums[n];
            } else {
                return n;
            }
        }
        return -1;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,3,4,2,2};
    assert(s.findDuplicate(v1) == 2);

    vector<int> v2 = {3,1,3,4,2};
    assert(s.findDuplicate(v2) == 3);

    vector<int> v3 = {2,2,2,2,2};
    assert(s.findDuplicate(v3) == 2);
    return 0;
}
#endif
