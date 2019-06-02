
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

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> ctmap;  // content=>files
        for (int i = 0; i < paths.size(); i++) {
            string &files = paths[i];
            size_t pos = files.find(' ');
            if (pos == string::npos) {
                continue;
            }
            string directory = files.substr(0, pos);
            directory.append("/");
            pos++;
            while (pos < files.size()) {
                size_t pos2 = files.find('(', pos);
                if (pos2 == string::npos) {
                    break;
                }
                string fname = files.substr(pos, pos2 - pos);
                pos = pos2 + 1;
                pos2 = files.find(')', pos);
                if (pos2 == string::npos) {
                    break;
                }
                string content = files.substr(pos, pos2 - pos);
                pos = pos2 + 2; // skip blank
                ctmap[content].push_back(directory + fname);
            }
        }
        vector<vector<string>> ret;
        for (auto it = ctmap.begin(); it != ctmap.end(); it++) {
            if (it->second.size() < 2) {
                continue;
            }
            ret.push_back(it->second);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    vector<string> p1 = {
        "root/a 1.txt(abcd) 2.txt(efgh)", 
        "root/c 3.txt(abcd)", 
        "root/c/d 4.txt(efgh)", 
        "root 4.txt(efgh)"
    };
    auto ret = s.findDuplicate(p1);
    std::for_each(ret.begin(), ret.end(), [](vector<string> &v) {
        cout<<"[";
        std::for_each(v.begin(), v.end(), [](string &s) {
            cout<<s<<", ";
        });
        cout<<"]"<<std::endl;
    });
    
    return 0;
}
#endif
