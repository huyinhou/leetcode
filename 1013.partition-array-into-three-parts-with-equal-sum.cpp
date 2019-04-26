
// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#endif

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = std::accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) {
            return false;
        }
        int tmp = 0, exp = sum / 3;
        for (size_t i = 0; i < A.size(); i++) {
            tmp += A[i];
            if (tmp == exp) {
                exp += sum / 3;
            }
        }
        return exp > sum;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{0,2,1,-6,6,-7,9,1,2,0,1};
    assert(s.canThreePartsEqualSum(v1));
    vector<int> v2{0,2,1,-6,6,7,9,-1,2,0,1};
    assert(!s.canThreePartsEqualSum(v2));
    vector<int> v3{3,3,6,5,-2,2,5,1,-9,4};
    assert(s.canThreePartsEqualSum(v3));
    vector<int> v4{1,2,3,0,6};
    assert(!s.canThreePartsEqualSum(v4));
    return 0;
}
#endif

