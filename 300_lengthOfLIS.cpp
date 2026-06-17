//
// Created by dkdoking on 2026/6/15.
//
#include <bits/stdc++.h>
using namespace std;

/**
 * 定义dp[i]:以nums[i]结尾的最大递增子序列的长度（定义时，尽可能让状态唯一）
 * 那么，dp[i]的大小，其实和dp[i-1]以及nums[i]有关系，如果nums[i]严格大于nums[i-1]，则dp[i]=dp[i-1]+1，否则dp[i+1]=dp[i]
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp[0] = 1;
        for (int i = 1;i < n; i++) {
            if (nums[i] > nums[i-1]) {
                dp[i] = dp[i-1] + 1;
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};