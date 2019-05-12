
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
using namespace std;
#endif

static int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> cntmap;
        for (size_t i = 0; i < deck.size(); i++) {
            cntmap[deck[i]]++;
        }
        if (cntmap.size() == 1) {
            if (cntmap.begin()->second == 1) {
                return false;
            }
            return true;
        }
        
        auto it = cntmap.begin();
        int x = it->second;
        while ((x > 1) && ((++it) != cntmap.end())) {
            x = gcd(x, it->second);
        }
        return x > 1;
    }
};


#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,2,3,4,4,3,2,1};
    assert(s.hasGroupsSizeX(v1) == true);
    vector<int> v2 = {1,1,1,2,2,2,3,3};
    assert(s.hasGroupsSizeX(v2) == false);
    vector<int> v3 = {1};
    assert(!s.hasGroupsSizeX(v3));
    vector<int> v4 = {1,1};
    assert(s.hasGroupsSizeX(v4));
    vector<int> v5 = {1,1,2,2,2,2};
    assert(s.hasGroupsSizeX(v5));
    return 0;
}
#endif
