package BackTracking;
import java.util.*;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet<Character> set = new HashSet<>();
        for(int i = 0 ; i < board.length ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] != '.'){
                    if(set.contains(board[i][j])) return false;
                    else set.add(board[i][j]);
                }
            }
            set.clear();
        }

        for(int i = 0 ; i < board.length ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[j][i] != '.'){
                    if(set.contains(board[j][i])) return false;
                    else set.add(board[j][i]);
                }
            }
            set.clear();
        }

        for(int i = 0 ; i <= 6 ; i+=3){
            for(int j = 0 ; j <= 6 ; j+=3){
                for(int k = i ; k <= i+2 ; k++){
                    for(int l = j ; l <= j+2 ; l++){
                        if(board[k][l] != '.'){
                            if(set.contains(board[k][l])) return false;
                            else set.add(board[k][l]);
                        }
                    }
                }
                set.clear();
            }
        }

        return true;
    }
}