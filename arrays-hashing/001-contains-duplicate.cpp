/*
Problem: Contains Duplicate
Date: 27 June 2026
Platform: LeetCode & NeetCode
Link: https://leetcode.com/problems/contains-duplicate/description/
Topic: Arrays, Hash Map, Sorting
Difficulty: Easy
 
Approach:
1.BruteForce: Check all the pairs and return answer accordingly
2.Sorting: Sort and check for adjacent element 
3.HashMap:
For every element mark value as true and before that 
check if it is already marked true then return TRUE as answer
Else, return false after loop
 
4.Length: Use hashset and find the length of the hashset(it contains only distinct elements)
if its equal to og len of array return false, else true


Time Complexity: O(n)
Space Complexity: O(n)
 
Mistake / Learning:
Thought of the approaches correctly but could not write the code.
Need to remember the "CHECK DUPLICATE USING HASHMAP"
*/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool twoSum(vector<int>& nums) {
        unordered_map<int, bool> seen;
 
        for(int x : nums){
            if(seen[x]) return true; //pehle hi check karlo 
            seen[x] = true; //nahi hai toh add kardo
        }
 
        return false; //yaha tak aa gye matlab sab distinct hai
    }
};
