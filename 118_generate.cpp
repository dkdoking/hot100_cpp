//
// Created by dkdoking on 2026/6/12.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> row_1 = {1};
        vector<int> row_2 = {1,1};
        vector<int> temp;
        if (numRows == 1) {
            res.push_back(row_1);
            return res;
        }
        if (numRows == 2) {
            res.push_back(row_1);
            res.push_back(row_2);
            return res;
        }
        res.push_back(row_1);
        res.push_back(row_2);
        for (int i = 2;i < numRows; i++) {
            temp.push_back(1);
            for (int j = 1 ;j <= res[i-1].size()-1;j++) {
                temp.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            temp.push_back(1);
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};