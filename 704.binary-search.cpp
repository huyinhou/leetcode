/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
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
#include <algorithm>
#include <map>
using namespace std;
#endif

#include <cstdlib>

int compare(const void *ap, const void *bp)
{
    const int *a = (int *) ap;
    const int *b = (int *) bp;
    if(*a < *b)
        return -1;
    else if(*a > *b)
        return 1;
    else
        return 0;
}
 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int *pos = static_cast<int*>(
            std::bsearch(&target, nums.data(), nums.size(), sizeof(int), compare));
        if (!pos) {
            return -1;
        }
        return pos - nums.data();
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {-1,0,3,5,9,12};
    assert(s.search(v1, 9) == 4);
    assert(s.search(v1, 2) == -1);
    return 0;
}
#endif

