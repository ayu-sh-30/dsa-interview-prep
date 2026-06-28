/*
Problem: Group Anagram
Date: 28 June 2026
Platform: LeetCode & NeetCode
Link: https://leetcode.com/problems/group-anagram/description/
Topic: Arrays, Hash Map, Sorting
Difficulty: Medium
 
Approach:
1.Sorting: 
Sort each strings in and store them in HashMap as keys and whatever the real elements match
to the key after sorting store them as values. O(n*logk) k->max string size

2.Frequency Array & HashMap:
Just like the valid anagram create frequency array for each string and store them in hashmap
as key and corresponding matching strings as values and return the values as answer
 


BEST:
Time Complexity: O(n*m)
Space Complexity: O(n)
 
Mistake / Learning:
1. Thought in the right direction, it was an easy solvable question
2. Must think of patterns and recognise and learn from past problems
3. Couldn't code--> implementation and logic should be improved for this
*/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    string getFrequencyString(const string& str){
        int freq[26] = {0};

        for(char c : str){
            freq[c - 'a']++;
        }

        string res = "";
        for(int i = 0; i < 26; i++){
            res += (char)('a'+i);
            res += to_string(freq[i]);
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>>mp;
        if(strs.size() == 0) return {strs};
        for(const string& str : strs){
            string freqKey = getFrequencyString(str);
            mp[freqKey].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto& it : mp){
            ans.push_back(it.second);
        }
        return ans;
        // for(int i =0; i < strs.size(); i++){
        //     string newS = strs[i];
        //     sort(newS.begin(), newS.end());
        //     mp[newS].push_back(strs[i]);
        // }
        // for(auto& it : mp){
        //     ans.push_back(it.second);
        // }
        // return ans;
    }
};

