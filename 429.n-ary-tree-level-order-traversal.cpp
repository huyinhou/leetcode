/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (58.50%)
 * Total Accepted:    27.7K
 * Total Submissions: 47.1K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * We should return its level order traversal:
 * 
 * 
 * [
 * ⁠    [1],
 * ⁠    [3,2,4],
 * ⁠    [5,6]
 * ]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The depth of the tree is at most 1000.
 * The total number of nodes is at most 5000.
 * 
 * 
 */

// #define LEETCODE
#ifdef LEETCODE
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

#include <deque>
#include <iterator>
using std::deque;
using std::back_inserter;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        deque<Node*> level;
        vector<vector<int> > result;
        if (root == nullptr) {
            return result;
        }
        level.push_back(root);
        while (!level.empty()) {
            deque<Node*> child;
            vector<int> line;

            do {
                Node *n = level.front();
                line.push_back(n->val);
                std::copy(n->children.begin(), n->children.end(), back_inserter(child));
                level.pop_front();
            } while(!level.empty());
            result.push_back(line);
            level.swap(child);
        }
        return result;
    }
};


#ifdef LEETCODE
#include <iostream>
#include <cassert>
#include <sstream>
using std::ostringstream;

void buildTree(vector<int> &nodes, vector<Node> &tree, int nchild) {
    tree.resize(nodes.size());
    for (size_t i = 0; i < nodes.size(); i++) {
        tree[i].val = nodes[i];
        cout<<nodes[i]<<" - ";
        for (int j = i * nchild + 1; (j < nodes.size()) && (j <= (i + 1) * nchild); j++) {
            tree[i].children.push_back(&tree[j]);
            cout<<tree[j].val<<", ";
        }
        cout<<std::endl;
    }
}

int main(int argc, char *argv[]) {
    vector<int> nodes = {1, 2, 3, 4, 5, 6};
    vector<Node> tree;
    buildTree(nodes, tree, 2);
    Solution s;
    auto result = s.levelOrder(&tree[0]);
    for (auto it = result.begin(); it != result.end(); it++) {
        std::copy(it->begin(), it->end(), std::ostream_iterator<int>(cout, ", "));
        cout<<std::endl;
    }
    tree.clear();
    buildTree(nodes, tree, 3);
    result = s.levelOrder(&tree[0]);
    for (auto it = result.begin(); it != result.end(); it++) {
        std::copy(it->begin(), it->end(), std::ostream_iterator<int>(cout, ", "));
        cout<<std::endl;
    }
    return 0;
}
#endif

