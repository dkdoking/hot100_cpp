//
// Created by dkdoking on 2026/7/13.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. 记录一下每门课的入度
        vector<int> in_degree(numCourses);
        // 2. 记录一下每们课的后续要学的课程
        unordered_map<int,vector<int>> map;
        for (vector<int> prerequisite : prerequisites){
            int course = prerequisite[0];
            int pre_course = prerequisite[1];
            in_degree[course]++;
            map[pre_course].push_back(course);
        }
        // 3. 把入度为0的放入queue里，然后取，取的时候，会影响它后面要学的课程的入度，所以后面课程的入读也要-1，如果减少到0，那么就加入
        queue<int> q;
        for (int i = 0;i < numCourses;i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        int already_learn = 0;
        // 4. 拿出入度为0的课程
        while (!q.empty()) {
            int course = q.front();
            // 这个课程后续的课程入度-1
            q.pop();
            already_learn++;
            vector<int> post_courses = map[course];
            for (int post_course : post_courses) {
                in_degree[post_course]--;
                if (in_degree[post_course] == 0) {
                    q.push(post_course);
                }
            }
        }
        return already_learn == numCourses ? true : false;
    }
};