/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 *
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (38.19%)
 * Total Accepted:    121.4K
 * Total Submissions: 317.8K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a stack using queues.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * 
 * 
 * Example:
 * 
 * 
 * MyStack stack = new MyStack();
 * 
 * stack.push(1);
 * stack.push(2);  
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 * 
 * Notes:
 * 
 * 
 * You must use only standard operations of a queue -- which means only push to
 * back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may
 * simulate a queue by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 * 
 * 
 */
#include <queue>
using std::queue;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        qa = new queue<int>();
        qb = new queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        qa->push(x);
        while (!qb->empty()) {
            qa->push(qb->front());
            qb->pop();
        }
        queue<int> *tmp = qa;
        qa = qb;
        qb = tmp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = qb->front();
        qb->pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return qb->front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return qb->empty();
    }

private:
    queue<int> *qa;
    queue<int> *qb;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
// #define LEETEST
#ifdef LEETEST
#include <cassert>

int main(int argc, char *argv[]) {
    MyStack obj;
    obj.push(1);
    obj.push(2);
    assert(obj.top() == 2);
    assert(obj.pop() == 2);
    assert(obj.top() == 1);
    assert(!obj.empty());
    assert(obj.pop() == 1);
    assert(obj.empty());
    return 0;
}
#endif
