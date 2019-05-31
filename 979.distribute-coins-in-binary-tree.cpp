
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
    int distributeCoins(TreeNode* root) {
        int ln = 0, rn = 0, lv= 0, rv = 0;
        int moves = 0;
        if (root == nullptr) {
            return 0;
        }
        if (root->left) {
            moves += distributeSubTree(root->left, ln, lv);
        }
        if (root->right) {
            moves += distributeSubTree(root->right, rn, rv);
        }
        return moves;
    }

    int distributeSubTree(TreeNode *root, int &nodes, int &vals) {
        int ln = 0, rn = 0, lv= 0, rv = 0;
        int moves = 0;
        if (root->left) {
            moves += distributeSubTree(root->left, ln, lv);
        }
        if (root->right) {
            moves += distributeSubTree(root->right, rn, rv);
        }

        nodes = ln + rn + 1;
        vals = lv + rv + root->val;
        moves += std::abs(nodes - vals);
        return moves;
    }
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
    vector<int> v1 = {3,0,0};
    TreeNode *tree = buildTree(v1);
    assert(s.distributeCoins(tree) == 2);

    vector<int> v2 = {0,3,0};
    tree = buildTree(v2);
    assert(s.distributeCoins(tree) == 3);
    return 0;
}
#endif
