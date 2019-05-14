
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
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> remain(K, 0);
        int sum = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            sum %= K;
            if (sum < 0) {
                sum += K;
            }
            remain[sum]++;
        }
        
        sum = remain[0];
        for (int i = 0; i < K; i++) {
            sum += remain[i] * (remain[i] - 1) / 2;
        }
        return sum;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {4,5,0,-2,-3,1};
    assert(s.subarraysDivByK(v1, 5) == 7);
    return 0;
}
#endif
