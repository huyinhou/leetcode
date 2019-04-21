/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (64.60%)
 * Total Accepted:    41.1K
 * Total Submissions: 63.1K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given a n-ary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * We should return its max depth, which is 3.
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
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int maxd = 0;
        for (auto it = root->children.begin(); it != root->children.end(); it++) {
            int depth = maxDepth(*it);
            if (maxd < depth) {
                maxd = depth;
            }
        }
        return maxd + 1;
    }
};

#ifdef LEETCODE
void buildTree(vector<int> &vals, vector<Node> &tree) {
    tree.resize(vals.size());
    for (size_t i = 0; i < vals.size(); i++) {
        Node &node = tree[i];
        node.val = vals[i];
        for (int child = 3 * i + 1; child <= 3 * (i + 1) && child < vals.size(); child++) {
            node.children.push_back(&tree[child]);
        }
    }
}
int main(int argc, char *argv[]) {
    Solution s;
    vector<int> vals{1, 3, 2, 4, 5, 6};
    vector<Node> tree;
    buildTree(vals, tree);
    assert(3 == s.maxDepth(&tree[0]));
    return 0;
}
#endif
