/*
Problem: Valid Anagram
Date: 27 June 2026
Platform: LeetCode & NeetCode
Link: https://leetcode.com/problems/valid-anagram/description/
Topic: Arrays, Hash Map, Sorting
Difficulty: Easy
 
Approach:
1.Sorting: 
Sort and check if both the strings are equal or not 

2.HashMap:
Create a frequency hashmap of characters of s with ++ and in same hashmap decrement for 
characters of t.
Return false if count of any char is != 0, else true.
 
3.Arrays: 
Use an array of 26 characters initiallized to 0 and same above method
It makes S.C from O(N) to O(1)

BEST:
Time Complexity: O(n)
Space Complexity: O(1)
 
Mistake / Learning:
1. Starting only check for the lengths of both strings
2. Check for the upper/lower case constraint of the string
*/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char, int>freq;
       if(s.length() != t.length()) return false;
       for(char ch : s) freq[ch]++;
       for(char ch : t) freq[ch]--;

       for(auto& it : freq){
        if(it.second > 0) return false;
       }
       return true;
    }
};
/*
Array Method:

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }
        return true;
    }
};
*/