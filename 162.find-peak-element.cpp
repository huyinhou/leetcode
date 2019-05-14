
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
    int findPeakElement(vector<int>& nums) {
        bool flag = true;   // 比前一个元素大
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 == nums.size() && flag) {
                return i;
            }
            if (nums[i] > nums[i + 1]) {
                if (flag) {
                    return i;
                }
                flag = false;
            } else {
                flag = true;
            }
        }
        return 0;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,2,3,1};
    assert(s.findPeakElement(v1) == 2);

    vector<int> v2 = {1,2,1,3,5,6,4};
    assert(s.findPeakElement(v2) == 1);
    return 0;
}
#endif
