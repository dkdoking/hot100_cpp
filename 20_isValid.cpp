//
// Created by dkdoking on 2026/6/8.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] == '('||s[i] =='['||s[i] =='{') {
                stack.push(s[i]);
            }
            if (s[i] == ')') {
                if (stack.empty()) return false;
                char val = stack.top();
                stack.pop();
                if (!(val== '(')) {
                    return false;
                }

            } else if (s[i] == ']') {
                if (stack.empty()) return false;
                char val1 = stack.top();
                stack.pop();
                if (!(val1 == '[')) {
                    return false;
                }
            } else if (s[i] == '}') {
                if (stack.empty()) return false;
                char val2 = stack.top();
                stack.pop();
                if (!(val2== '{')) {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};
int main() {
    Solution sol;
    sol.isValid("]");
}