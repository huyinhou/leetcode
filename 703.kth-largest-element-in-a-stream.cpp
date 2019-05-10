/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
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
using namespace std;
#endif

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        kmax.resize(k, INT_MIN);
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        auto pos = lower_bound(kmax.begin(), kmax.end(), val, [](const int &a, const int &b) {
            return a >= b;
        });
        if (pos != kmax.end()) {
            kmax.insert(pos, val);
            kmax.resize(kmax.size() - 1);
        }
        
        return *kmax.rbegin();
    }

private:
    vector<int> kmax;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    vector<int> v1 = {4,5,8,2};
    KthLargest *kl = new KthLargest(3, v1);
    assert(kl->add(3) == 4);
    assert(kl->add(5) == 5);
    assert(kl->add(10) == 5);
    assert(kl->add(9) == 8);
    assert(kl->add(4) == 8);
    return 0;
}
#endif
