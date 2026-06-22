//
// Created by dkdoking on 2026/6/22.
//
#include <bits/stdc++.h>
using namespace std;

/**
 * 需要两个字符串
 * string alphas 记录大写字母
 * string numbers 记录数字
 * string res 记录答案
 * 然后拼装
 * (1)for(i=0;i<min(alphas.size,number.size),i++){
 *   1. 如果nums[i]==0，那么此时只拼接0，而不拼接alphas[i]
 *   然后就可以按照正常拼接了
 *   res.pushback(nums[i])
 *   for(int i = 0;i < nums[i];i++){
 *      res.pushback(alphas[i])
 *   }
 * }
 * (2)上面那个大循环拼完后，就拼剩下的，那么字母可能剩下，数字也可能剩下
 * int max = max(alphas.size,numbers.size)
 * 1.if(alphas.size < numbers.size) 拼剩下的数子 for(int i = alphas.size;i < max;i++) res.pushback(number[i])
 * 2.if(alphas.size > numbers.size) 拼剩下的字母 for(int i = numbers.size;i < max;i++) res.pushback(alphas[i])
 */
class Solution {

private:
    bool IsAlphs(char & x) {
        set<char> alphs = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        if (alphs.find(x)!=alphs.end()) {
            //找到了
            return true;
        }
        return false;
    };
    bool IsNumbrs(char & x) {
        set<char> numbers = {'0','1','2','3','4','5','6','7','8','9'};
        if (numbers.find(x)!=numbers.end()) {
            //找到了
            return true;
        }
        return false;
    };
public:
    string formatStr(string& s) {
        string alphas ;
        string numbers ;
        string res ;
        int n = s.size();
        for (int i = 0;i < n;i++) {
            if (IsAlphs(s[i])) {
                alphas.push_back(s[i]);
            } else if (IsNumbrs(s[i])) {
                numbers.push_back(s[i]);
            }
        }
        int min_size = min(alphas.size(),numbers.size());
        /**
        *然后拼装
        (1)for(i=0;i<min(alphas.size,number.size),i++){
        1. 如果nums[i]==0，那么此时只拼接0，而不拼接alphas[i]
        然后就可以按照正常拼接了
        res.pushback(nums[i])
        for(int i = 0;i < nums[i];i++){
        res.pushback(alphas[i])
        }
        }*/
        for(int i=0;i < min_size;i++){
            if (numbers[i]==0) res.push_back('0');
            res.push_back(numbers[i]);
            for(int j = 0;j < numbers[i]-48;j++){
                res.push_back(alphas[i]);
            }
        }
        /**
        *(2)上面那个大循环拼完后，就拼剩下的，那么字母可能剩下，数字也可能剩下
        int max = max(alphas.size,numbers.size)
        1.if(alphas.size < numbers.size) 拼剩下的数子 for(int i = alphas.size;i < max;i++) res.pushback(number[i])
        2.if(alphas.size > numbers.size) 拼剩下的字母 for(int i = numbers.size;i < max;i++) res.pushback(alphas[i])
        */
        int max_size = max(alphas.size(),numbers.size());
        if(alphas.size() < numbers.size()) {
            for(int i = alphas.size();i < max_size;i++) {
                res.push_back(numbers[i]);
            }
        }
        if(alphas.size() > numbers.size()) {
            for(int i = numbers.size();i < max_size;i++) {
                res.push_back(alphas[i]);
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    string s;
    cin >> s;
    Solution sol;
    auto res = sol.formatStr(s);
    cout << res;
}

