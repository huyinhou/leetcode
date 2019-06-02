
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
    int numRabbits(vector<int>& answers) {
        map<int, int> ansmap;
        for (int i = 0; i < answers.size(); i++) {
            ansmap[answers[i]]++;
        }
        int total = 0;
        for (auto it = ansmap.begin(); it != ansmap.end(); it++) {
            total += ((it->second - 1) / (it->first + 1) + 1) * (it->first + 1);
        }
        return total;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,1,2};
    assert(s.numRabbits(v1) == 5);

    vector<int> v2 = {10,10,10};
    assert(s.numRabbits(v2) == 11);

    vector<int> v3 = {};
    assert(s.numRabbits(v3) == 0);
    return 0;
}
#endif
