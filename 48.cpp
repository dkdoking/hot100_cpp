//
// Created by dkdoking on 2026/6/30.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;
        while(true){
            //上转右
            for(int i = left; i < right;i++){
                swap(matrix,top,i,i,right);
            }
            //下转左
            for(int i = right; i > left;i--){
                swap(matrix,bottom,i,i,left);
            }
            //上下转
            for(int i = right; i > left;i--){
                swap(matrix,bottom,i,top,n-i-1);
            }
            top++;
            bottom--;
            if(top >= bottom ) break;
            left++;
            right--;
            if(left >=right ) break;

        }
    }
private:
    void swap(vector<vector<int>>& matrix, int x_1,int y_1,int x_2,int y_2){
        int temp = matrix[x_2][y_2];
        matrix[x_2][y_2] = matrix[x_1][y_1];
        matrix[x_1][y_1] = temp;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;
    sol.rotate(matrix);
}
