/*
    Time Complexity - O(n! * n)
    Space Complexity - O(n^2)
*/

class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int dupRow = row;
        int dupCol = col;
        
        //left
        for(int i=0; i<col; i++) {
            if(board[row][i]=='Q') {
                return false;
            }
        }
        
        //up-left
        while(row>=0 && col>=0) {
            if(board[row][col]=='Q') {
                return false;
            }
            
            --row, --col;
        }
        
        //down-left
        row = dupRow;
        col = dupCol;
        
        while(row<n && col>=0) {
            if(board[row][col]=='Q') {
                return false;
            }
            
            ++row, --col;
        }
        
        return true;   
    }
    
    void helper(int col, vector<vector<string>> &ans, vector<string> &board, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                helper(col+1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
         
        for(int i=0; i<n; i++) {
            board[i] = s;
        }
        
        helper(0, ans, board, n);
        return ans;
    }
};