//
// Created by dkdoking on 2026/6/8.
//
#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> min_s;

public:
    MinStack() {

    }

    void push(int value) {
        s.push(value);
        if (min_s.empty()||value<min_s.top()) {
            min_s.push(value);
        }
    }

    void pop() {
        if (s.top()==min_s.top()) {
            min_s.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */