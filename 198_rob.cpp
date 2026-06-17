//
// Created by dkdoking on 2026/6/13.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[i]定义为从nums[0,1,...,i]中能偷到的最大金额
        //可以倒着来考虑这个问题
        //要计算dp[i]分两种情况：1.第i间房子偷了，那么第i-1间房子就不能偷，所以dp[i] = dp[i-2]+nums[i]
        //2.第i间房子不偷，那么dp[i] = dp [i-1]
        //两者取最大值
        int n = nums.size();
        vector<int> dp(n+1);
        dp[0] = 0;//偷前0间房子最大价值为0
        dp[1] = nums[0];//偷前1间房子最大价值是nums[0]
        if (n==0) return 0;
        if (n==1) return nums[0];
        for (int i = 2;i < n+1 ;i++) {
            dp[i] = max((dp[i-2]+nums[i-1]),dp[i-1]);
        }
        return dp[n];
    }
    int rob2(vector<int>& nums) {
        //dp[i]定义为从nums[0,1,...,i]中能偷到的最大金额
        //可以倒着来考虑这个问题
        //要计算dp[i]分两种情况：1.第i间房子偷了，那么第i-1间房子就不能偷，所以dp[i] = dp[i-2]+nums[i]
        //2.第i间房子不偷，那么dp[i] = dp [i-1]
        //两者取最大值
        //注意到dp[i]只和dp[i-1]、dp[i-2]有关，所以可以用两个变量优化
        int n = nums.size();
        int dp_pre_pre = 0;//偷前0间房子最大价值为0
        int dp_pre = nums[0];//偷前1间房子最大价值是nums[0]
        if (n==0||n==1) return 0;
        if (n==2) return dp_pre;
        int max_value = 0;
        for (int i = 3;i < n+1 ;i++) {
            //dp[i] = max(dp[i-2]+nums[i],dp [i-1]);
            max_value = max(dp_pre_pre+nums[i-1],dp_pre);
            dp_pre_pre = dp_pre;
            dp_pre = max_value;
        }
        return max_value;
    }
};
int main() {
    Solution sol;
    vector<int> nums {1,2,3,1};
    int rob = sol.rob(nums);
    cout << rob << endl;
}