#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool solved = false;

//     set<int> presentNumbers(vector<vector<char>>& board,int r, int c){
//         pair<int,int> row, col;

//         if(r<=2){ row = {0,2}; }
//         else if(r<=5){ row = {3,5}; }
//         else { row = {6,8}; }

//         if(c<=2){ col = {0,2}; }
//         else if(c<=5){ col = {3,5}; }
//         else { col = {6,8}; }

//         set<int> s;

//         for(int rw = row.first; rw<=row.second; rw++){
//             for(int cw = col.first; cw<=col.second; cw++){
//                 if(board[rw][cw] != '.')
//                     s.insert(board[rw][cw]-'0');
//             }
//         }

//         for(int i = 0; i<9; i++){
//             if(board[i][c] != '.')
//                 s.insert(board[i][c]-'0');
//         }

//         for(int i = 0; i<9; i++){
//             if(board[r][i] != '.')
//                 s.insert(board[r][i]-'0');
//         }

//         return s;
//     }

//     void helper(vector<vector<char>>& board, vector<vector<char>>& box, int row){
//         if(solved) return;

//         int emptyCount = 0;
//         for(int i = 0 ; i<9 ; i++)
//             for(int j = 0 ; j<9 ; j++)
//                 if(board[i][j]=='.') emptyCount++;

//         if(emptyCount == 0){
//             for(int i = 0 ; i<9 ; i++)
//                 for(int j = 0 ; j<9 ; j++)
//                     box[i][j] = board[i][j];

//             solved = true;
//             return;
//         }

//         if(row >= 9) return;

//         for(int i = 0 ; i<9 ; i++){
//             if(board[row][i]=='.'){
//                 set<int> s = presentNumbers(board,row,i);

//                 for(int k = 1 ; k<= 9 ; k++){
//                     if(s.find(k) == s.end()){
//                         board[row][i] = k+'0';

//                         int c = 0;
//                         for(int l = 0 ; l<9; l++){   // ← FIXED LOOP
//                             if(board[row][l] == '.') c++;
//                         }

//                         if(c > 0)
//                             helper(board,box,row);
//                         else
//                             helper(board,box,row+1);

//                         if(solved) return;

//                         board[row][i] = '.';
//                     }
//                 }
//                 return;
//             }
//         }
//     }

// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         vector<vector<char>> box(9, vector<char>(9));
//         helper(board,box,0);

//         for(int i = 0 ; i<9 ; i++)
//             for(int j = 0 ; j<9 ; j++)
//                 board[i][j] = box[i][j];
//     }
// };


class Solution {
public:
    
    bool isValid(vector<vector<char>>& board,int r, int c, int number){
        for(int i = 0 ; i<9 ; i++){
            if(board[r][i] == number+'0') return false;
            if(board[i][c] == number+'0') return false;
            if(board[(r/3)*3 + i/3][(c/3)*3 + i%3] == number+'0') return false;
        }
        return true;
    }

    bool helper(vector<vector<char>>& board){
        for(int i = 0 ; i<9 ; i++){
            for(int j = 0 ; j<9 ; j++){
                if(board[i][j] == '.'){
                    for(int k = 1 ; k<=9 ; k++){
                        if(isValid(board,i,j,k)){
                            board[i][j] = k+'0';
                            if(helper(board) == true){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};