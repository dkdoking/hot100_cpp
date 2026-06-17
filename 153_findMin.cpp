//
// Created by dkdoking on 2026/6/8.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            //右边有序
            if (nums[mid] < nums[right]) {
                //最小值就是nums[mid]
                min = std::min(min,nums[mid]);
                //最小值也可能在左边
                right = mid - 1;
            } else {
                //左边有序
                //最小值就是nums[left]
                min = std::min(min,nums[left]);
                //也有可能在右边
                left = mid + 1;
            }
        }
        return min;
    }
};