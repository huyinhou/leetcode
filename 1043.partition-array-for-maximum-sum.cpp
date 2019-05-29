
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
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> sum(A.size());
        for (int i = 0; i < A.size(); i++) {
            int maxv = 0;
            int tmps = 0;
            for (int j = 0; (i - j >= 0) && j < K; j++) {
                int k = i - j;
                maxv = std::max(maxv, A[k]);
                if (k > 0) {
                    tmps = std::max(tmps, (j + 1) * maxv + sum[k - 1]);
                } else {
                    tmps = std::max(tmps, (j + 1) * maxv);
                }
            }
            sum[i] = tmps;
        }
        return *sum.rbegin();
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,15,7,9,2,5,10};
    assert(s.maxSumAfterPartitioning(v1, 3) == 84);
    vector<int> v2 = {1,15,7,9,2,5,10,20};
    assert(s.maxSumAfterPartitioning(v2, 3) == 123);
    return 0;
}
#endif
