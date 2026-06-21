//
// Created by dkdoking on 2026/6/20.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        return x;
    }
};