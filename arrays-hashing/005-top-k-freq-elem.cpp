/*
Problem: Top K Frequent Elements
Date: 29 June 2026
Platform: LeetCode & NeetCode
Link: https://leetcode.com/problems/top-k-frequent-elements/description/
Topic: Arrays, Hash Map, Sorting
Difficulty: Medium
 
Approach:
1.Sorting: 
Maintain freq hashmap and sort them on the basis of value using vector of pair and then 
return the top k elements

2.Min-Heap:

3.Bucket Sort:
 


BEST:
Time Complexity: O(n)--->bucket sort
Space Complexity: O(n)
 
Mistake / Learning:
1. Thought correctly also wrote correctly, but not properly
2. There are two more ways to solve this problem->Min-Heap and bucket sort
3. Need to revise and study both methods separately when we will cover those topics
*/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;
        for(int num : nums) count[num]++;

        vector<pair<int, int>>arr;
        for(auto& it : count){
            arr.push_back({it.second, it.first});
        }
        vector<int>ans;
        sort(arr.rbegin(), arr.rend());
        for(int i =0; i < k; i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};