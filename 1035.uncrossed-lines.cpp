
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

struct index_info {
    vector<int> aindex;
    vector<int> bindex;
};

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> count(A.size(), vector<int>(B.size()));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    if (i > 0 && j > 0) {
                        count[i][j] = 1 + count[i - 1][j - 1];
                    } else {
                        count[i][j] = 1;
                    }
                } else {
                    if (j > 0) {
                        count[i][j] = count[i][j - 1];
                    }
                    if (i > 0) {
                        count[i][j] = std::max(count[i][j], count[i - 1][j]);
                    }
                }
            }
        }
        return *(count.rbegin()->rbegin());
    }

};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> a1 = {1,4,2};
    vector<int> b1 = {1,2,4};
    assert(s.maxUncrossedLines(a1, b1) == 2);

    vector<int> a2 = {2,5,1,2,5};
    vector<int> b2 = {10,5,2,1,5,2};
    assert(s.maxUncrossedLines(a2, b2) == 3);

    vector<int> a3 = {1,3,7,1,7,5};
    vector<int> b3 = {1,9,2,5,1};
    assert(s.maxUncrossedLines(a3, b3) == 2);
    return 0;
}
#endif
