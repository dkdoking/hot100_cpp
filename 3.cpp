//
// Created by dkdoking on 2026/6/28.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //这段代码核心就是维护一个滑动窗口，左窗口是left，右窗口是end
        //遍历每一个s[i]，尽可能的让end为s[i]的字串长一些
        int res = 0;
        int n = s.size();
        int left = 0;
        //key：字符
        //value：这个字符上一次出现位置的下一个位置，比如aaba
        unordered_map<char,int> hashmap;
        for(int i = 0; i < n; i++){
            //如果map里能找到，那么left就要到s[i]出现的下一个地方
            if(hashmap.count(s[i])){
                left = max(hashmap[s[i]],left);
                hashmap[s[i]]=i+1;
            } else {
                //找不到，那就加入map
                hashmap[s[i]]=i+1;
            }
            res = max(res,i - left +1);
        }
        return res;
    }
};

// int main(int argc, char *argv[]) {
//     Solution sol;
//     sol.lengthOfLongestSubstring("abcabcbb");
// }
