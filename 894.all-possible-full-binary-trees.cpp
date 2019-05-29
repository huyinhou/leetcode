
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> ret;

        if (N % 2 == 0) {
            return ret;
        }
        if (N == 1) {
            ret.push_back(new TreeNode(0));
            return ret;
        }

        int remain = N - 1;
        for (int l = 1; l < remain; l+=2) {
            vector<TreeNode*> left = allPossibleFBT(l);
            vector<TreeNode*> right = allPossibleFBT(remain - l);
            auto itl = left.begin();
            while (itl != left.end()) {
                auto itr = right.begin();
                while (itr != right.end()) {
                    TreeNode *node = new TreeNode(0);
                    node->left = *itl;
                    node->right = *itr;
                    ret.push_back(node);
                    itr++;
                }
                itl++;
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
void dumpTree(TreeNode *root) {

}

int main(int argc, char *argv[]) {
    Solution s;
    auto ret = s.allPossibleFBT(1);
    assert(ret.size() == 1);

    ret = s.allPossibleFBT(3);
    assert(ret.size() == 1);

    ret = s.allPossibleFBT(5);
    assert(ret.size() == 2);

    ret = s.allPossibleFBT(7);
    assert(ret.size() == 5);
    return 0;
}
#endif
