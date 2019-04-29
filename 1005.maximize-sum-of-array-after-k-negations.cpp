/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
#endif

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        // 按0进行分区
        int i = 0, j = A.size() - 1, minv = INT_MAX;
        while (i <= j) {
            while (i <= j && A[i] < 0) i++;
            while (i <= j && A[j] >= 0) {
                if (minv > A[j]) {
                    minv = A[j];
                }
                j--;
            }
            if (i < j) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
        
        if (K <= i) {   // 将前k个负数变正
            std::sort(A.begin(), A.begin() + i);
            for (j = 0; j < K; j++) {
                A[j] = -A[j];
            }
            K = 0;
        } else { // 全部负数变正，再找最小正数，判断正负号
            for (j = 0; j < i; j++) {
                A[j] = -A[j];
                if (A[j] < minv) {
                    minv = A[j];
                }
            }
            K -= i;
        }
        int result = std::accumulate(A.begin(), A.end(), 0);
        if (K % 2 != 0) {
            result -= 2 * minv;
        }
        return result;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {4,2,3};
    assert(s.largestSumAfterKNegations(v1, 1) == 5);
    assert(s.largestSumAfterKNegations(v1, 2) == 9);
    vector<int> v2 = {3,-1,0,2};
    assert(s.largestSumAfterKNegations(v2, 3) == 6);
    assert(s.largestSumAfterKNegations(v2, 2) == 6);
    vector<int> v3 = {2,-3,-1,5,-4};
    assert(s.largestSumAfterKNegations(v3, 2) == 13);
    vector<int> v4 = {-2,5,0,2,-2};
    assert(s.largestSumAfterKNegations(v4, 3) == 11);
    return 0;
}
#endif
