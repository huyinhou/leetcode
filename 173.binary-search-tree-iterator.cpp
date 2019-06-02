
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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root != nullptr) {
            stack.push_back(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *node = stack.back();
        int val = node->val;
        stack.pop_back();
        node = node->right;
        while (node != nullptr) {
            stack.push_back(node);
            node = node->left;
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty();
    }

private:
    vector<TreeNode*> stack;
};

#ifdef LEETCODE
TreeNode *buildTree(vector<int> &vals) {
    vector<TreeNode*> nodes(vals.size());
    for (int i = vals.size() - 1; i >= 0; i--) {
        // cout<<i<<" ";
        if (vals[i] < 0) {
            continue;
        }
        TreeNode *node = new TreeNode(vals[i]);
        node->val = vals[i];
        int child = 2 * i + 1;
        if (child < vals.size() && vals[child] >= 0) {
            node->left = nodes[child];
        }
        child++;
        if (child < vals.size() && vals[child] >= 0) {
            node->right = nodes[child];
        }
        nodes[i] = node;
    }
    return nodes[0];
}

int main(int argc, char *argv[]) {
    vector<int> v1 = {7,3,15,-1,-1,9,20};
    TreeNode *tree = buildTree(v1);
    BSTIterator it(tree);
    while(it.hasNext()) {
        cout<<it.next()<<" ";
    }
    return 0;
}
#endif
