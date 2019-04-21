/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
 *
 * https://leetcode.com/problems/flip-equivalent-binary-trees/description/
 *
 * algorithms
 * Medium (65.08%)
 * Total Accepted:    13.1K
 * Total Submissions: 20.2K
 * Testcase Example:  '[1,2,3,4,5,6,null,null,null,7,8]\n[1,3,2,null,6,4,5,null,null,null,null,8,7]'
 *
 * For a binary tree T, we can define a flip operation as follows: choose any
 * node, and swap the left and right child subtrees.
 * 
 * A binary tree X is flip equivalent to a binary tree Y if and only if we can
 * make X equal to Y after some number of flip operations.
 * 
 * Write a function that determines whether two binary trees are flip
 * equivalent.  The trees are given by root nodes root1 and root2.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 =
 * [1,3,2,null,6,4,5,null,null,null,null,8,7]
 * Output: true
 * Explanation: We flipped at nodes with values 1, 3, and 5.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Each tree will have at most 100 nodes.
 * Each value in each tree will be a unique integer in the range [0, 99].
 * 
 * 
 * 
 * 
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
#include <vector>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return (root2 == nullptr);
        }
        if (root2 == nullptr) {
            return (root1 == nullptr);
        }
        if (root1->val != root2->val) {
            return false;
        }
        if (flipEquiv(root1->left, root2->left)) {
            return flipEquiv(root1->right, root2->right);
        }
        if (flipEquiv(root1->left, root2->right)) {
            return flipEquiv(root1->right, root2->left);
        }
        return false;
    }
};

#ifdef LEETCODE
TreeNode* buildTree(vector<int> &vals) {
    vector<TreeNode*> nodes(vals.size());
    nodes[0] = new TreeNode(vals[0]);
    for (size_t i = 1; i < vals.size(); i++) {
        if (vals[i] == 0) {
            continue;
        }
        TreeNode *node = new TreeNode(vals[i]);
        nodes[i] = node;
        int parent = (i - 1) / 2;
        if (i % 2) { // left
            nodes[parent]->left = node;
        } else {
            nodes[parent]->right = node;
        }
    }
    return nodes[0];
}

void dumpPreTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    cout<<root->val<<", ";
    dumpPreTree(root->left);
    dumpPreTree(root->right);
}

void dumpMidTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    dumpMidTree(root->left);
    cout<<root->val<<", ";
    dumpMidTree(root->right);
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{1,2,3,4,5,6,0,0,0,7,8};
    vector<int> v2{1,3,2,0,6,4,5,0,0,0,0,0,0,8,7};
    TreeNode *tree1 = buildTree(v1);
    dumpPreTree(tree1);
    cout<<std::endl;
    TreeNode *tree2 = buildTree(v2);
    dumpPreTree(tree2);
    cout<<std::endl;
    dumpMidTree(tree2);
    cout<<std::endl;
    assert(s.flipEquiv(tree1, tree2));
    return 0;
}
#endif

