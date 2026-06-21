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

    /**
     * 如果nums里面有0，1，2，3该怎么排序？参考chatgpt
     * @param nums 数组
     */
    void sortFourColors2(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return;
        }

        // [0 ... p0)      全是 0
        // [p0 ... p1)     全是 1
        // [p1 ... i)      全是 2
        // [i ... p3)      未处理
        // [p3 ... n - 1]  全是 3

        int p0 = 0;
        int p1 = 0;
        int i = 0;
        int p3 = n;

        while (i < p3) {
            if (nums[i] == 0) {
                swap(nums, i, p0);

                // 如果已经有 1 区，刚才换出来的 1 需要放到 p1 位置
                if (p0 < p1) {
                    swap(nums, i, p1);
                }

                p0++;
                p1++;
                i++;
            } else if (nums[i] == 1) {
                swap(nums, i, p1);
                p1++;
                i++;
            } else if (nums[i] == 2) {
                i++;
            } else {
                p3--;
                swap(nums, i, p3);
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