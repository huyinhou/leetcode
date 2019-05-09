/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
#include <map>
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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        // cout<<"pathSum "<<root->val<<" "<<sum<<std::endl;
        int count = withNode(root, sum);
        if (root->left) {
            count += pathSum(root->left, sum);
        }
        if (root->right) {
            count += pathSum(root->right, sum);
        }
        return count;
    }

    // 选该节点
    int withNode(TreeNode* root, int sum) {
        int count = 0;
        // cout<<"withNode "<<root->val<<" "<<sum<<std::endl;
        if (root->val == sum) {
            count++;
        }
        sum -= root->val;
        if (root->left) {
            count += withNode(root->left, sum);
        }
        if (root->right) {
            count += withNode(root->right, sum);
        }
        return count;
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
    vector<int> vals{10,5,-3,3,2,0,11,3,-2,0,1};
    TreeNode *root = buildTree(vals);
    assert(s.pathSum(root, 8) == 3);
    return 0;
}
#endif
