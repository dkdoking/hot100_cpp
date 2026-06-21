//
// Created by dkdoking on 2026/6/21.
//
#include <bits//stdc++.h>
using namespace std;

/**
 *参考weiwei的解答；
 * 这道题的意思是让我们把数组里的元素按照0，1，2的大小顺序排列
 * 我们可以把nums数组分为3个区域
 * [0,zero) 这个区间全是0
 * [zero,i) 这个区间全是1
 * [i,two)这个区间全是未处理的元素
 * [two,n)这个区间全是2
 * 所以，我们需要三个指针，zero指向下一个该放0的位置，i指向正在处理的元素，two指向2开始的位置
 * i应该小于n，等于n-1是最后一次处理
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int i = 0;
        int two = n;
        while (i < two) {
            if (nums[i] == 0) {
                swap(nums,i,zero);
                i++;
                zero++;
            } else if (nums[i] == 2) {
                two--;
                swap(nums,i,two);
            } else {
                i++;
            }
        }
    }
private:
    void swap(vector<int> & nums,int i,int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};