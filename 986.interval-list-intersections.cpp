
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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ret;
        if (A.empty() || B.empty()) {
            return ret;
        }
        int i = 0, j = 0;
        vector<int> a = A[0];
        vector<int> b = B[0];
        vector<int> c(2);
        while (i < A.size() && j < B.size()) {
            // cout<<"i="<<i<<", j="<<j<<", a=["<<a[0]<<", "<<a[1]<<"], b=["<<b[0]<<", "<<b[1]<<"]"<<std::endl;
            if (a[0] > b[1]) {  // b在a前
                if ((++j) < B.size()) {
                    b = B[j];
                }
            } else if (b[0] > a[1]) { // a在b前
                if ((++i) < A.size()) {
                    a = A[i];
                }
            } else {
                c[0] = std::max(a[0], b[0]);
                c[1] = std::min(a[1], b[1]);
                ret.push_back(c);
                a[0] = c[1] + 1;
                b[0] = c[1] + 1;
                if (a[0] > a[1]) {
                    if ((++i) < A.size()) {
                       a = A[i];
                    }
                }
                if (b[0] > b[1]) {
                    if ((++j) < B.size()) {
                        b = B[j];
                    }
                }
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v1 = {
        {0,2},{5,10},{13,23},{24,25}
    };
    vector<vector<int>> v2 = {
        {1,5},{8,12},{15,24},{25,26}
    };
    auto ret = s.intervalIntersection(v1, v2);
    std::for_each(ret.begin(), ret.end(), [](vector<int> &v) {
        cout<<"["<<v[0]<<", "<<v[1]<<"]"<<std::endl;
    });
    return 0;
}
#endif
