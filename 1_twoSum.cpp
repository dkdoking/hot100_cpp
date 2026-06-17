//
// Created by dkdoking on 2026/6/4.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //使用哈希表，哈希表中没有的target-nums[i]的话，就把当前的key=nums[i],value=i存进去
        //假如说hashmap已经已经存进去了{1,0}{3,1},nums=[1,3,4],target等于5,那么第3次的时候就能
        //找到答案，把答案存在vector里面
        unordered_map<int,int> hashmap;
        vector<int> res;

        for (int i = 0;i<nums.size();i++) {
            auto ele = hashmap.find(target-nums[i]);
            //找不到的话，就存
            if (ele == hashmap.end()) {
                hashmap.insert({nums[i],i});
            } else {
                //找到了
                res.push_back(ele->second);
                res.push_back(i);
                return res;
            }
        }
    }
};
// int main() {
//     Solution sol;
//     vector<int> nums = {1,3,4};
//     vector<int> two_sum = sol.twoSum(nums,7);
//     auto sum = sol.twoSum(nums,7)
//     for (int x:two_sum) {
//         cout << x <<"_";
//     }
// }

