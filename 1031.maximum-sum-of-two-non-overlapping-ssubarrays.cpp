
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
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        for (size_t i = 1; i < A.size(); i++) {
            A[i] += A[i - 1];
        }
        int lmax = A[L - 1], mmax = A[M - 1];
        int ret = A[L + M - 1];
        for (size_t i = L + M; i < A.size(); i++) {
            lmax = std::max(lmax, A[i - M] - A[i - M - L]);
            mmax = std::max(mmax, A[i - L] - A[i - L - M]);
            ret = std::max(std::max(ret, lmax + A[i] - A[i - M]), mmax + A[i] - A[i - L]);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {0,6,5,2,2,5,1,9,4};
    assert(s.maxSumTwoNoOverlap(v1, 1, 2) == 20);

    vector<int> v2 = {3,8,1,3,2,1,8,9,0};
    assert(s.maxSumTwoNoOverlap(v2, 3, 2) == 29);

    vector<int> v3 = {2,1,5,6,0,9,5,0,3,8};
    assert(s.maxSumTwoNoOverlap(v3, 4, 3) == 31);
    return 0;
}
#endif
