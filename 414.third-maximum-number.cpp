
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
    int thirdMax(vector<int>& nums) {
        if (nums.size() < 3) {
            auto it = std::max_element(nums.begin(), nums.end());
            return *it;
        }

        vector<int> temp;
        for (size_t i = 0; i < nums.size(); i++) {
            if ((temp.size() >= 3) && nums[i] <= *temp.rbegin()) {
                continue;
            }
            auto it = temp.begin();
            for (; it != temp.end(); it++) {
                if (nums[i] == *it) {
                    goto next_loop;
                }
                if (nums[i] < *it) {
                    continue;
                }
                temp.insert(it, nums[i]);
                break;
            }
            if (it == temp.end()) {
                temp.push_back(nums[i]);
            }
            if (temp.size() > 3) {
                temp.resize(3);
            }
        next_loop:
            ;
        }
        if (temp.size() < 3) {
            return temp[0];
        }
        return *temp.rbegin();
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {3, 2, 1};
    assert(s.thirdMax(v1) == 1);

    vector<int> v2 = {1, 2};
    assert(s.thirdMax(v2) == 2);

    vector<int> v3 = {2, 2, 3, 1};
    assert(s.thirdMax(v3) == 1);
    return 0;
}
#endif
