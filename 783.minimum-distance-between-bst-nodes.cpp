/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// #define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <map>
#include <vector>
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
    int minDiffInBST(TreeNode* root) {
        int diff = INT_MAX;
        TreeNode *prev = nullptr;
        inOrderBST(root, prev, diff);
        return diff;
    }

    void inOrderBST(TreeNode *root, TreeNode *&prev, int &diff) {
        int dist = 0;
        if (root->left != nullptr) {
            inOrderBST(root->left, prev, diff);
        }
        if (prev) {
            dist = abs(prev->val - root->val);
            if (diff > dist) {
                diff = dist;
            }
        }
        prev = root;
        if (root->right) {
            inOrderBST(root->right, prev, diff);
        }
    }
};

#ifdef LEETCODE
TreeNode *buildTree(vector<int> &vals) {
    vector<TreeNode*> nodes(vals.size());
    for (int i = vals.size() - 1; i >= 0; i--) {
        // cout<<i<<" ";
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
    vector<int> t1{4,2,6,1,3};
    TreeNode *r1 = buildTree(t1);
    assert(1 == s.minDiffInBST(r1));
    vector<int> t2{8,5,14,1,7,11};
    TreeNode *r2 = buildTree(t2);
    assert(1 == s.minDiffInBST(r2));
    return 0;
}
#endif

