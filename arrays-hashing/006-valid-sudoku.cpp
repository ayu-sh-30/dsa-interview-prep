/*
Problem: Valid Sudoku
Date: 01 July 2026
Platform: LeetCode & NeetCode
Link: https://leetcode.com/problems/valid-sudoku/description/
Topic: Arrays, Hash Map, Sorting
Difficulty: Medium
 
Approach:
1.Brute Force: 
Check concerned row, concerned col and concerned matrix.
For matrx: StartRow = (i/3)*3, StartCol = (j/3)*3
T.C->O(N^3)

2.Use HashSet:
Create a SEEN set for every row, col and every matrix
access matrix by -> (i%3)*3 + (j%3)

3.Bit-Mask:
 Samajh nahi aaya baad mei dekhenge


BEST:
Time Complexity: O(n^2)
Space Complexity: O(n)
 
Mistake / Learning:
1. Brute force toh soch liya but TC bekar thi and code nahi kar paya
2. Pattern mei soch rha tha but push nhi kiya and kar sakta tha but nhi kar paya
3. Need to revisit this question and then solve it with different methods
*/
 
#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool checkCell(vector<vector<char>>& board, char target, int r, int c){
        int n = board.size(); // 9
        int rowCount = 0, colCount = 0, boxCount = 0;

        // row + column check merged into one loop (both size n)
        for(int i = 0; i < n; i++){
            if(board[r][i] == target) rowCount++;   // scanning row r
            if(board[i][c] == target) colCount++;   // scanning col c
        }

        // box check
        int boxRowStart = (r / 3) * 3;
        int boxColStart = (c / 3) * 3;
        for(int i = boxRowStart; i < boxRowStart + 3; i++){
            for(int j = boxColStart; j < boxColStart + 3; j++){
                if(board[i][j] == target) boxCount++;
            }
        }

        return rowCount <= 1 && colCount <= 1 && boxCount <= 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == '.') continue;
                if(!checkCell(board, board[i][j], i, j)) return false;
            }
        }
        return true;
    }
};