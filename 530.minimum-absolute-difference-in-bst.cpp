/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
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

