
// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>
#include <numeric>
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
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeaf(root, 0);
    }
    int sumRootToLeaf(TreeNode *node, unsigned base) {
        base <<= 1;
        // cout<<base<<" "<<node->val<<std::endl;
        if (node->val) {
            base |= 1;
        }
        
        int ret = 0;
        if (node->left) {
            ret += sumRootToLeaf(node->left, base);
        }
        if (node->right) {
            ret += sumRootToLeaf(node->right, base);
        }
        if (ret > 0) {
            return ret;
        }
        return base;
    }
};

#ifdef LEETCODE
TreeNode *buildTree(vector<int> &vals) {
    vector<TreeNode*> nodes(vals.size());
    for (int i = vals.size() - 1; i >= 0; i--) {
        // cout<<i<<" ";
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
    vector<int> v1{1,0,1,0,1,0,1};
    TreeNode *tree = buildTree(v1);
    assert(s.sumRootToLeaf(tree) == 22);

    return 0;
}
#endif
