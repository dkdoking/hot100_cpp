//
// Created by dkdoking on 2026/6/22.
//
#include <bits/stdc++.h>
using namespace std;

/**
 * 核心就是维护一个[left,right]窗口，right0开始往右遍历
 * 1.一开始，left==0,right一直往右走，直到left-right+1=w的时候，还要再进入一次循环
 * 进入后，要先算sum，并且还要再算一次invalid_nums,算完后，如果此时left-right+1=w且invalid_nums=0，那么就可以跟新min_sum
 * 上面这些步骤做完后，在这个循环最后一步做right++
 * 2.第二次循环的时候，right-left+1>w了，这个时候代表窗口长度过长，所以我们要减少
 * 所以sum=sum-scores[left]
 * 如果scores[left]==0，同时invalid_nums--
 * 在这个循环最外侧，left--；
 */
class Solution {
public:
   vector<int> findBestWindow(int n,int w,vector<int> & scores) {
      vector<int> ans(2);
      int left=0,right=0,sum=0,invalid_nums=0;
      int min_sum = INT_MAX;
      while (right < n) {
         while (right - left + 1 <=w) {
            sum = sum + scores[right];
            if (scores[right]==0) invalid_nums++;
            if (invalid_nums==0 && right - left + 1 ==w) {
               if (sum < min_sum) {
                  min_sum = sum;
                  ans = {left,min_sum};
               }
            }
            right++;
         }
         //来到这里代表right - left + 1 >w
         sum = sum -scores[left];
         if (scores[left]==0) invalid_nums--;
         left++;
      }
      if (min_sum == INT_MAX) ans = {-1,0};
      return ans;
   }
};
int main() {
   int n = 12;
   int w = 4;
   cin >> n >> w;
   vector<int> scores(n);
   for (int i = 0;i < n;i++) {
      cin >> scores[i];
   }
   Solution sol;
   auto find_best_window = sol.findBestWindow(n,w,scores);
   for (int best_window : find_best_window) {
      cout << best_window << " ";
   }
}