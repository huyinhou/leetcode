/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
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
#include <map>
#include <vector>
using namespace std;
#endif

class MyHashSet {
public:
    struct HashKey {
        HashKey(int k) : key(k) { }
        HashKey *next;
        int key;
    };

    /** Initialize your data structure here. */
    MyHashSet() {
        memset(keySet, 0, sizeof(keySet));
    }
    
    void add(int key) {
        int idx = key % MaxSlots;
        HashKey *list = keySet[idx];
        while (list != nullptr) {
            if (list->key == key) {
                return;
            }
            list = list->next;
        }
        list = new HashKey(key);
        list->next = keySet[idx];
        keySet[idx] = list;
    }
    
    void remove(int key) {
        int idx = key % MaxSlots;
        HashKey *list = keySet[idx];
        HashKey **prev = &keySet[idx];
        while (list != nullptr) {
            if (list->key == key) {
                *prev = list->next;
                delete list;
                return;
            }
            prev = &list->next;
            list = list->next;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = key % MaxSlots;
        HashKey *list = keySet[idx];
        while (list != nullptr) {
            if (list->key == key) {
                return true;
            }
            list = list->next;
        }
        return false;
    }

private:
    static const int MaxSlots=4999;
    HashKey *keySet[MaxSlots];
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    MyHashSet hashSet;
    hashSet.add(1);         
    hashSet.add(2);         
    assert(hashSet.contains(1));    // returns true
    assert(!hashSet.contains(3));    // returns false (not found)
    hashSet.add(2);          
    assert(hashSet.contains(2));    // returns true
    hashSet.remove(2);          
    assert(!hashSet.contains(2));    // returns false (already removed)
    return 0;
}
#endif
