
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
    int maxTurbulenceSize(vector<int>& A) {
        int flag = 0;
        int start = 0;
        int pos = 1;
        int maxlen = 0;
        for (pos = 1; pos < A.size(); pos++) {
            // cout<<start<<" "<<pos<<" "<<maxlen<<std::endl;
            if (A[pos] > A[pos - 1]) {
                if (flag <= 0) {
                    flag = 1;
                    continue;
                }
                flag = 1;
            } else if (A[pos] == A[pos - 1]) {
                flag = 0;
                maxlen = std::max(maxlen, pos - start);
                start = pos;
                continue;
            } else {
                if (flag >= 0) {
                    flag = -1;
                    continue;
                }
                flag = -1;
            }
            maxlen = std::max(maxlen, pos - start);
            start = pos - 1;
        }
        // cout<<start<<" "<<pos<<" "<<maxlen<<std::endl;
        return std::max(maxlen, pos - start);
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {9,4,2,10,7,8,8,1,9};
    assert(s.maxTurbulenceSize(v1) == 5);

    vector<int> v2 = {4,8,12,16};
    assert(s.maxTurbulenceSize(v2) == 2);

    vector<int> v3 = {100};
    assert(s.maxTurbulenceSize(v3) == 1);
    
    vector<int> v4 = {100, 100, 100};
    assert(s.maxTurbulenceSize(v4) == 1);
    return 0;
}
#endif
