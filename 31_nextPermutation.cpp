//
// Created by dkdoking on 2026/6/21.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //首先明确一个概念，如果这个数组是降序的，那么它肯定已经是最大的了
        //所以要去找这个数组第一次出现升序的位置
        int firstPositon = -1;
        for (int i = n-2;i >=0;i--) {
            if (nums[i]<nums[i+1]) {
                firstPositon = i;
                break;
            }
        }
        //如果一直是降序的，那么我们需要reverse
        if (firstPositon != -1) {
            //找到后，再去后面找第一个比nums[firstPositon]大的元素，然会交换
            for (int i = n-1;i >=0;i--) {
                if (nums[i] > nums[firstPositon]) {
                    swap(nums[i],nums[firstPositon]);
                    break;
                }
            }
        }

        //然后再把firstposition后面的元素升序排列
        reverse(nums.begin()+firstPositon+1,nums.end());
    }
};