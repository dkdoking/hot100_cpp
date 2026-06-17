//
// Created by dkdoking on 2026/6/15.
//
#include <bits/stdc++.h>
using namespace std;

/**
 * 假设判断s=leetcodeleet能否被{leet，code}切割，那递推式该如何设置？
 * dp[i]表示[0,i-1]能够被{leet,code}切割。
 * 那我们可以把[0,i-1]表示为[0,j-1]+[j,i-1]，即[0,j-1]能够被切割，且[j,i-1]包含在{leet,code}中的话，我们就认为[0,i-1]可被切割
 * 遍历j,只要有一个j满足[0,j-1]能够被切割，且[j,i-1]包含在{leet,code}中，则dp[i]=true
 * 可以看到j的取值范围为[0,i-1]
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1);
        dp[0] = true;
        for (int i = 1;i <= n;i++) {
            for (int j = 0;j <= i-1;j++) {
                if (dp[j] && contains(wordDict,s.substr(j,i-j))) { //思考把字符数组转换成hashset
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    bool wordBreak2(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(),wordDict.end());

        int n = s.size();
        vector<bool> dp(n+1);
        dp[0] = true;
        for (int i = 1;i <= n;i++) {
            for (int j = 0;j <= i-1;j++) {
                if (dp[j] && words.count(s.substr(j,i-j))) { //思考把字符数组转换成hashset
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
private:
    bool contains(vector<string> & vector, string substr) {
        for (string x : vector) {
            if (x == substr) return true;
        }
        return false;
    }
};
// int main() {
//     string s = "applepenapple";
//     vector<string> wordDict = {"apple", "pen"};
//     Solution sol;
//     bool word_break = sol.wordBreak(s,wordDict);
//     cout << word_break << endl;
//     return 0;
// }