
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
    vector<vector<int>> largeGroupPositions(string S) {
        int start = 0;
        // int length = 0;
        vector<vector<int>> ret;
        for (int pos = 1; pos <= S.size(); pos++) {
            if (pos < S.size()) {
                if (S[pos] == S[pos - 1]) {
                    continue;
                }
            }
            if (pos - start < 3) {
                start = pos;
                continue;
            }
            // cout<<start<<", "<<pos<<std::endl;
            
            ret.push_back(vector<int>{start, pos - 1});
            start = pos;
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    auto ret = s.largeGroupPositions("abbxxxxzzy");
    std::for_each(ret.begin(), ret.end(), [](vector<int> &val) {
        cout<<"["<<val[0]<<", "<<val[1]<<"]"<<std::endl;
    });
    cout<<std::endl;
    ret = s.largeGroupPositions("abc");
    std::for_each(ret.begin(), ret.end(), [](vector<int> &val) {
        cout<<"["<<val[0]<<", "<<val[1]<<"]"<<std::endl;
    });
    cout<<std::endl;
    ret = s.largeGroupPositions("abcdddeeeeaabbbcdddd");
    std::for_each(ret.begin(), ret.end(), [](vector<int> &val) {
        cout<<"["<<val[0]<<", "<<val[1]<<"]"<<std::endl;
    });

    return 0;
}
#endif
