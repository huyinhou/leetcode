
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
#include <sstream>
#include <queue>
using namespace std;
#endif

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0; 
        vector<string> ret;
        for (int pos = 1; pos <= nums.size(); pos++) {
            if (pos < nums.size()) {
                if (nums[pos] == nums[pos - 1] + 1) {
                    continue;
                }
            }
            ostringstream oss;
            if (pos == start + 1) {
                oss<<nums[start];
            } else {
                oss<<nums[start]<<"->"<<nums[pos - 1];
            }
            ret.push_back(oss.str());
            start = pos;
        }
        
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {0,1,2,4,5,7};
    auto ret = s.summaryRanges(v1);
    std::copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, ", "));
    cout<<std::endl;
    vector<int> v2 = {0,2,3,4,6,8,9};
    ret = s.summaryRanges(v2);
    std::copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
