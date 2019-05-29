
#define LEETCODE
#ifdef LEETCODE
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <string>
#include <ostream>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        vector<TreeNode*> right;
        right.push_back(root);
        while(!right.empty()) {
            TreeNode *node = right.back();
            right.pop_back();
            while (node != nullptr) {
                ret.push_back(node->val);
                if (node->right != nullptr) {
                    right.push_back(node->right);
                }
                node = node->left;
            }
        }
        return ret;
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
    vector<int> v1 = {1,0,2,0,0,3};
    TreeNode *tree = buildTree(v1);
    auto ret = s.preorderTraversal(tree);
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    
    vector<int> v2 = {1,2,3,4,0,5};
    tree = buildTree(v2);
    ret = s.preorderTraversal(tree);
    std::copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
