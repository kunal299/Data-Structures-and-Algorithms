/*
    Time Complexity - O(9 ^ (n^2))
    Space Complexity - O(1)
*/

class Solution {
public:
    bool isValid(int row, int col, char ch, vector<vector<char>> &board) {
        
        for(int i=0; i<9; i++) {
            //row-check 
            if(board[row][i]==ch) {
                return false;
            }
            
            //col-check
            if(board[i][col]==ch) {
                return false;
            }
            
            //box-check
            if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)]==ch) {
                return false;
            }
        }
        
        return true;
    }
    
    bool helper(vector<vector<char>> &board) {
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                
                if(board[i][j]=='.') {
                    
                    for(char ch='1'; ch<='9'; ch++) {
                        
                        if(isValid(i, j, ch, board)) {
                            board[i][j] = ch;
                            
                            if(helper(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                            
                        }
                        
                    }
                    
                    return false;
                    
                }
                
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool store = helper(board);
    }
};