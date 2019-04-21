/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 *
 * https://leetcode.com/problems/construct-quad-tree/description/
 *
 * algorithms
 * Easy (54.70%)
 * Total Accepted:    8.8K
 * Total Submissions: 15.8K
 * Testcase Example:  '[[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]'
 *
 * We want to use quad trees to store an N x N boolean grid. Each cell in the
 * grid can only be true or false. The root node represents the whole grid. For
 * each node, it will be subdivided into four children nodes until the values
 * in the region it represents are all the same.
 * 
 * Each node has another two boolean attributes : isLeaf and val. isLeaf is
 * true if and only if the node is a leaf node. The val attribute for a leaf
 * node contains the value of the region it represents.
 * 
 * Your task is to use a quad tree to represent a given grid. The following
 * example may help you understand the problem better:
 * 
 * Given the 8 x 8 grid below, we want to construct the corresponding quad
 * tree:
 * 
 * 
 * 
 * It can be divided according to the definition above:
 * 
 * 
 * 
 * 
 * 
 * The corresponding quad tree should be as following, where each node is
 * represented as a (isLeaf, val) pair.
 * 
 * For the non-leaf nodes, val can be arbitrary, so it is represented as *.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N is less than 1000 and guaranteened to be a power of 2.
 * If you want to know more about the quad tree, you can refer to its wiki.
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
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
#endif

class Solution {
public:
    Node* construct(vector<vector<int> >& grid) {
        size_t n = grid.size();
        vector<Node*> nodes(n * n);
        for (size_t i = 0; i < n; i++) {
            vector<int> &line = grid[i];
            for (size_t j = 0; j < n; j++) {
                nodes[i * n + j]= new Node(line[j] == 1, true, nullptr, nullptr, nullptr, nullptr);
            }
        }
        return buildTree(nodes, n);
    }

    Node *buildTree(vector<Node*> &nodes, size_t n) {
        if (n == 1) {
            return nodes[0];
        }
        size_t np = n / 2; // parent
        cout<<"n="<<n<<", np="<<np<<", size="<<nodes.size()<<std::endl;
        vector<Node*> parent(np * np);
        for (size_t i = 0; i < np; i++) {
            for (size_t j = 0; j < np; j++) {
                // cout<<i<<", "<<j<<std::endl;
                int ntrue = 0, nleaf = 0;
                int top = i * 2, left = j * 2;
                // top, left
                Node *tl = nodes[top * n + left];
                ntrue += tl->val;
                nleaf += tl->isLeaf;
                // top, right
                Node *tr = nodes[top * n + left + 1];
                ntrue += tr->val;
                nleaf += tr->isLeaf;
                // bottom, left
                Node *bl = nodes[(top + 1) * n + left];
                ntrue += bl->val;
                nleaf += bl->isLeaf;
                // bottom, right
                Node *br = nodes[(top + 1) * n + left + 1];
                ntrue += br->val;
                nleaf += br->isLeaf;
                if ((nleaf == 4) && (ntrue % 4 == 0)) {
                    delete tl;
                    delete tr;
                    delete bl;
                    delete br;
                    tl = nullptr;
                    tr = nullptr;
                    bl = nullptr;
                    br = nullptr;
                }
                // cout<<"i="<<i<<", j="<<j<<", val="<<(ntrue == 4)<<", leaf="<<((ntrue == 4) || (ntrue == 0))<<std::endl;
                parent[i * np + j] = new Node(ntrue == 4, 
                    (nleaf == 4) && (ntrue % 4 == 0), tl, tr, bl, br);
            }
        }
        return buildTree(parent, np);
    }
};

#ifdef LEETCODE
#include <iostream>
#include <cassert>
#include <sstream>
using std::ostringstream;

void dumpTree(Node *node, string pad) {
    // ostringstream oss;
    if (node == nullptr) {
        cout<<pad<<"nullptr"<<std::endl;
        return;
    }
    cout<<pad<<"{"<< node->val<<","<<node->isLeaf<<"}"<<std::endl;
    string newpad = pad.append("  ");
    if (node->isLeaf) {
        return;
    }
    dumpTree(node->topLeft, newpad);
    dumpTree(node->topRight, newpad);
    dumpTree(node->bottomLeft, newpad);
    dumpTree(node->bottomRight, newpad);
}

void buildGrid(int *g, int n, vector<vector<int> > &grid) {
    grid.clear();
    for (int i = 0; i < n; i++) {
        vector<int> line;
        for (int j = 0; j < n; j++) {
            // cout<<i<<", "<<j<<", "<<std::endl;
            line.push_back(g[i * n + j]);
        }
        grid.push_back(line);
    }
}

int main(int argc, char *argv[]) {
    int g1[8][8] = {
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0},
        {1,1,1,1,0,0,0,0}
    };
    vector<vector<int> > grid;
    buildGrid((int*)g1, 8, grid);
    cout<<"done"<<std::endl;
    Solution s;
    Node *root = s.construct(grid);
    dumpTree(root, "");

    int g2[8][8] = {
        {1,1,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0},
        {1,1,0,0,0,0,1,1},
        {1,1,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,1,1},
        {1,1,1,1,1,1,0,0},
        {1,1,1,1,1,1,0,0}
    };
    buildGrid((int*)g2, 8, grid);
    root = s.construct(grid);
    dumpTree(root, "");
    return 0;
}
#endif
