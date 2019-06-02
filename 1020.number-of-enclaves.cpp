
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

struct Position {
    int row;
    int col;
    Position(int r, int c) : row(r), col(c) {}
};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        rows = A.size(), cols = A[0].size();
        flags.clear();
        flags.resize(rows * cols);
        
        int index = 0;
        int count = 0;
        
        for (int i = 0; i < A.size(); i++) {
            vector<int> &row = A[i];
            for (int j = 0; j < row.size(); j++, index++) {
                if (row[j] == 0) {
                    flags[index] = true;
                } else {
                    count++;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            if (A[i][0] == 1) {
                count -= bfs(i, 0);
            }
            if (A[i][cols - 1] == 1) {
                count -= bfs(i, cols - 1);
            }
        }
        for (int i = 0; i < cols; i++) {
            if (A[0][i] == 1) {
                count -= bfs(0, i);
            }
            if (A[rows - 1][i] == 1) {
                count -= bfs(rows - 1, i);
            }
        }
        return count;
    }

    int bfs(int r, int c) {
        int index = r * cols + c;
        if (flags[index]) {
            return 0;
        }
        flags[index] = true;
        int total = 0;
        queue<Position> visit;
        visit.push(Position(r, c));
        while (!visit.empty()) {
            total++;
            Position p = visit.front();
            visit.pop();
            for (int i = 0; i < 4; i++) {
                int r1 = p.row + direction[i][0];
                int c1 = p.col + direction[i][1];
                if (r1 < 0 || r1 >= rows) {
                    continue;
                }
                if (c1 < 0 || c1 >= cols) {
                    continue;
                }
                index = r1 * cols + c1;
                if (flags[index]) {
                    continue;
                }
                flags[index] = true;
                visit.push(Position(r1, c1));
            }
        }
        return total;
    }

private:
    vector<bool> flags;
    int rows;
    int cols;
    static int direction[4][2];
};

int Solution::direction[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> v1 = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    assert(s.numEnclaves(v1) == 3);

    vector<vector<int>> v2 = {
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,0}
    };
    assert(s.numEnclaves(v2) == 0);
    return 0;
}
#endif
