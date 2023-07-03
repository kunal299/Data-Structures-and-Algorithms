/*
    Time Complexity - O(N) + O(M) + O(N x M x4)
    Space Complexity - O(N x M) + O(N x M)
*/

class Solution {
public:
    void dfs(int row, int col, int trow[], int tcol[], vector<vector<int>>& vis, vector<vector<char>>& board) {
        vis[row][col] = 1;

        int m = board.size();
        int n = board[0].size();

        bool flag = true;
        for(int i=0; i<4; i++) {
            int nrow = row + trow[i];
            int ncol = col + tcol[i];
            
            if(nrow>=0 && nrow<=m-1 && ncol>=0 && ncol<=n-1 && vis[nrow][ncol]==0 && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, trow, tcol, vis, board);
            } 
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));
        int trow[] = {-1, 0, 1, 0};
        int tcol[] = {0, -1, 0, 1};

        for(int j=0; j<n; j++) {
            if(!vis[0][j] && board[0][j]=='O') dfs(0, j, trow, tcol, vis, board);
            if(!vis[m-1][j] && board[m-1][j]=='O') dfs(m-1, j, trow, tcol, vis, board);
        }

        for(int i=0; i<m; i++) {
            if(!vis[i][0] && board[i][0]=='O') dfs(i, 0, trow, tcol, vis, board);
            if(!vis[i][n-1] && board[i][n-1]=='O') dfs(i, n-1, trow, tcol, vis, board);
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == 'O' && vis[i][j]==0) board[i][j] = 'X';
            }
        }
    }
};