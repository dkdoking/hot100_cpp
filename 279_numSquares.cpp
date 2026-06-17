//
// Created by dkdoking on 2026/6/13.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        //dp[i]表示组成i的平方数的最小个数
        //dp[0] = 0;
        //dp[1] = 1
        vector<int> dp(n+1);
        //组成i的平方数的最大个数是i个1，所以先初始化
        for (int i = 1; i<dp.size();i++) {
            dp[i] = i;
        }
        //然后再来优化
        for (int j = 1; j < dp.size();j++) {
            //假如求dp[15],那么dp[15]=min{dp[15],dp[14]+1,dp[11]+1,dp[6]+1}
            for (int k = 1;j - k*k >=0;k++) {
                dp[j] = min(dp[j],dp[j-k*k]+1);
            }
        }
        return dp[n];
    }
};