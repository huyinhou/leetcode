
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

struct DistInfo {
    int index;
    unsigned int dist;
};

bool operator<(const DistInfo &l, const DistInfo &r) {
    return l.dist > r.dist;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<DistInfo> dists(points.size());
        auto it = dists.begin();
        for (int i = 0; i < points.size(); i++) {
            vector<int> &p = points[i];
            it->index = i;
            it->dist = p[0] * p[0] + p[1] * p[1];
            it++;
            std::push_heap(dists.begin(), it);
        }
        vector<vector<int>> ret;
        for (int i = 0; i < K; i++) {
            std::pop_heap(dists.begin(), dists.end());
            ret.push_back(points[dists.rbegin()->index]);
            dists.pop_back();
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v1 = {
        {1,3},
        {-2,2}
    };
    auto ret = s.kClosest(v1, 1);
    std::for_each(ret.begin(), ret.end(), [](vector<int> &v) {
        cout<<"["<<v[0]<<", "<<v[1]<<"]"<<std::endl;
    });
    vector<vector<int>> v2 = {
        {3,3},
        {5,-1},
        {-2,4}
    };
    ret = s.kClosest(v2, 2);
    std::for_each(ret.begin(), ret.end(), [](vector<int> &v) {
        cout<<"["<<v[0]<<", "<<v[1]<<"]"<<std::endl;
    });
    return 0;
}
#endif
