/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (66.33%)
 * Total Accepted:    36.9K
 * Total Submissions: 55.2K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the preorder traversal of its nodes' values.
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Return its preorder traversal as: [1,3,5,6,2,4].
 * 
 * 
 * 
 * Note:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
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

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
#endif

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        if (root == nullptr) {
            return ret;
        }
        preorderVisit(root, ret);
        return ret;
    }
    void preorderVisit(Node *root, vector<int> &vals) {
        vals.push_back(root->val);
        std::for_each(root->children.begin(), root->children.end(), [this, &vals](Node *node) {
            preorderVisit(node, vals);
        });
    }
};

#ifdef LEETCODE
void buildTree(vector<int> &vals, vector<Node> &nodes) {
    nodes.resize(vals.size());
    for (size_t i = 0; i < vals.size(); i++) {
        nodes[i].val = vals[i];

        for (int child = 3 * i + 1; child <= 3 * (i + 1) && child < vals.size(); child++) {
            nodes[i].children.push_back(&nodes[child]);
        }
    }
}
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> v1{1,3,2,4,5,6};
    vector<Node> nodes;
    buildTree(v1, nodes);
    auto ret = s.preorder(&nodes[0]);
    std::copy(ret.begin(), ret.end(), std::ostream_iterator<int>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
