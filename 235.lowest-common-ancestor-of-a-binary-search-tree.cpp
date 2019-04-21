/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (43.63%)
 * Total Accepted:    261.6K
 * Total Submissions: 599.5K
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * Output: 6
 * Explanation: The LCA of nodes 2 and 8 is 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * Output: 2
 * Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
 * of itself according to the LCA definition.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the BST.
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

#include <vector>
#include <iostream>
using std::vector;

// #define LEETCODE
#ifdef LEETCODE
#include <cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() {}
};

void printPath(vector<TreeNode*> &path) {
    for (int i = 0; i < path.size(); i++) {
        std::cout<<path[i]->val<<" ";
    }
    std::cout << std::endl;
}
#endif


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return NULL;
        }

        vector<TreeNode*> vp, vq;
        if (!findTreeNode(root, p, vp)) {
            return NULL;
        }
        vp.push_back(root);
        if (!findTreeNode(root, q, vq)) {
            return NULL;
        }
        vq.push_back(root);
        // printPath(vp);
        // printPath(vq);

        vector<TreeNode*>::reverse_iterator ip, iq;
        ip = vp.rbegin();
        iq = vq.rbegin();
        for (; ip != vp.rend() && iq != vq.rend(); ip++, iq++) {
            // std::cout<<(*ip)->val << " "<< (*iq)->val<<std::endl;
            if (*ip != *iq) {
                return *(--ip);
            }
        }
        if (ip == vp.rend()) {
            return *(vp.begin());
        }
        return *(vq.begin());
    }

    bool findTreeNode(TreeNode* root, TreeNode* p, vector<TreeNode*> &path) {
        if (root == p) {
            return true;
        }
        if (root->left != NULL) {
            if (findTreeNode(root->left, p, path)) {
                path.push_back(root->left);
                return true;
            }
        }
        if (root->right != NULL) {
            if (findTreeNode(root->right, p, path)) {
                path.push_back(root->right);
                return true;
            }
        } 
        return false;
    }
};

#ifdef LEETCODE
#include <cassert>

void makeTree(vector<int> &nums, vector<TreeNode> &tree) {
    tree.resize(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            continue;
        }
        tree[i].val = nums[i];
        int left = 2 * i + 1;
        if (left < nums.size()) {
            if (nums[left] != 0) {
                tree[i].left = &tree[left];
            }
        }
        int right = 2 * i + 2;
        if (right < nums.size()) {
            if (nums[right] != 0) {
                tree[i].right = &tree[right];
            }
        }
    }
}

void printTree(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main(int argc, char *argv[]) {
    vector<int> nums = {1, 2, 3, 4, 0, 5, 6, 7, 8, 0, 0, 10, 11};
    vector<TreeNode> tree;
    makeTree(nums, tree);
    printTree(&tree[0]);
    std::cout<<std::endl;

    Solution s;
    assert(s.lowestCommonAncestor(&tree[0], &tree[1], &tree[3]) == &tree[1]);
    assert(s.lowestCommonAncestor(&tree[0], &tree[3], &tree[1]) == &tree[1]);
    assert(s.lowestCommonAncestor(&tree[0], &tree[1], &tree[4]) == NULL);
    assert(s.lowestCommonAncestor(&tree[0], &tree[4], &tree[1]) == NULL);
    assert(s.lowestCommonAncestor(&tree[0], &tree[5], &tree[6]) == &tree[2]);
}
#endif
