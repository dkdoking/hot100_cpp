//
// Created by dkdoking on 2026/6/20.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
         int word1_len = word1.size();
         int word2_len = word2.size();
        if (word1_len==0&&word2_len==0) return 0;
        if (word1_len==0) return word2_len;
        if (word2_len==0) return word1_len;
        //dp[i][j]:word[0,i]转换到word[0,j]需要的最少次数
        vector<vector<int>> dp(word1_len,vector<int>(word2_len,0));
        if (word1[0]==word2[0]) {
            dp[0][0] = 0;
        } else {
            dp[0][0] = 1;
        }
        //计算dp[0][j] j=1...word2.len-1
        for (int j = 1;j < word2_len;j++) {
            if (word1[0]==word2[j]) {
                dp[0][j] = j;
            } else {
                dp[0][j] = dp[0][j-1] + 1;
            }
        }
        //计算dp[i][0] i=1...word1.len-1
        for (int i = 1;i < word1_len;i++) {
            if (word1[i]==word2[0]) {
                dp[i][0] = i;
            } else {
                dp[i][0] = dp[i-1][0] + 1;
            }
        }
        //计算dp[i][j]
        //分为三种情况（对应三种操作）是有三种操作，所以才分类讨论的
        //1.word1[i]==word2[j] dp[i][j]=dp[i-1][j-1]
        //2.word1[i]!=word2[j]
        //2.0 令word[0,i-1],word[0,j-1]能匹配，那么只需要替换最后一次
        //2.1 令word1[0,i-1],word2[0,j]能匹配，那么只需要删除word1[i]
        //2.2 令word1[0,i],word2[0,j-1]能匹配，那么只需要word1增加word2[j]
        for (int i = 1;i < word1_len;i++) {
            for (int j =1;j < word2_len;j++) {
                if (word1[i]==word2[j]) {
                    dp[i][j]=dp[i-1][j-1];
                } else {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        return dp[word1_len-1][word2_len-1];
    }
};