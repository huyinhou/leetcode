/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
 *
 * https://leetcode.com/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (67.47%)
 * Total Accepted:    27.7K
 * Total Submissions: 41.3K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * A binary tree is univalued if every node in the tree has the same value.
 * 
 * Return true if and only if the given tree is univalued.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,1,1,1,1,null,1]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,5,2]
 * Output: false
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be in the range [1, 100].
 * Each node's value will be an integer in the range [0, 99].
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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isUniValTreeWithVal(root->left, root->val) &&
            isUniValTreeWithVal(root->right, root->val);
    }

    bool isUniValTreeWithVal(TreeNode* root, int val) {
        if (root == nullptr) {
            return true;
        }
        if (root->val != val) {
            return false;
        }
        return isUniValTreeWithVal(root->left, val) &&
            isUniValTreeWithVal(root->right, val);
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
    vector<int> vals{2,2,2,2,3};
    vector<TreeNode> nodes;
    buildTree(vals, nodes);
    assert(s.isUnivalTree(&nodes[0]) == false);

    vector<int> v2{1,1,1,1,1,1};
    buildTree(v2, nodes);
    assert(s.isUnivalTree(&nodes[0]));
    return 0;
}
#endif
