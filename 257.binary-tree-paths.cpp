/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (45.17%)
 * Total Accepted:    213.2K
 * Total Submissions: 471.9K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
#include <cstddef>

#include <iostream>

using std::cout;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() {}
};
#endif

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using std::vector;
using std::string;
using std::ostringstream;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) {
            return m_paths;
        }
        vector<int> path;
        dlr(root, path);
        return m_paths;
    }

    void dlr(TreeNode *node, vector<int> &path) {
        bool leaf = true;
        path.push_back(node->val);
        if (node->left) {
            dlr(node->left, path);
            leaf = false;
        } 
        if (node->right) {
            dlr(node->right, path);
            leaf = false;
        }
        if (leaf) { // dump path
            ostringstream oss;
            vector<int>::iterator it = path.begin();
            oss<<*it++;
            std::for_each(it, path.end(), [&oss](int num) {
                oss<<"->"<<num;
            });
            m_paths.push_back(oss.str());
        }
        path.pop_back();
    }

private:
    vector<string> m_paths;
};

#ifdef LEETCODE

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

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 0, 5, 6, 7, 8, 0, 0, 9};
    vector<TreeNode> tree;
    makeTree(nums, tree);
    vector<string> ret = s.binaryTreePaths(&tree[0]);
    ostringstream oss;
    std::for_each(ret.begin(), ret.end(), [&oss](string &p) {
        oss<<p<<std::endl;
    });
    cout << oss.str();
    return 0;
}
#endif
