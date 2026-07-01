/*
Problem: Valid Sudoku
Date: 30 June 2026
Platform: LeetCode & NeetCode
Link: https://leetcode.com/problems/product-of-array-except-self/description/
Topic: Arrays, Hash Map, Sorting
Difficulty: Medium
 
Approach:
1.Brute Force: 
Two loops and compute the product except the self element

2.Use prefix-suffix array:
Create array pref and compute product till element and push them into pref from left till rightmost
Create array suff and compute product till element and push them into suff from right till leftmost
pref[0] =1, suff[n-1] = 1
multiply both the arrays and store in final array


BEST:
Time Complexity: O(n)
Space Complexity: O(n)
 
Mistake / Learning:
1. Brute force toh soch liya tha
2. Second approach bhi soch liya tha but main final answer nahi nikal paa rha tha 
3. Need to revisit this question 
*/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n);
        vector<int>suff(n);
        pre[0] = 1;
        suff[n-1] = 1;
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] * nums[i-1];
        }
        for(int i = n-2; i >=0 ; i--){
            suff[i] = nums[i+1] * suff[i+1];
        }
        vector<int>res(n);
        for(int i = 0; i < n; i++){
            res[i] = pre[i]*suff[i];
        }
        return res;
    }
};