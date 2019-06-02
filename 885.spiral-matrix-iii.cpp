
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
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int steps[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1,0}
        };

        int visited = 1;
        int next = 0;
        vector<bool> flags(R * C);
        vector<vector<int>> ret;
        ret.push_back(vector<int>{r0, c0});
        flags[r0 * C + c0] = true;

        while (visited < R * C) {
            int r1 = r0 + steps[next][0];
            int c1 = c0 + steps[next][1];
            cout<<r1<<", "<<c1<<std::endl;
            if (r1 < 0 || r1 >= R 
                || c1 < 0 || c1 >= C) {
                r0 = r1;
                c0 = c1;
                next = (next + 1) % 4;
                continue;
            }
            int index = r1 * C + c1;
            if (flags[index]) {
                next = (next + 3) % 4;
                continue;
            }
            r0 = r1;
            c0 = c1;
            ret.push_back(vector<int>{r0, c0});
            flags[index] = true;
            next = (next + 1) % 4;
            visited++;
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    auto ret = s.spiralMatrixIII(1, 4, 0, 0);
    std::for_each(ret.begin(), ret.end(), [](vector<int> &v) {
        cout<<"["<<v[0]<<", "<<v[1]<<"]"<<std::endl;
    });
    cout<<std::endl;

    ret = s.spiralMatrixIII(5, 6, 1, 4);
    std::for_each(ret.begin(), ret.end(), [](vector<int> &v) {
        cout<<"["<<v[0]<<", "<<v[1]<<"]"<<std::endl;
    });
    cout<<std::endl;
    return 0;
}
#endif
