
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
    int lastStoneWeight(vector<int>& stones) {
        std::make_heap(stones.begin(), stones.end());
        while (stones.size() > 1) {
            std::pop_heap(stones.begin(), stones.end());
            int y = stones.back();
            stones.pop_back();
            std::pop_heap(stones.begin(), stones.end());
            int x = stones.back();
            stones.pop_back();
            if (x == y) {
                continue;
            }
            stones.push_back(y - x);
            std::push_heap(stones.begin(), stones.end());
        }
        if (stones.empty()) {
            return 0;
        }
        return stones[0];
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {2,7,4,1,8,1};
    assert(s.lastStoneWeight(v1) == 1);
    cout<<std::endl;
    vector<int> v2 = {2,1,1};
    assert(s.lastStoneWeight(v2) == 0);
    return 0;
}
#endif
