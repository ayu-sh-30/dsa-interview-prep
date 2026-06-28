/*
Problem: Two Sum
Date: 28 June 2026
Platform: LeetCode & NeetCode
Link: https://leetcode.com/problems/two-sum/description/
Topic: Arrays, Hash Map, Sorting
Difficulty: Easy
 
Approach:
1.Sorting: 
Sort and find for target and move two pointers accordingly, left or right 

2.HashMap:
Create a hashmap and check for element (target-nums[i]) is present in the map or not
return indexes if yes
 
3.Brute-Force: 
Use two loops and generate and check for sum of each generated and pair and return the one
that equals to the target. O(n^2)

BEST:
Time Complexity: O(n)
Space Complexity: O(n)
 
Mistake / Learning:
1. Always check for the edge cases like duplicate mapping, returning the same index {i,i}
*/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        vector<int>ans;
        
        for(int i = 0; i < nums.size(); i++){
            int search = target - nums[i];
            if(mp.count(search) && mp.at(search) != i){
                ans = {i, mp.at(search)};
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};

