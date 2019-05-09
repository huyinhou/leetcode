
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
#include <algorithm>
#include <map>
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
    int findTilt(TreeNode* root) {
        int tilt = 0;
        treeSumAndTilt(root, &tilt);
        return tilt;
    }

    int treeSumAndTilt(TreeNode *root, int *tilt) {
        if (root == nullptr) {
            return 0;
        }
        int left = 0;
        if (root->left) {
            left = treeSumAndTilt(root->left, tilt);
        }
        int right = 0;
        if (root->right) {
            right = treeSumAndTilt(root->right, tilt);
        }
        *tilt += abs(left - right);
        return left + right + root->val;
    }
};

#ifdef LEETCODE
TreeNode *buildTree(vector<int> &vals) {
    vector<TreeNode*> nodes(vals.size());
    for (int i = vals.size() - 1; i >= 0; i--) {
        if (!vals[i]) {
            continue;
        }
        TreeNode *node = new TreeNode(vals[i]);
        node->val = vals[i];
        int child = 2 * i + 1;
        if (child < vals.size() && vals[child]) {
            node->left = nodes[child];
        }
        child++;
        if (child < vals.size() && vals[child]) {
            node->right = nodes[child];
        }
        nodes[i] = node;
    }
    return nodes[0];
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> vals {1,2,3};
    TreeNode * tree = buildTree(vals);
    assert(s.findTilt(tree) == 1);
    assert(s.findTilt(nullptr) == 0);
    vector<int> v2{1,2,3,0,4};
    tree = buildTree(v2);
    assert(s.findTilt(tree) == 7);
    return 0;
}
#endif


