
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
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{5,2,3,1};
    s.sortArray(v1);
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(cout, ", "));
    return 0;
}
#endif

