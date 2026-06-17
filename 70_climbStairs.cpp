//
// Created by dkdoking on 2026/6/11.
//
#include <bits/stdc++.h>
using namespace std;

/**
 * 每次可以爬一个台阶或者两个台阶
 * dp[i]表示爬到第i个楼梯有多少种方法
 * 其实可以很容易联想到，爬到第n个楼梯，要么是从n-1个楼梯跨一步爬上来，要么从n-2个楼梯跨两步爬上来，所以：
 * dp[i] = dp[i-1] + dp[i-2]
 * 那么dp[0]是多少呢？爬到0层台阶，dp[0]=1,dp[1] = 1,dp[2] = dp[0]+dp[1]=2,dp[3] = dp[3] = 1+2=3
 */
class Solution {
public:
    /**
     *
     * @param n n阶楼梯
     * @return 爬上n阶楼梯有多少种方法
     */
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        int pre_stair = 1;
        int pre_pre_stair = 1;
        int res = 0;
        //dp[i] = dp[i-1] + dp[i-2] 这个可以用三个变量循环计算
        for (int i = 2;i <= n;i++) {
            res = pre_pre_stair + pre_stair;
            pre_pre_stair = pre_stair;
            pre_stair = res;
        }
        return res;
    }
};