
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
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int pattern[26] = {0};
        for (size_t i = 0; i < B.size(); i++) {
            int temp[26] = {0};
            countLetter(B[i], temp);
            for (int j = 0; j < 26; j++) {
                pattern[j] = std::max(pattern[j], temp[j]);
            }
        }
        vector<int> index;
        for (size_t i = 0; i < 26; i++) {
            if (pattern[i]) {
                index.push_back(i);
            }
        }
        vector<string> ret;
        for (size_t i = 0; i < A.size(); i++) {
            int temp[26] = {0};
            countLetter(A[i], temp);
            for (size_t j = 0; j < index.size(); j++) {
                int k = index[j];
                if (temp[k] < pattern[k]) {
                    goto next_loop;
                }
            }
            ret.push_back(A[i]);
            next_loop:
            ;
        }
        return ret;
    }

    void countLetter(string &str, int cnt[26]) {
        for (size_t i = 0;  i < str.size(); i++) {
            cnt[str[i] - 'a']++;
        }
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<string> a1 = {
        "amazon","apple","facebook","google","leetcode"
    };
    vector<string> b1 = {
        "e","o"
    };
    auto ret = s.wordSubsets(a1, b1);
    std::copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, ", "));
    cout<<std::endl;

    vector<string> b2 = {
        "l","e"
    };
    ret = s.wordSubsets(a1, b2);
    std::copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, ", "));
    cout<<std::endl;

    vector<string> b3 = {
        "oo","e"
    };
    ret = s.wordSubsets(a1, b3);
    std::copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, ", "));
    cout<<std::endl;

    vector<string> b4 = {
        "ec","oc","ceo"
    };
    ret = s.wordSubsets(a1, b4);
    std::copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, ", "));
    cout<<std::endl;
    return 0;
}
#endif
