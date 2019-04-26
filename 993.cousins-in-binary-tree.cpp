/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
#include <stack>
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
    bool isCousins(TreeNode* root, int x, int y) {
        stack<TreeNode*> nodes;
        stack<int> level;
        TreeNode *curr = root, *parent = nullptr;
        int xl = 0, yl = 0;
        TreeNode *xp = nullptr, *yp = nullptr;
        int curlvl = 0;
        while (curr || !nodes.empty()) {
            while (curr) {
                // visit this node
                if (curr->val == x) {
                    xl = curlvl;
                    xp = parent;
                }
                if (curr->val == y) {
                    yl = curlvl;
                    yp = parent;
                }
                // cout<<curr->val<<" "<<curlvl<<std::endl;
                nodes.push(curr);
                level.push(++curlvl);
                parent = curr;
                curr = curr->left;
            }
            if (!nodes.empty()) {
                curr = nodes.top();
                curlvl = level.top();
                nodes.pop();
                level.pop();
                parent = curr;
                curr = curr->right;
            }
        }
        // cout<<xl<<" "<<yl<<std::endl;
        return (xl == yl) && (xp != yp);
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

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1 = {
        1,2,3,0,4,0,5
    };
    TreeNode *tree = buildTree(v1);
    assert(!s.isCousins(tree, 1, 2));
    assert(!s.isCousins(tree, 2, 2));
    assert(!s.isCousins(tree, 2, 3));
    assert(s.isCousins(tree, 4, 5));
    assert(!s.isCousins(tree, 2, 5));
    return 0;
}
#endif

