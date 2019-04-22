/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (62.30%)
 * Total Accepted:    40.3K
 * Total Submissions: 64.2K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree.  From left to right order, the
 * values of those leaves form a leaf value sequence.
 * 
 * 
 * 
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 * 
 * Two binary trees are considered leaf-similar if their leaf value sequence is
 * the same.
 * 
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Both of the given trees will have between 1 and 100 nodes.
 * 
 * 
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
#include <sstream>
#include <map>
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
using std::map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        vector<int> seq2;
        leafVals(root1, seq1);
        leafVals(root2, seq2);
        if (seq1.size() != seq2.size()) {
            return false;
        }
        for (size_t i = 0; i < seq1.size(); i++) {
            if (seq1[i] != seq2[i]) {
                return false;
            }
        }
        return true;
    }

    void leafVals(TreeNode *root, vector<int> &leaf) {
        if (root == nullptr) {
            return;
        }
        if ((root->left == nullptr) && (root->right == nullptr)) {
            leaf.push_back(root->val);
        }
        if (root->left) {
            leafVals(root->left, leaf);
        }
        if (root->right) {
            leafVals(root->right, leaf);
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

void dumpTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    cout<<root->val<<" ";
    dumpTree(root->left);
    dumpTree(root->right);
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> val1{3,5,1,6,2,9,8,0,0,7,4};
    vector<int> val2{3,4,5,6,3,9,8,0,0,7,4};
    auto tree1 = buildTree(val1);
    auto tree2 = buildTree(val2);
    assert(s.leafSimilar(tree1, tree2));

    vector<int> val3{18,35,22,0,103,43,101,58,0,97};
    vector<int> val4{94,102,17,122,0,0,54,58,101,97};
    tree1 = buildTree(val3);
    dumpTree(tree1);
    tree2 = buildTree(val4);
    dumpTree(tree2);
    assert(!s.leafSimilar(tree1, tree2));
    return 0;
}
#endif

