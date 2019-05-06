/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
#include <numeric>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == t) {
            return true;
        }
        if (isSametree(s, t)) {
            return true;
        }
        if (s->left && isSubtree(s->left, t)) {
            return true;
        }
        if (s->right && isSubtree(s->right, t)) {
            return true;
        }
        return false;
    }

    bool isSametree(TreeNode *s, TreeNode *t) {
        if (s == t) {
            return true;
        }
        if (t == nullptr || s == nullptr) {
            return false;
        }
        if (s->val != t->val) {
            return false;
        }
        return isSametree(s->left, t->left) 
            && isSametree(s->right, t->right);
    }
};

#ifdef LEETCODE
TreeNode *buildTree(vector<int> &vals) {
    vector<TreeNode*> nodes(vals.size());
    for (int i = vals.size() - 1; i >= 0; i--) {
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
    vector<int> n1{3, 4, 5, 1, 2};
    TreeNode *t1 = buildTree(n1);
    vector<int> n2{4, 1, 2};
    TreeNode *t2 = buildTree(n2);
    assert(s.isSubtree(t1, t2));
    assert(s.isSubtree(t1, t1));

    vector<int> n3{3, 4, 5, 1, 2, 0, 0, 0, 0, 6};
    TreeNode *t3 = buildTree(n3);
    assert(!s.isSubtree(t3, t2));
    return 0;
}
#endif


