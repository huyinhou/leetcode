/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
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
using namespace std;
#endif

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i0 = 0, j0 = 0;
        for (size_t i = 0; i < board.size(); i++) {
            vector<char> &row = board[i];
            for (size_t j = 0; j < row.size(); j++) {
                if (row[j] == 'R') {
                    i0 = i;
                    j0 = j;
                    goto got_rook;
                }
            }
        }
        cout<<i0<<" "<<j0<<std::endl;
got_rook:
        int result = 0;
        if (capturePawn(board, i0, j0, -1, 0)) {
            result++;
        }
        if (capturePawn(board, i0, j0, 1, 0)) {
            result++;
        }
        if (capturePawn(board, i0, j0, 0, -1)) {
            result++;
        }
        if (capturePawn(board, i0, j0, 0, 1)) {
            result++;
        }
        return result;
    }

    bool capturePawn(vector<vector<char>>& board, int si, int sj, int di, int dj) {
        do {
            si += di;
            sj += dj;
            if (si < 0 || si >= board.size()) {
                return false;
            }
            if (sj < 0 || sj >= board[0].size()) {
                return false;
            }
            char ch = board[si][sj];
            if (ch == '.') {
                continue;
            } else if (ch == 'p') {
                break;
            } else {    // 其他字符
                return false;
            }
        } while(true);
        return true;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<char> > board = {
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','R','.','B','.','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };
    assert(s.numRookCaptures(board) == 2);
    return 0;
}
#endif
