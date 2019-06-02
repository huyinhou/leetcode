
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

struct DequeueItem {
    DequeueItem *prev;
    DequeueItem *next;
    int val;

    DequeueItem(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class MyCircularDeque {
private:
    int maxsize;
    int count;
    DequeueItem *head;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        maxsize = k;
        count = 0;
        head = nullptr;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (count >= maxsize) {
            return false;
        }
        DequeueItem *item = new DequeueItem(value);
        count++;
        if (head == nullptr) {
            item->next = item->prev = item;
        } else {
            item->next = head;
            item->prev = head->prev;
            head->prev->next = item;
            head->prev = item;
        }
        head = item;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (count >= maxsize) {
            return false;
        }
        DequeueItem *item = new DequeueItem(value);
        count++;
        if (head == nullptr) {
            head = item;
            item->next = item->prev = item;
        } else {
            item->prev = head->prev;
            item->next = head;
            head->prev->next = item;
            head->prev = item;
        }
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (head == nullptr) {
            return false;
        }
        count--;
        DequeueItem *item = head;
        if (count == 0) {
            head = nullptr;
        } else {
            head->next->prev = head->prev;
            head->prev->next = head->next;
            head = head->next;
        }
        delete item;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (head == nullptr) {
            return false;
        }
        count--;
        DequeueItem *item = head->prev;
        if (count == 0) {
            head = nullptr;
        } else {
            head->prev->prev->next = head;
            head->prev = head->prev->prev;
        }
        delete item;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (head == nullptr) {
            return -1;
        }
        return head->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (head == nullptr) {
            return -1;
        }
        return head->prev->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return head == nullptr;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count == maxsize;
    }
};

#ifdef LEETCODE
int main(int argc, char *argv[]) {
    MyCircularDeque s(3);
    assert(s.insertFront(1));
    assert(s.insertFront(2));
    assert(s.insertFront(3));
    assert(!s.insertFront(4));
    assert(s.getRear() == 1);
    assert(s.getFront() == 3);
    assert(s.deleteLast());
    assert(s.getRear() == 2);
    assert(s.deleteLast());
    assert(s.getRear() == 3);
    assert(s.deleteLast());
    assert(s.getRear() == -1);

    assert(s.insertLast(1));
    assert(s.insertLast(2));
    assert(s.getRear() == 2);
    assert(s.getFront() == 1);
    return 0;
}
#endif
