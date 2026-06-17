//
// Created by dkdoking on 2026/6/8.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
                //右边有序
            } else if (nums[mid] < nums[right]) {
                //target在右边
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }else {
                    //target在左边
                    right = mid - 1;
                }
                //左边有序
            } else {
                //target在左边
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }else {
                    //target在右边
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};