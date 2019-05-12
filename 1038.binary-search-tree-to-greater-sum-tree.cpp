
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
    TreeNode* bstToGst(TreeNode* root) {
        greatSum(root, 0);
        return root;
    }

    int greatSum(TreeNode* root, int sum) {
        if (root->right) {
            sum = greatSum(root->right, sum);
        }
        sum += root->val;
        root->val = sum;
        if (root->left) {
            sum = greatSum(root->left, sum);
        }
        return sum;
    }
};

#ifdef LEETCODE
void buildTree(vector<int> &vals, vector<TreeNode*> &nodes) {
    // vector<TreeNode*> nodes(vals.size());
    nodes.resize(vals.size());
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
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<TreeNode*> nodes;
    vector<int> v1 = {4,1,6,1,2,5,7,0,0,0,3,0,0,0,8};
    buildTree(v1, nodes);
    // TreeNode *root = buildTree(v1);
    s.bstToGst(nodes[0]);
    std::for_each(nodes.begin(), nodes.end(), [](TreeNode *node) {
        if (node == nullptr) {
            cout<<"0 ";
        } else {
            cout<<node->val<<" ";
        }
    });
    return 0;
}
#endif
