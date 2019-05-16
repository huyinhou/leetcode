
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
    TreeNode* pruneTree(TreeNode* root) {
        if (root->left) {
            root->left = pruneTree(root->left);
        }
        if (root->right) {
            root->right = pruneTree(root->right);
        }
        if (root->left == nullptr && 
            root->right == nullptr && 
            root->val == 0) {
            return nullptr;
        }
        return root;
    }
};

#ifdef LEETCODE
TreeNode *buildTree(vector<int> &vals) {
    vector<TreeNode*> nodes(vals.size());
    for (int i = vals.size() - 1; i >= 0; i--) {
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

void dumpTree(TreeNode *node) {
    if (node == nullptr) {
        cout<<"null ";
    } else {
        cout<<node->val<<" ";
        dumpTree(node->left);
        dumpTree(node->right);
    }
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {1,-1,0,-1,-1,0,1};
    TreeNode *tree = buildTree(v1);
    dumpTree(tree);
    cout<<std::endl;
    dumpTree(s.pruneTree(tree));
    cout<<std::endl;
    
    vector<int> v2 = {1,0,1,0,0,0,1};
    tree = buildTree(v2);
    dumpTree(s.pruneTree(tree));
    return 0;
}
#endif
