/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
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
#include <queue>
using namespace std;
#endif

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int> > qmax;   // 最大的3个数
        priority_queue<int> qmin;   // 最小的三个负数
        for (size_t i = 0; i < nums.size(); i++) {
            qmax.push(nums[i]);
            if (qmax.size() > 3) {
                qmax.pop();
            }
            if (nums[i] < 0) {
                qmin.push(nums[i]);
                if (qmin.size() > 2) {
                    qmin.pop();
                }
            }
        }

        int temp1 = qmax.top();
        qmax.pop();
        temp1 *= qmax.top();
        qmax.pop();
        // cout<<"temp1="<<temp1<<std::endl;
        if (qmin.size() >= 2) {
            int temp2 = qmin.top();
            qmin.pop();
            temp2 *= qmin.top();
            qmin.pop();
            // cout<<"temp2="<<temp2<<std::endl;
            if (temp1 < temp2) {
                return qmax.top() * temp2;
            }
        }
        return qmax.top() * temp1;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {3,2,0,-1,-2};
    assert(s.maximumProduct(v1) == 6);
    vector<int> v3 = {3,2,0,-1,-2,-4};
    assert(s.maximumProduct(v3) == 24);
    vector<int> v2 = {0,-1,-2,-3};
    assert(s.maximumProduct(v2) == 0);
    vector<int> v4 = {-4,-3,-2,-1,60};
    assert(s.maximumProduct(v4) == 720);
    vector<int> v5 = {-1,60,2,3};
    assert(s.maximumProduct(v5) == 360);
    return 0;
}
#endif

