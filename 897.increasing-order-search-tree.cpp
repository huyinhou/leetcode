/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 *
 * https://leetcode.com/problems/increasing-order-search-tree/description/
 *
 * algorithms
 * Easy (63.32%)
 * Total Accepted:    26.6K
 * Total Submissions: 41.7K
 * Testcase Example:  '[5,3,6,2,4,null,8,1,null,null,null,7,9]'
 *
 * Given a tree, rearrange the tree in in-order so that the leftmost node in
 * the tree is now the root of the tree, and every node has no left child and
 * only 1 right child.
 * 
 * 
 * Example 1:
 * Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * 
 * ⁠      5
 * ⁠     / \
 * ⁠   3    6
 * ⁠  / \    \
 * ⁠ 2   4    8
 * /        / \ 
 * 1        7   9
 * 
 * Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 * 
 * ⁠1
 * \
 * 2
 * \
 * 3
 * \
 * 4
 * \
 * 5
 * \
 * 6
 * \
 * 7
 * \
 * 8
 * \
 * ⁠                9  
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be between 1 and 100.
 * Each node will have a unique integer value from 0 to 1000.
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
    TreeNode(): val(0) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *head = nullptr;
        if (root == nullptr) {
            return head;
        }
        increaseTree(root, &head);
        return head;
    }

    TreeNode **increaseTree(TreeNode *node, TreeNode **prev) {
        if (node->left != nullptr) {
            prev = increaseTree(node->left, prev);
        }
        *prev = node;
        node->left = nullptr;
        prev = &node->right;
        if (node->right != nullptr) {
            prev = increaseTree(node->right, prev);
        }
        return prev;
    }
};

#ifdef LEETCODE
void buildTree(vector<int> &vals, vector<TreeNode> &nodes) {
    nodes.resize(vals.size());
    for (size_t i = 0; i < vals.size(); i++) {
        if (!vals[i]) {
            continue;
        }
        nodes[i].val = vals[i];
        int child = 2 * i + 1;
        if (child < vals.size() && vals[child]) {
            nodes[i].left = &nodes[child];
        }
        child++;
        if (child < vals.size() && vals[child]) {
            nodes[i].right = &nodes[child];
        }
    }
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> vals{5,3,6,2,4,0,8,1,0,0,0,0,0,7,9};
    vector<TreeNode> nodes;
    buildTree(vals, nodes);
    auto head = s.increasingBST(&nodes[0]);
    assert(head != nullptr) ;
    while(head != nullptr) {
        cout<<head->val<<", ";
        head = head->right;
    }
    return 0;
}
#endif
