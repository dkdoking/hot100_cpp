//
// Created by dkdoking on 2026/6/20.
//
#include <bits/stdc++.h>
using namespace std;
//核心思路就是参考K神
//当遇到众数，投票+1，遇到非众数，投票-1，最后肯定是票数>0.
//在遍历的时候，如果发生票数=0的情况，只可能是前面众数和非众数两两抵消，或者非众数和非众数两两抵消，这并不会影响数组里剩余元素和的正负
//前面相互抵消的情况，只有两个结局，1是非众数之间抵消了，2是众数和非众数抵消了，但这两个结局都不会影响剩余数组的状态，所以能一直坐下去，到最后剩最后的数组
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int votes = 0;
        int x = 0;
        for (int num : nums) {
            if (votes == 0) x = num;
            if (num == x) {
                votes++;
            } else {
                votes--;
            }
        }
        return x;
    }
};