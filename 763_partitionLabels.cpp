//
// Created by dkdoking on 2026/6/11.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        //我们假设能够包含第一个所有字母的组，也能够包含这个组里的所有字母，遇到超出范围的，我们在扩大范围
        //先计算下每个字母出现的最远位置
        int n = s.size();
        vector<int> alpha_last_index(26);
        for (int i = 0;i < 26;i++) {
            alpha_last_index[s[i]-'a'] = i;
        }
        //然后开始分组，假设刚开始字母s[0]所在的组的所有字母都可以被包含在这个组里
        //后面这个组里有字母不能被包含在这个组里，我们再更新右边界
        int end = 0;//第一组的最右边界，可更新
        int start = 0;//第一组的左边界
        vector<int> res;
        for (int i = 0;i < n;i++) {
            end = max(end,alpha_last_index[s[i]-'a']);//在第一组里，一直要更新第一组的右边界
            if (i == end) {//如果走到了右边界
                res.push_back(end - start + 1 );//计算第一个的元素个数
                start = end + 1;//更新第二组的左边界
            }
        }
        return res;
    }
};
int main() {
    string s = "ababcbacadefegdehijhklij";
    Solution sol;
    auto partition_labels = sol.partitionLabels(s);
    for (int x : partition_labels) {
        cout << x << " ";
    }
}