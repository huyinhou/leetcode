/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 *
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (75.96%)
 * Total Accepted:    70K
 * Total Submissions: 91.8K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * Note: This is a companion problem to the System Design problem: Design
 * TinyURL.
 * 
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such
 * as http://tinyurl.com/4e9iAk.
 * 
 * Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need
 * to ensure that a URL can be encoded to a tiny URL and the tiny URL can be
 * decoded to the original URL.
 * 
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
#include <sstream>
#include <functional>
#include <vector>
#include <map>
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
#endif

struct urlinfo {
    urlinfo *next;  // 相同hash值的链表
    size_t hash;
    string url;
    urlinfo *pair;  // 另一对地址

    urlinfo(size_t h, string &u) 
        : hash(h), url(u) {
        next = pair = nullptr;
    }
};

class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        init();
        size_t lh = std::hash<string>{}(longUrl);
        urlinfo *lu = find_url(m_long_urlmap, lh, longUrl);
        if (lu != nullptr) {
            return lu->pair->url;
        }
        size_t th = 0;
        urlinfo *tu = nullptr;
        string tinyUrl = "http://tinyurl.com/000000";
        do {
            for (int i = 19; i < 25; i++) {
                tinyUrl[i] = s_letter[rand() % 62];
            }
            // cout<<tinyUrl<<std::endl;
            th = std::hash<string>{}(tinyUrl);
            tu = find_url(m_tiny_urlmap, th, tinyUrl);
            if (tu == nullptr) {
                break;
            }
        } while (true);
        assert(lu == nullptr);
        assert(tu == nullptr);
        lu = new urlinfo(lh, longUrl);
        tu = new urlinfo(th, tinyUrl);
        lu->pair = tu;
        tu->pair = lu;
        insert_url(m_long_urlmap, lu);
        insert_url(m_tiny_urlmap, tu);
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t th = std::hash<string>{}(shortUrl);
        urlinfo *tu = find_url(m_tiny_urlmap, th, shortUrl);
        if (tu == nullptr) {
            return string();
        }
        return tu->pair->url;
    }

    static void init() {
        if (s_inited) {
            return;
        }
        srand(time(nullptr));
        char *p = s_letter;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            *p++ = ch;
        }
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            *p++ = ch;
        }
        for (char ch = '0'; ch <= '9'; ch++) {
            *p++ = ch;
        }
        s_inited = true;
    }
    static char s_letter[62];
    static bool s_inited;

    typedef std::map<size_t, urlinfo*> hashmap;
    urlinfo *find_url(hashmap &map, size_t h, string &url) {
        hashmap::iterator it = map.find(h);
        if (it == map.end()) {
            return nullptr;
        }
        urlinfo *info = it->second;
        while (info != nullptr) {
            if ((info->url.length() == url.length()) 
                && (info->url.compare(url) == 0)) {
                return info;
            }
        }
        return nullptr;
    }

    void insert_url(hashmap &map, urlinfo *info) {
        hashmap::iterator it = map.find(info->hash);
        if (it != map.end()) {
            info->next = it->second;
        }
        map[info->hash] = info;
    }
private:
    hashmap m_long_urlmap;
    hashmap m_tiny_urlmap; 
};

char Solution::s_letter[62] = {0};
bool Solution::s_inited = false;

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    Solution s;
    assert(s.decode(s.encode("http://www.baidu.com")) == "http://www.baidu.com");
    assert(s.decode(s.encode("http://www.google.com")) == "http://www.google.com");
    assert(s.decode(s.encode("http://www.sina.com")) == "http://www.sina.com");
    return 0;
}
#endif


