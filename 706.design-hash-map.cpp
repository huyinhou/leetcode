/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
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

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        memset(&hashVals, 0, sizeof(hashVals));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key % MaxSlots;
        HashKeyVal *list = hashVals[idx];
        while (list != nullptr) {
            if (list->key == key) {
                list->val = value;
                return;
            }
            list = list->next;
        }
        list = new HashKeyVal(key, value);
        list->next = hashVals[idx];
        hashVals[idx] = list;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key % MaxSlots;
        HashKeyVal *list = hashVals[idx];
        while (list != nullptr) {
            if (list->key == key) {
                return list->val;
            }
            list = list->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = key % MaxSlots;
        HashKeyVal **next = &hashVals[idx];
        HashKeyVal *list = hashVals[idx];
        while (list != nullptr) {
            if (list->key == key) {
                *next = list->next;
                delete list;
                break;
            }
            next = &list->next;
            list = list->next;
        }
    }

private:
    static const int MaxSlots = 4999;
    class HashKeyVal {
    public:
        HashKeyVal(int k, int v) : next(nullptr), key(k), val(v) { }

        HashKeyVal *next;
        int key;
        int val;
    };
    HashKeyVal *hashVals[MaxSlots];
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    MyHashMap *obj = new MyHashMap();
    obj->put(1, 2);
    obj->put(5000, 3);
    assert(obj->get(1) == 2);
    assert(obj->get(2) == -1);
    obj->remove(1);
    assert(obj->get(1) == -1);
    assert(obj->get(5000) == 3);
    return 0;
}
#endif

