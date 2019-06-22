
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
    vector<int> rightSideView(TreeNode* root) {
        views.clear();
        if (root) {
            rightView(root, 1);
        }
        return views;
    }

private:
    void rightView(TreeNode *root, int level) {
        if (level > views.size()) {
            views.push_back(root->val);
        }
        if (root->right) {
            rightView(root->right, level + 1);
        }
        if (root->left) {
            rightView(root->left, level + 1);
        }
    }

    vector<int> views;
};

#ifdef LEETCODE
TreeNode *buildTree(vector<int> &vals) {
    vector<TreeNode*> nodes(vals.size());
    for (int i = vals.size() - 1; i >= 0; i--) {
        if (vals[i] < 0) {
            continue;
        }
        TreeNode *node = new TreeNode(vals[i]);
        node->val = vals[i];
        int child = 2 * i + 1;
        if (child < vals.size() && vals[child] >= 0) {
            node->left = nodes[child];
        }
        child++;
        if (child < vals.size() && vals[child] >= 0) {
            node->right = nodes[child];
        }
        nodes[i] = node;
    }
    return nodes[0];
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1, 2, 3, -1, 5};
    TreeNode *t1 = buildTree(v1);
    auto ret = s.rightSideView(t1);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int>(cout, ", "));
    return 0;
}
#endif
