
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
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }    
        maxAncestorDiffTree(root, root->val, root->val);
        return maxdiff;
    }

    void maxAncestorDiffTree(TreeNode* root, int max, int min) {
        max = std::max(max, root->val);
        min = std::min(min, root->val);
        // cout<<max<<", "<<min<<std::endl;
        maxdiff = std::max(maxdiff, max - min);
        if (root->left) {
            maxAncestorDiffTree(root->left, max, min);
        }
        if (root->right) {
            maxAncestorDiffTree(root->right, max, min);
        }
    }

private:
    int maxdiff;
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
    vector<int> v1 = {8,3,10,1,6,-1,14,-1,-1,4,7,-1,-1,13};
    TreeNode *tree = buildTree(v1);
    cout<<s.maxAncestorDiff(tree);
    assert(s.maxAncestorDiff(tree) == 7);
    return 0;
}
#endif
