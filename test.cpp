#include <iostream>
//
// Created by dkdoking on 2026/6/5.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string>s = {"abcdefghijk","aaa"};
    unordered_set<string> set(s.begin(),s.end());
    cout << set.count("aaa");
}