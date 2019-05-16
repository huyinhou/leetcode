
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

class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front();
            nodes.push_back(node);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
            q.pop();
        }
    }
    
    int insert(int v) {
        int idx = nodes.size();
        TreeNode *n = new TreeNode(v);
        TreeNode *p = nodes[(idx - 1) / 2];
        if (idx % 2 != 0) { // right
            p->left = n;
        } else {
            p->right = n;
        }
        nodes.push_back(n);
        return p->val;
    }
    
    TreeNode* get_root() {
        return nodes[0];
    }

public:
    vector<TreeNode*> nodes;
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
    vector<int> v1 = {1,2,3,4,5,6};
    TreeNode *root = buildTree(v1);
    CBTInserter cbt(root);
    assert(cbt.insert(7) == 3);
    assert(cbt.insert(8) == 4);
    assert(cbt.insert(9) == 4);
    return 0;
}
#endif
