//
// Created by dkdoking on 2026/6/22.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        //先找相遇的点
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        //找到后，slow和slow1一起走
        int slow1 = 0;
        while (slow1 != slow) {
            slow = nums[slow];
            slow1 = nums[slow1];
        }
        return slow;
    }
};