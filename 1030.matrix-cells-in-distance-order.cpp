
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#endif

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<bool> flags(R * C);
        vector<vector<int>> ret;

        ret.push_back(vector<int>{r0, c0});
        flags.at(r0 * C + c0) = true;
        for (size_t i = 0; i < ret.size(); i++) {
            vector<int> cell = ret[i];
            int idx = cell[0] * C + cell[1];

            vector<int> tmp = cell;
            // cout<<cell[0]<<", "<<cell[1]<<" "<<idx<<std::endl;
            if ((--tmp[0] >= 0) && !flags.at(idx - C)) {
                ret.push_back(tmp);
                flags.at(idx - C) = true;
            }

            tmp = cell;
            if ((++tmp[0] < R) && !flags.at(idx + C)) {
                ret.push_back(tmp);
                flags.at(idx + C) = true;
            }
            
            tmp = cell;
            if ((--tmp[1] >= 0) && !flags.at(idx - 1)) {
                ret.push_back(tmp);
                flags.at(idx - 1) = true;
            }

            tmp = cell;
            if ((++tmp[1] < C) && !flags.at(idx + 1)) {
                ret.push_back(tmp);
                flags.at(idx + 1) = true;
            }
        }
        return ret;
    }
};


#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    auto ret = s.allCellsDistOrder(1,2,0,0);
    for_each(ret.begin(), ret.end(), [](vector<int> &cell) {
        cout<<"["<<cell[0]<<", "<<cell[1]<<"], ";
    });
    cout<<std::endl;

    ret = s.allCellsDistOrder(2,2,0,1);
    for_each(ret.begin(), ret.end(), [](vector<int> &cell) {
        cout<<"["<<cell[0]<<", "<<cell[1]<<"], ";
    });
    cout<<std::endl;

    ret = s.allCellsDistOrder(2,3,1,2);
    for_each(ret.begin(), ret.end(), [](vector<int> &cell) {
        cout<<"["<<cell[0]<<", "<<cell[1]<<"], ";
    });
    cout<<std::endl;

    ret = s.allCellsDistOrder(4,3,1,2);
    for_each(ret.begin(), ret.end(), [](vector<int> &cell) {
        cout<<"["<<cell[0]<<", "<<cell[1]<<"], ";
    });
    cout<<std::endl;
    return 0;
}
#endif
