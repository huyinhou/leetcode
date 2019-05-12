
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
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int nsize = nums.size();
        int count = 0;
        for (int i = 0; i < nsize - 2; i++) {
            for (int j = i + 1; j < nsize - 1; j++) {
                int sum = nums[i] + nums[j];
                for (int k = j + 1; k < nsize && nums[k] < sum; k++) {
                    count++;
                }
            }
        }
        // cout<<count<<std::endl;
        return count;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {2,2,3,4};
    assert(s.triangleNumber(v1) == 3);
    return 0;
}
#endif
