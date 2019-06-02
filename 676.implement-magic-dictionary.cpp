
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

class MagicDictionary {
private:
    map<size_t, vector<string>> valmap;

public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        valmap.clear();
        for (size_t i = 0; i < dict.size(); i++) {
            vector<string> &vals = valmap[dict[i].size()];
            vals.push_back(dict[i]);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        auto it = valmap.find(word.size());
        if (it == valmap.end()) {
            return false;
        }
        for (int i = 0; i < it->second.size(); i++) {
            string &temp = it->second[i];
            int count = 0;
            for (int j = 0; j < word.size() && count < 2; j++) {
                if (word[j] != temp[j]) {
                    count++;
                }
            }
            if (count == 1) {
                return true;
            }
        }
        return false;
    }
};


#ifdef LEETCODE
int main(int argc, char *argv[]) {
    MagicDictionary s;
    vector<string> v1 = {"hello", "hallo", "leetcode"};
    s.buildDict(v1);
    assert(s.search("aello"));
    assert(s.search("hello"));
    assert(!s.search("hell"));
    assert(!s.search("leetcoded"));
    return 0;
}
#endif
