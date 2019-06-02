
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
    int maxChunksToSorted(vector<int>& arr) {
        int next = -1;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i > next) {
                ans++;
                next = i;
            }
            if (arr[i] > next) {
                next = arr[i];
            }
        }
        return ans;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,0,2,3,4};
    assert(s.maxChunksToSorted(v1) == 4);
    vector<int> v2 = {4,3,2,1,0};
    assert(s.maxChunksToSorted(v2) == 1);
    return 0;
}
#endif
