/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (58.41%)
 * Total Accepted:    13.4K
 * Total Submissions: 22.7K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * Return any binary tree that matches the given preorder and postorder
 * traversals.
 * 
 * Values in the traversals pre and post are distinct positive integers.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * Output: [1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] and post[] are both permutations of 1, 2, ..., pre.length.
 * It is guaranteed an answer exists. If there exists multiple answers, you can
 * return any of them.
 * 
 * 
 * 
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return constructTreeInRange(pre.cbegin(), pre.cend(), post.cbegin(), post.cend());
    }

    typedef vector<int>::const_iterator VIT;
    TreeNode* constructTreeInRange(VIT pre_l, VIT pre_r, VIT post_l, VIT post_r) {
        if (pre_l == pre_r) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(*pre_l);
        pre_l++;
        post_r--;
        if (pre_l == pre_r) {
            return root;
        }
        VIT post_m = std::next(std::find(post_l, post_r, *pre_l));
        VIT pre_m = pre_l + (post_m - post_l);
        root->left = constructTreeInRange(pre_l, pre_m, post_l, post_m);
        root->right = constructTreeInRange(pre_m, pre_r, post_m, post_r);
        return root;
    }
};

#ifdef LEETCODE
void mid_order(TreeNode *n) {
    if (n == nullptr) {
        return;
    }
    mid_order(n->left);
    cout<<n->val<<", ";
    mid_order(n->right);
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{1,2,4,5,3,6,7};
    vector<int> v2{4,5,2,6,7,3,1};
    TreeNode *t = s.constructFromPrePost(v1, v2);
    mid_order(t);
    return 0;
}
#endif

