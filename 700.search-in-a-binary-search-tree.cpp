/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
 *
 * https://leetcode.com/problems/search-in-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (66.99%)
 * Total Accepted:    51.9K
 * Total Submissions: 76.8K
 * Testcase Example:  '[4,2,7,1,3]\n2'
 *
 * Given the root node of a binary search tree (BST) and a value. You need to
 * find the node in the BST that the node's value equals the given value.
 * Return the subtree rooted with that node. If such node doesn't exist, you
 * should return NULL.
 * 
 * For example, 
 * 
 * 
 * Given the tree:
 * ⁠       4
 * ⁠      / \
 * ⁠     2   7
 * ⁠    / \
 * ⁠   1   3
 * 
 * And the value to search: 2
 * 
 * 
 * You should return this subtree:
 * 
 * 
 * ⁠     2     
 * ⁠    / \   
 * ⁠   1   3
 * 
 * 
 * In the example above, if we want to search the value 5, since there is no
 * node with value 5, we should return NULL.
 * 
 * Note that an empty tree is represented by NULL, therefore you would see the
 * expected output (serialized tree format) as [], not null.
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
#include <set>
#include <sstream>
using std::vector;
using std::string;
using std::cout;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        } else if (root->val == val) {
            return root;
        }
        return searchBST(root->right, val);
    }
};

#ifdef LEETCODE
void buildTree(vector<int> &vals, vector<TreeNode> &nodes) {
    nodes.resize(vals.size());
    for (size_t i = 0; i < vals.size(); i++) {
        nodes[i].val = vals[i];
        int child = 2 * i + 1;
        if (child < vals.size()) {
            nodes[i].left = &nodes[child];
        }
        child++;
        if (child < vals.size()) {
            nodes[i].right = &nodes[child];
        }
    }
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> vals{4,2,7,1,3};
    vector<TreeNode> nodes;
    buildTree(vals, nodes);
    assert(s.searchBST(&nodes[0], 5) == nullptr);
    assert(s.searchBST(&nodes[0], 7) == &nodes[2]);
    return 0;
}
#endif
