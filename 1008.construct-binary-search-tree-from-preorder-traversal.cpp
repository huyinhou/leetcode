/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (72.92%)
 * Total Accepted:    8.8K
 * Total Submissions: 12.1K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * Return the root node of a binary search tree that matches the given preorder
 * traversal.
 * 
 * (Recall that a binary search tree is a binary tree where for every node, any
 * descendant of node.left has a value < node.val, and any descendant of
 * node.right has a value > node.val.  Also recall that a preorder traversal
 * displays the value of the node first, then traverses node.left, then
 * traverses node.right.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 * 
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= preorder.length <= 100
 * The values of preorder are distinct.
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};
#endif


class Solution {
public:
    TreeNode *bstFromPreorder(vector<int>& preorder) {
        return bstFromRange(preorder.begin(), preorder.end());
    }

    typedef vector<int>::iterator VIT;
    TreeNode *bstFromRange(VIT start, VIT end) {
        if (start == end) {
            return nullptr;
        }
        int val = *start++;
        TreeNode *node = new TreeNode(val);
        VIT mid = std::lower_bound(start, end, val);
        node->left = bstFromRange(start, mid);
        node->right = bstFromRange(mid, end);
        return node;
    }
};

#ifdef LEETCODE
void preorder(TreeNode *node, vector<int> &vals) {
    if (node == nullptr) {
        return;
    }
    vals.push_back(node->val);
    preorder(node->left, vals);
    preorder(node->right, vals);
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{8,5,1,7,10,12};
    TreeNode *node = s.bstFromPreorder(v1);
    v1.clear();
    preorder(node, v1);
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(cout, ", "));
    return 0;
}
#endif

