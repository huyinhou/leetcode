
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
using namespace std;
#endif

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            vector<char> &row = board[i];
            for (int j = 0; j < row.size(); j++) {
                if (row[j] == word[0]
                    && existAt(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool existAt(vector<vector<char>>& board, int r, int c, string &word, int i) {
        static struct delta {
            int x;
            int y;
        } delta_array[]= {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };
        // cout<<r<<" "<<c<<" "<<i<<std::endl;
        if (++i == word.size()) {
            return true;
        }
        char ch = board[r][c];
        board[r][c] = 0;
    
        // 找下一个位置
        bool found = false;
        for (int k = 0; k < sizeof(delta_array) / sizeof(delta); k++) {
            int r1 = r + delta_array[k].x;
            int c1 = c + delta_array[k].y;
            if (r1 < 0 || r1 >= board.size()
                || c1 < 0 || c1 >= board[0].size()) {
                continue;
            }
            if (board[r1][c1] != word[i]) {
                continue;
            }
            if (existAt(board, r1, c1, word, i)) {
                found = true;
                break;
            }
        }
        board[r][c] = ch;
        return found;
    }
};



#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<char>> v1 = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    assert(s.exist(v1, "ABCCED"));
    assert(s.exist(v1, "SEE"));
    assert(!s.exist(v1, "ABCB"));
    return 0;
}
#endif
