
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



#ifdef LEETCODE
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int mirror[3] = {0, p, p};
        bool left = true;
        int target = 0;
        int p2 = p * 2;
        while (true) {
            if (left) {
                if (mirror[2] == target) {
                    return 2;
                } else if (mirror[2] < target) {
                    mirror[2] += p2;
                }
            } else {
                if (mirror[0] == target) {
                    return 0;
                } else if (mirror[0] < target) {
                    mirror[0] += p2;
                }

                if (mirror[1] == target) {
                    return 1;
                } else if (mirror[1] < target) {
                    mirror[1] += p2;
                }
            }
            left = !left;
            target += q;
        }
        return 0;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    assert(s.mirrorReflection(2, 1) == 2);
    assert(s.mirrorReflection(3, 1) == 1);
    assert(s.mirrorReflection(5, 2) == 0);
    return 0;
}
#endif
