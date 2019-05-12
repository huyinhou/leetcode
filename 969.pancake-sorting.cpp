
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
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ret;
        for (int end = A.size(); end > 0; end--) {
            auto it = std::max_element(A.begin(), A.begin() + end);
            if (it == A.begin() + (end  - 1)) {
                continue;
            }
            if (it > A.begin()) {
                ret.push_back((it - A.begin()) + 1);
                std::reverse(A.begin(), it + 1);
            }
            ret.push_back(end);
            std::reverse(A.begin(), A.begin() + end);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {3,2,4,1};
    auto ret = s.pancakeSort(v1);
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));

    vector<int> v2 = {1,2,3};
    ret = s.pancakeSort(v2);
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout<<std::endl;

    vector<int> v3 = {5,6,2,3,4,1};
    ret = s.pancakeSort(v3);
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
