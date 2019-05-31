
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
#endif

struct index_info {
    short node;
    short index;

    index_info() : node(0), index(0) {}
    index_info(short n) : node(n), index(0) {}
};

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ret;
        vector<index_info> s;
        s.push_back(index_info(0));
        while(!s.empty()) {
            auto back = s.rbegin();
            vector<int> &node = graph[back->node];
            if (back->index >= node.size()) {
                s.pop_back();
                if (s.empty()) {
                    break;
                }
                s.rbegin()->index++;
                continue;
            }
            int next = node[back->index];
            if (next == graph.size() - 1) {
                // 提取结果
                ret.resize(ret.size() + 1);
                std::for_each(s.begin(), s.end(), [&ret](index_info &v) {
                    ret.rbegin()->push_back(v.node);
                });
                ret.rbegin()->push_back(next);
                back->index++;
            } else if (graph[next].empty()) {
                back->index++;
            } else {    // 中间节点
                s.push_back(index_info(next));
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v1 = {
        {1,2},
        {3},
        {3},
        {}
    };
    auto ret = s.allPathsSourceTarget(v1);
    std::for_each(ret.begin(), ret.end(), [](vector<int> &v) {
        std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
        cout<<std::endl;
    });

    vector<vector<int>> v2 = {
        {1},
        {2,3},
        {3,4},
        {},
        {},
    };
    ret = s.allPathsSourceTarget(v2);
    std::for_each(ret.begin(), ret.end(), [](vector<int> &v) {
        std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
        cout<<std::endl;
    });
    return 0;
}
#endif
